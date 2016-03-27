#include "pong/state.hpp"

#include <Box2D/Box2D.h>

#include "pong/game.hpp"
#include "pong/defs.hpp"

namespace pong {

sf::RectangleShape createRectangleShape(float width, float height) {
    sf::RectangleShape shape;
    shape.setOrigin(width / 2, height / 2);
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::White);
    return shape;
}

void syncBodyToTransformable(b2Body* body, sf::Transformable& transformable) {
    b2Vec2 position = body->GetPosition();
    float angle = body->GetAngle();
    transformable.setPosition(position.x * PIXELS_PER_METER,
                              position.y * PIXELS_PER_METER);
    transformable.setRotation(angle);
}

void DefaultState::enter(Game* game) {
    game_ = game;
}

void DefaultState::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::Closed) {
        game_->exit();
    }
}

} /* namespace pong */
