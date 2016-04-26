#include "Pong/Pong.hpp"

#include "Pong/Defs.hpp"
#include "Pong/State/GameState.hpp"

using namespace sf;

namespace pong {

void Pong::create() {
    window_.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);

    assets_.loadAssets();

    GameState* gameState = new GameState(this);
    gameState->create();
    changeState(gameState);
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
