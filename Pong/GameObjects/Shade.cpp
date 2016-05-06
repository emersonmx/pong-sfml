#include "Pong/GameObjects/Shade.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "Pong/Defs.hpp"

namespace pong {

sf::Vector2f Shade::position() {
    return shape_.getPosition();
}

void Shade::setPosition(const sf::Vector2f& position) {
    shape_.setPosition(position);
}

sf::Vector2f Shade::size() {
    return shape_.getSize();
}

void Shade::setSize(const sf::Vector2f& size) {
    shape_.setSize(size);
}

sf::Color Shade::fillColor() {
    return shape_.getFillColor();
}

void Shade::setFillColor(const sf::Color& color) {
    shape_.setFillColor(color);
}

void Shade::show() {
    visible_ = true;
}

void Shade::hide() {
    visible_ = false;
}

void Shade::create() {
    sf::Vector2f size(WINDOW_WIDTH, WINDOW_HEIGHT);
    setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    setFillColor(sf::Color(0, 0, 0, 128));
    shape_.setOrigin(size / 2.0f);
    setPosition(sf::Vector2f(WINDOW_HALF_WIDTH, WINDOW_HALF_HEIGHT));

    show();
}

void Shade::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (visible_) {
        target.draw(shape_, states);
    }
}

} /* namespace pong */
