#ifndef PONG_HELPERS_HPP
#define PONG_HELPERS_HPP

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

namespace pong {

sf::RectangleShape createRectangleShape(float width, float height);
void syncBodyToTransformable(b2Body* body, sf::Transformable& transformable);

} /* namespace pong */
#endif /* PONG_HELPERS_HPP */
