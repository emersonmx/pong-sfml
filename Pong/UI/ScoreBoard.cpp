#include "Pong/UI/ScoreBoard.hpp"

#include "Pong/Defs.hpp"

namespace pong {

void ScoreBoard::create(const sf::Font* font) {
    leftScoreText_ = createLeftScoreText(font);
    rightScoreText_ = createRightScoreText(font);
    updateLeftScoreText();
    updateRightScoreText();
    hide();
}

void ScoreBoard::update() {
    if (visibility_) {
        sf::Time elapsedTime = clock_.getElapsedTime();
        if (elapsedTime.asSeconds() > 2.0f) {
            hide();
            clock_.restart();
        }
    }
}

void ScoreBoard::leftScored(GameWorld& gameWorld) {
    leftScore_++;
    updateLeftScoreText();
    clock_.restart();
    show();
}

void ScoreBoard::rightScored(GameWorld& gameWorld) {
    rightScore_++;
    updateRightScoreText();
    clock_.restart();
    show();
}

sf::Text ScoreBoard::createLeftScoreText(const sf::Font* font) {
    std::string score = std::to_string(leftScore_);
    return sf::Text(score, *font, DEFAULT_FONT_SIZE);
}

sf::Text ScoreBoard::createRightScoreText(const sf::Font* font) {
    std::string score = std::to_string(rightScore_);
    return sf::Text(score, *font, DEFAULT_FONT_SIZE);
}

void ScoreBoard::updateLeftScoreText() {
    leftScoreText_.setString(std::to_string(leftScore_));

    sf::Vector2f position;
    sf::FloatRect bounds = leftScoreText_.getLocalBounds();
    position.x -= 25.0f;
    position.y -= bounds.top;
    leftScoreText_.setOrigin(sf::Vector2f(bounds.left + bounds.width, 0.0f));
    leftScoreText_.setPosition(position);
}

void ScoreBoard::updateRightScoreText() {
    rightScoreText_.setString(std::to_string(rightScore_));

    sf::Vector2f position;
    sf::FloatRect bounds = rightScoreText_.getLocalBounds();
    position.x += 25.0f;
    position.y -= bounds.top;
    rightScoreText_.setOrigin(sf::Vector2f(bounds.left, 0.0f));
    rightScoreText_.setPosition(position);
}

void ScoreBoard::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (visibility_) {
        states.transform *= getTransform();

        target.draw(leftScoreText_, states);
        target.draw(rightScoreText_, states);
    }
}

} /* namespace pong */
