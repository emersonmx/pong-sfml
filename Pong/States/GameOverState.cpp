#include "Pong/States/GameOverState.hpp"

#include <SFML/Graphics/Font.hpp>

#include "Pong/Application.hpp"
#include "Pong/States/GameState.hpp"
#include "Pong/Utils.hpp"

namespace pong {

GameOverState::GameOverState(Application* app, GameState* gameState, ScoreBoard::Winner winner)
    : DefaultState::DefaultState(app), gameState_(gameState), winner_(winner) {}

void GameOverState::enter() {
    clock_.restart();
    delay_ = true;
}

void GameOverState::create() {
    sf::Font* defaultFont = app_->assets().defaultFont();
    message_.setFont(*defaultFont);
    message_.setCharacterSize(DEFAULT_FONT_SIZE * 2.666);

    if (winner_ == ScoreBoard::Winner::PLAYER) {
        message_.setString("YOU WIN!");
    } else if (winner_ == ScoreBoard::Winner::COMPUTER) {
        message_.setString("YOU LOSE");
    } else {
        message_.setString("DRAW");
    }

    sf::FloatRect bounds = message_.getLocalBounds();
    message_.setOrigin(Utils::calculateCenterOfRect(bounds));
    message_.setPosition(WINDOW_HALF_WIDTH, WINDOW_HALF_HEIGHT);
}

void GameOverState::update() {
    if (delay_) {
        sf::Time time = clock_.getElapsedTime();
        if (time.asSeconds() >= 2.0f) {
            delay_ = false;
            // show menu
        }
    }
}

void GameOverState::render(sf::RenderTarget& renderTarget) {
    gameState_->render();
    renderTarget.draw(message_);
}

} /* namespace pong */
