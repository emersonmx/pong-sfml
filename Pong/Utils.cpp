#include "Pong/Utils.hpp"

#include <SFML/Graphics/Rect.hpp>

#include <Pong/Defs.hpp>

namespace pong {

namespace Utils {

void syncBodyToTransformable(b2Body* body, sf::Transformable& transformable) {
    b2Vec2 position = body->GetPosition();
    float angle = body->GetAngle();
    transformable.setPosition(position.x * PIXELS_PER_METER,
                              position.y * PIXELS_PER_METER);
    transformable.setRotation(angle * 180.0f / M_PI);
}

sf::Vector2f calculateCenterOfRect(sf::FloatRect rect) {
    return sf::Vector2f(rect.left + rect.width / 2.0f,
                        rect.top + rect.height / 2.0f);
}

} /* namespace Utils */

} /* namespace pong */
