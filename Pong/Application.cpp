#include "Pong/Application.hpp"

#include "Pong/Defs.hpp"
#include "Pong/States/GameState.hpp"
#include "Pong/States/GameReadyState.hpp"
#include "Pong/States/GameOverState.hpp"

using namespace sf;

namespace pong {

void Application::newGame() {
    clearStates();

    GameState* gameState = new GameState(this);
    gameState->create();

    GameReadyState* gameReadyState = new GameReadyState(this, gameState);
    gameReadyState->create();

    pushState(gameState);
    pushState(gameReadyState);
}

void Application::backToMainMenu() {
    clearStates();
}

void Application::create() {
    int flags = sf::Style::Titlebar | sf::Style::Close;
    window_.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, flags);
    window_.setVerticalSyncEnabled(true);

    assets_.loadAssets();

    newGame();
}

void Application::destroy() {
    clearStates();
    window_.close();
}

void Application::tick() {
    currentState()->beginTick();

    sf::Time time = clock_.restart();

    currentState()->processEvents();

    timeAccumulator_ += time.asSeconds();
    if (timeAccumulator_ >= GAME_TIME_STEP) {
        currentState()->update();
        timeAccumulator_ -= GAME_TIME_STEP;
    }

    window_.clear();
    currentState()->render();
    window_.display();

    currentState()->endTick();
}

} /* namespace pong */
