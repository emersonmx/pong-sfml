#include "Pong/GameObjects/ScoreBoard.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

#include "Pong/Defs.hpp"

namespace pong {

void ScoreBoard::create() {
    leftScoreText_.setFont(*font_);
    leftScoreText_.setCharacterSize(DEFAULT_FONT_SIZE * 2.25f);
    updateLeftScoreText();

    rightScoreText_.setFont(*font_);
    rightScoreText_.setCharacterSize(DEFAULT_FONT_SIZE * 2.25f);
    updateRightScoreText();

    visible = false;
}

void ScoreBoard::update() {
    if (visible) {
        sf::Time elapsedTime = clock_.getElapsedTime();
        if (elapsedTime.asSeconds() > 2.0f) {
            hide();
        }
    }
}

void ScoreBoard::show() {
    clock_.restart();
    visible = true;
}

void ScoreBoard::hide() {
    visible = false;
}

void ScoreBoard::leftScored(GameWorld& gameWorld) {
    leftScore_++;
    updateLeftScoreText();
    show();
}

void ScoreBoard::rightScored(GameWorld& gameWorld) {
    rightScore_++;
    updateRightScoreText();
    show();
}

void ScoreBoard::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (!visible) {
        return;
    }

    target.draw(leftScoreText_, states);
    target.draw(rightScoreText_, states);
}

void ScoreBoard::updateLeftScoreText() {
    leftScoreText_.setString(std::to_string(leftScore_));

    sf::Vector2f position(WINDOW_HALF_WIDTH, 32);
    sf::FloatRect bounds = leftScoreText_.getLocalBounds();
    position.x -= 25.0f;
    position.y -= bounds.top;
    leftScoreText_.setOrigin(sf::Vector2f(bounds.left + bounds.width, 0.0f));
    leftScoreText_.setPosition(position);
}

void ScoreBoard::updateRightScoreText() {
    rightScoreText_.setString(std::to_string(rightScore_));

    sf::Vector2f position(WINDOW_HALF_WIDTH, 32);
    sf::FloatRect bounds = rightScoreText_.getLocalBounds();
    position.x += 25.0f;
    position.y -= bounds.top;
    rightScoreText_.setOrigin(sf::Vector2f(bounds.left, 0.0f));
    rightScoreText_.setPosition(position);
}

} /* namespace pong */
