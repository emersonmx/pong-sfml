#include "Pong/Pong.hpp"

#include <iostream>

#include "Pong/Defs.hpp"
#include "Pong/Screen/GameScreen.hpp"

using namespace sf;

namespace pong {

void Pong::create() {
    window_.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    sf::View view = window_.getDefaultView();
    view.setSize(WINDOW_WIDTH, -WINDOW_HEIGHT);
    window_.setView(view);

    GameScreen* gameScreen = new GameScreen(this);
    changeScreen(gameScreen);
}

void Pong::destroy() {
    window_.close();
}

void Pong::tick() {
    sf::Time time = clock_.restart();
    sf::Event event;

    while (window_.pollEvent(event)) {
        currentScreen()->processEvent(event);
    }

    timeAccumulator_ += time.asSeconds();
    if (timeAccumulator_ >= GAME_TIME_STEP) {
        currentScreen()->update();
        timeAccumulator_ -= GAME_TIME_STEP;
    }

    window_.clear();
    currentScreen()->render(window_);
    window_.display();
}

} /* namespace pong */
