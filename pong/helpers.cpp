#include "pong/helpers.hpp"

#include "pong/defs.hpp"

namespace pong {

void syncBodyToTransformable(b2Body* body, sf::Transformable& transformable) {
    b2Vec2 position = body->GetPosition();
    float angle = body->GetAngle();
    transformable.setPosition(position.x * PIXELS_PER_METER,
                          position.y * PIXELS_PER_METER);
    transformable.setRotation(angle);
}

sf::RectangleShape createRectangleShape(float width, float height) {
    sf::RectangleShape shape;
    shape.setOrigin(width / 2, height / 2);
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::White);
    return shape;
}

} /* namespace pong */
