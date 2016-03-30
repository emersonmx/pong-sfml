#include "pong/game.hpp"

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

namespace pong {

void Game::pushState(State* state) {
    if (state == nullptr) {
        std::cout << "Ignoring null state." << std::endl;
        return;
    }

    state->enter(this);
    states_.emplace(state);
}

State* Game::currentState() {
    return states_.top().get();
}

void Game::popState() {
    State* state = currentState();
    state->exit();
    states_.pop();

    if (states_.empty()) {
        pushState(new DefaultState());
    }
}

void Game::changeState(State* state) {
    if (!states_.empty()) {
        popState();
    }
    pushState(state);
}

void Game::exit() {
    exit(0);
}

void Game::exit(int errorCode) {
    errorCode_ = errorCode;
    running_ = false;
}

int Game::run() {
    create();

    clock_.restart();
    while (running_) {
        tick();
    }

    destroy();
    return errorCode_;
}

void Game::create() {
    window_.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    sf::View view = window_.getDefaultView();
    view.setSize(WINDOW_WIDTH, -WINDOW_HEIGHT);
    window_.setView(view);

    GameState* gameState = new GameState();
    changeState(gameState);
}

void Game::destroy() {
    window_.close();
}

void Game::tick() {
    sf::Time time = clock_.restart();
    sf::Event event;

    while (window_.pollEvent(event)) {
        currentState()->processEvent(event);
    }

    timeAccumulator_ += time.asSeconds();
    if (timeAccumulator_ >= GAME_TIME_STEP) {
        currentState()->update();
        timeAccumulator_ -= GAME_TIME_STEP;
    }

    window_.clear();
    currentState()->render(window_);
    window_.display();
}

} /* namespace pong */
