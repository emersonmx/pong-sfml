#include "Pong/State/GameReadyState.hpp"

#include "Pong/Application.hpp"
#include "Pong/State/GameState.hpp"

namespace pong {

GameReadyState::GameReadyState(Application* game, GameState* gameState)
    : DefaultState::DefaultState(game), gameState_(gameState) {}

void GameReadyState::create() {
    setupTexts();
}

void GameReadyState::processEvent(const sf::Event& event) {
    DefaultState::processEvent(event);

    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Space) {
            app_->popState();
        }
    }
}

void GameReadyState::render(sf::RenderTarget& renderTarget) {
    gameState_->render();
    renderTarget.draw(message_);
    if (leftReady_) {
        renderTarget.draw(leftReadyText_);
    }
    if (rightReady_) {
        renderTarget.draw(rightReadyText_);
    }
}

void GameReadyState::setupTexts() {
    setupMessage();
    setupLeftReady();
    setupRightReady();
}

void GameReadyState::setupMessage() {
    message_.setString("PRESS ANY MOVEMENT BUTTON WHEN READY");
    message_.setPosition(WINDOW_HALF_WIDTH, WINDOW_HALF_HEIGHT / 2.0f);
    applyDefaultStyle(message_);
}

void GameReadyState::setupLeftReady() {
    leftReadyText_.setString("READY!");
    leftReadyText_.setPosition(WINDOW_HALF_WIDTH / 2.0f, WINDOW_HALF_HEIGHT);
    applyDefaultStyle(leftReadyText_);
}

void GameReadyState::setupRightReady() {
    rightReadyText_.setString("READY!");
    rightReadyText_.setPosition(WINDOW_HALF_WIDTH * 1.5f, WINDOW_HALF_HEIGHT);
    applyDefaultStyle(rightReadyText_);
}

void GameReadyState::applyDefaultStyle(sf::Text& text) {
    sf::Font* font = app_->assets().defaultFont();
    text.setFont(*font);
    text.setCharacterSize(24);
    sf::FloatRect bounds = text.getLocalBounds();
    sf::Vector2f center(bounds.width + bounds.left, bounds.height + bounds.top);
    center *= 0.5f;
    text.setOrigin(center);
}

} /* namespace pong */
