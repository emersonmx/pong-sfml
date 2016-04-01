#include "MXG/Game.hpp"

#include <iostream>

namespace mxg {

void Game::pushState(State* state) {
    if (state == nullptr) {
        std::cout << "Ignoring null state." << std::endl;
        return;
    }

    state->enter();
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

void Game::clearStates() {
    while (!states_.empty()) {
        states_.pop();
    }

    pushState(new DefaultState());
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

    while (running_) {
        tick();
    }

    destroy();
    return errorCode_;
}

} /* namespace mxg */
