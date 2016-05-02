#include "Pong/GameObjects/PlayerRacket.hpp"

#include <SFML/Window/Keyboard.hpp>

#include "Pong/Defs.hpp"

namespace pong {

void PlayerRacket::handlerInput() {
    b2Vec2 velocity(0.0f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        velocity.Set(0.0f, -RACKET_BASE_SPEED);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        velocity.Set(0.0f, RACKET_BASE_SPEED);
    }

    body_->SetLinearVelocity(velocity);
}

} /* namespace pong */
