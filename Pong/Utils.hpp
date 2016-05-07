#ifndef PONG_UTILS_HPP_
#define PONG_UTILS_HPP_

#include <SFML/Graphics/Transformable.hpp>
#include <Box2D/Dynamics/b2Body.h>

namespace pong {

namespace Utils {

void syncBodyToTransformable(b2Body* body, sf::Transformable& transformable);

sf::Vector2f calculateCenterOfRect(const sf::FloatRect& rect);
sf::Vector2f calculateSizeOfRect(const sf::FloatRect& rect);

} /* namespace Utils */

} /* namespace pong */
#endif /* PONG_UTILS_HPP_ */
