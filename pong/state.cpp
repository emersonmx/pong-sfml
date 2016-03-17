#include "pong/state.hpp"

#include "pong/application.hpp"

namespace pong {

void BaseState::setup(Application* application) {
    application_ = application;
}

void GameState::enter() {
}

void GameState::exit() {
}

void GameState::update(sf::Time& time) {
}

void GameState::render(sf::RenderWindow& window) {
}

} /* namespace pong */
