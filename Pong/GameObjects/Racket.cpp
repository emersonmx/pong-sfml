#include "Pong/GameObjects/Racket.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "Pong/Defs.hpp"
#include "Pong/Utils.hpp"

namespace pong {

void Racket::create() {
    shape_.setSize(sf::Vector2f(RACKET_WIDTH, RACKET_HEIGHT));
    shape_.setOrigin(shape_.getSize() / 2.0f);
}

void Racket::update() {
    Utils::syncBodyToTransformable(body_, shape_);

    handleInput();
}

void Racket::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape_, states);
}

} /* namespace pong */