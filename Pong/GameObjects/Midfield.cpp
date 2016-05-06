#include "Pong/GameObjects/Midfield.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "Pong/Defs.hpp"

namespace pong {

void Midfield::create() {
    shape_.setSize(sf::Vector2f(2, WINDOW_HEIGHT));
    shape_.setOrigin(shape_.getSize() / 2.0f);
    shape_.setPosition(WINDOW_HALF_WIDTH, WINDOW_HALF_HEIGHT);
}

void Midfield::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (!visible) {
        return;
    }

    target.draw(shape_, states);
}

} /* namespace pong */
