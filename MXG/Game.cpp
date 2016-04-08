#include "MXG/Game.hpp"

#include <iostream>

namespace mxg {

Game::Game() {
    pushState(new DefaultState());
}

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
    if (states_.size() > 1) {
        State* state = currentState();
        state->exit();
        states_.pop();
    }
}

void Game::clearStates() {
    while (states_.size() > 1) {
        states_.pop();
    }
}

void Game::changeState(State* state) {
    popState();
    pushState(state);
}

} /* namespace mxg */
