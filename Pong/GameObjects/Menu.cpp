#include "Pong/GameObjects/Menu.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "Pong/Defs.hpp"
#include "Pong/Utils.hpp"

namespace pong {

Menu::Menu(const Options& options, const sf::Font& font,
           unsigned int characterSize, int spacing)
    : options_(options), font_(font), characterSize_(characterSize),
      spacing_(spacing) {}

void Menu::setPosition(sf::Vector2f position) {
    transformable_.setPosition(position);
}

void Menu::setSelect(int index) {
    int size = options_.size() - 1;
    if (index < 0) {
        selected_ = 0;
    } else if (index > size) {
        selected_ = options_.size() - 1;
    } else {
        selected_ = index;
    }
}

void Menu::create() {
    int optionsSize = options_.size();
    if (optionsSize <= 0) {
        return;
    }

    sf::Vector2f position;
    sf::Vector2f size;
    sf::Vector2f center;
    sf::FloatRect bounds;

    for (auto& option : options_) {
        sf::Text text(option, font_, characterSize_);
        updateTextCenter(text);
        textArray_.emplace_back(text);
    }

    sf::Text& first = textArray_.at(0);
    bounds = first.getLocalBounds();
    size = Utils::calculateSizeOfRect(bounds);
    float textHeight = bounds.height;
    float totalHeight = textHeight * optionsSize + (spacing_ * (optionsSize - 1));

    for (int i = 0; i < optionsSize; i++) {
        sf::Text& text = textArray_.at(i);
        position = text.getPosition();
        position.y = textHeight * i + (spacing_ * i);
        text.setPosition(position);
    }

    transformable_.setOrigin(0, totalHeight / 2.0f);
    updateTexts();
}

void Menu::next() {
    setSelect(selected_ + 1);
    updateTexts();
}

void Menu::previous() {
    setSelect(selected_ - 1);
    updateTexts();
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (!visible) {
        return;
    }

    states.transform *= transformable_.getTransform();

    for (auto& text : textArray_) {
        target.draw(text, states);
    }
}

void Menu::updateTexts() {
    int size = options_.size();
    for (int i = 0; i < size; i++) {
        sf::Text& text = textArray_.at(i);
        if (selected_ == i) {
            text.setString("> " + options_.at(i) + " <");
        } else {
            text.setString(options_.at(i));
        }
        updateTextCenter(text);
    }
}

void Menu::updateTextCenter(sf::Text& text) {
    sf::FloatRect bounds = text.getLocalBounds();
    sf::Vector2f center = Utils::calculateCenterOfRect(bounds);
    center.y = bounds.top;
    text.setOrigin(center);
}

} /* namespace pong */
