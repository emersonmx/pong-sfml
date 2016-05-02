#include "Pong/Pong.hpp"

#include "Pong/Defs.hpp"
#include "Pong/States/GameState.hpp"

using namespace sf;

namespace pong {

void Pong::create() {
    int flags = sf::Style::Titlebar | sf::Style::Close;
    window_.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, flags);
    window_.setVerticalSyncEnabled(true);

    assets_.loadAssets();

    pushState(new GameState(this));
}

void Pong::destroy() {
    clearStates();
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
