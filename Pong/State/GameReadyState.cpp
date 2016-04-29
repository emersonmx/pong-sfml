#include "Pong/State/GameReadyState.hpp"

#include "Pong/Pong.hpp"
#include "Pong/State/GameState.hpp"

namespace pong {

GameReadyState::GameReadyState(Pong* pong, GameState* gameState)
    : DefaultState::DefaultState(pong), gameState_(gameState) {}

void GameReadyState::create() {
    setupTexts();
}

void GameReadyState::processEvent(const sf::Event& event) {
    DefaultState::processEvent(event);

    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Space) {
            game_->popState();
        }
    }
}

void GameReadyState::render(sf::RenderTarget& renderTarget) {
    gameState_->render();
    renderTarget.draw(message_);
    if (showLeftReady_) {
        renderTarget.draw(leftReady_);
    }
    if (showRightReady_) {
        renderTarget.draw(rightReady_);
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
    leftReady_.setString("READY!");
    leftReady_.setPosition(WINDOW_HALF_WIDTH / 2.0f, WINDOW_HALF_HEIGHT);
    applyDefaultStyle(leftReady_);
}

void GameReadyState::setupRightReady() {
    rightReady_.setString("READY!");
    rightReady_.setPosition(WINDOW_HALF_WIDTH * 1.5f, WINDOW_HALF_HEIGHT);
    applyDefaultStyle(rightReady_);
}

void GameReadyState::applyDefaultStyle(sf::Text& text) {
    sf::Font* font = game_->assets().defaultFont();
    text.setFont(*font);
    text.setCharacterSize(24);
    sf::FloatRect bounds = text.getLocalBounds();
    sf::Vector2f center(bounds.width + bounds.left, bounds.height + bounds.top);
    center *= 0.5f;
    text.setOrigin(center);
}

} /* namespace pong */
