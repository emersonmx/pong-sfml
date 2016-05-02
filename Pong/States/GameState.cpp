#include "Pong/States/GameState.hpp"

#include <iostream>

#include "Pong/Pong.hpp"

namespace pong {

void GameState::create() {
}

void GameState::update() {
}

void GameState::enter() {
}

void GameState::exit() {
}

void GameState::processEvent(const sf::Event& event) {
    DefaultState::processEvent(event);
}

void GameState::render(sf::RenderTarget& renderTarget) {
}

} /* namespace pong */
