#include "Pong/UI/ScoreBoard.hpp"

#include <iostream>

#include "Pong/Defs.hpp"

namespace pong {

void ScoreBoard::create(const sf::Font* font) {
    background_ = createBackground();
    leftScoreText_ = createLeftScoreText(font);
    rightScoreText_ = createRightScoreText(font);

    scale(1, -1);
}

void ScoreBoard::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();

    target.draw(background_, states);
    target.draw(leftScoreText_, states);
    //target.draw(rightScoreText_, states);
}

void ScoreBoard::leftScored(GameWorld& gameWorld) {
    leftScore_++;
    updateScores();
}

void ScoreBoard::rightScored(GameWorld& gameWorld) {
    rightScore_++;
    updateScores();
}

sf::RectangleShape ScoreBoard::createBackground() {
    sf::Vector2f size(150, DEFAULT_FONT_SIZE + 20);
    sf::Vector2f origin = size / 2.0f;

    sf::RectangleShape background(size);
    background.setFillColor(sf::Color::Black);
    background.setOutlineColor(sf::Color::White);
    background.setOutlineThickness(-2.0f);

    background.setOrigin(origin);
    background.setPosition(sf::Vector2f(0, 0));

    return background;
}

sf::Text ScoreBoard::createLeftScoreText(const sf::Font* font) {
    sf::Vector2f position = background_.getPosition();

    sf::Text text("99", *font, DEFAULT_FONT_SIZE);
    sf::FloatRect bounds = text.getLocalBounds();
    sf::Vector2f origin(bounds.width - bounds.left, bounds.height - bounds.top);
    origin /= 2.0f;
    text.setOrigin(origin);
    text.setPosition(position);
    return text;
}

sf::Text ScoreBoard::createRightScoreText(const sf::Font* font) {
    sf::Text text("99", *font, DEFAULT_FONT_SIZE);
    sf::FloatRect bounds = text.getLocalBounds();
    sf::Vector2f origin(bounds.width - bounds.left, bounds.height - bounds.top);
    text.setOrigin(origin);
    return text;
}

void ScoreBoard::updateScores() {
    leftScoreText_.setString("1");
    rightScoreText_.setString("2");
}

} /* namespace pong */
