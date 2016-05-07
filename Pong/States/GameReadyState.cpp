#include "Pong/States/GameReadyState.hpp"

#include "Pong/Application.hpp"
#include "Pong/States/GameState.hpp"

namespace pong {

GameReadyState::GameReadyState(Application* app, GameState* gameState)
    : DefaultState::DefaultState(app), gameState_(gameState) {}

void GameReadyState::create() {
    setupWaitMessage();
    setupStartMessage();
}

void GameReadyState::update() {
    if (ready_) {
        sf::Time time = clock_.getElapsedTime();
        if (time.asSeconds() > 1.0f) {
            gameState_->reset();
            app_->popState();
        }
    }
}

void GameReadyState::processEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Up ||
                event.key.code == sf::Keyboard::Down) {
            clock_.restart();
            ready_ = true;
        }
    }

    DefaultState::processEvent(event);
}

void GameReadyState::render(sf::RenderTarget& renderTarget) {
    gameState_->render();

    if (!ready_) {
        renderTarget.draw(waitMessage_);
    } else {
        renderTarget.draw(startMessage_);
    }
}

void GameReadyState::setupWaitMessage() {
    sf::Font* font = app_->assets().defaultFont();
    waitMessage_.setFont(*font);
    waitMessage_.setCharacterSize(DEFAULT_FONT_SIZE);
    waitMessage_.setString("PRESS ANY MOVEMENT BUTTON WHEN READY");
    waitMessage_.setPosition(WINDOW_HALF_WIDTH, WINDOW_HALF_HEIGHT / 2.0f);

    sf::FloatRect bounds = waitMessage_.getLocalBounds();
    sf::Vector2f center(bounds.width + bounds.left, bounds.height + bounds.top);
    waitMessage_.setOrigin(center / 2.0f);
}

void GameReadyState:: setupStartMessage() {
    sf::Font* font = app_->assets().defaultFont();
    startMessage_.setFont(*font);
    startMessage_.setCharacterSize(DEFAULT_FONT_SIZE * 2.666);
    startMessage_.setString("GAME START");
    startMessage_.setPosition(WINDOW_HALF_WIDTH, WINDOW_HALF_HEIGHT / 2.0f);

    sf::FloatRect bounds = startMessage_.getLocalBounds();
    sf::Vector2f center(bounds.width + bounds.left, bounds.height + bounds.top);
    startMessage_.setOrigin(center / 2.0f);
}

} /* namespace pong */
