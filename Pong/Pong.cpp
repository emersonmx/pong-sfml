#include "Pong/Pong.hpp"

#include "Pong/Defs.hpp"
#include "Pong/State/GameState.hpp"
#include "Pong/State/GameReadyState.hpp"

using namespace sf;

namespace pong {

void Pong::create() {
    int flags = sf::Style::Titlebar | sf::Style::Close;
    window_.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, flags);

    assets_.loadAssets();

    GameState* gameState = new GameState(this);
    gameState->create();
    GameReadyState* gameReadyState = new GameReadyState(this, gameState);
    gameReadyState->create();
    changeState(gameReadyState);
}

void Pong::destroy() {
    window_.close();
}

void Pong::tick() {
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
