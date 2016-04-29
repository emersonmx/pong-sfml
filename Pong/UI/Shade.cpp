#include "Pong/UI/Shade.hpp"

namespace pong {

void Shade::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (visible_) {
        states.transform *= getTransform();
        target.draw(shade_, states);
    }
}

} /* namespace pong */
