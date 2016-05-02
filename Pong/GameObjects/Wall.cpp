#include "Pong/GameObjects/Wall.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "Pong/Defs.hpp"
#include "Pong/Utils.hpp"

namespace pong {

void Wall::create() {
    shape_.setSize(sf::Vector2f(WALL_WIDTH, WALL_HEIGHT));
    shape_.setOrigin(shape_.getSize() / 2.0f);

    Utils::syncBodyToTransformable(body_, shape_);
}

void Wall::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape_, states);
}

} /* namespace pong */
