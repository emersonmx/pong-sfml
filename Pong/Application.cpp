#include "Pong/Application.hpp"

#include "Pong/Defs.hpp"
#include "Pong/States/GameState.hpp"

using namespace sf;

namespace pong {

void Application::create() {
    int flags = sf::Style::Titlebar | sf::Style::Close;
    window_.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, flags);
    window_.setVerticalSyncEnabled(true);

    assets_.loadAssets();

    GameState* gameState = new GameState(this);
    gameState->create();
    pushState(gameState);
}

void Application::destroy() {
    clearStates();
    window_.close();
}

void Application::tick() {
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
}

} /* namespace pong */
