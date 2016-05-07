#include "Pong/States/GameOverState.hpp"

#include <SFML/Graphics/Font.hpp>

#include "Pong/Application.hpp"
#include "Pong/States/GameState.hpp"
#include "Pong/Defs.hpp"
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

    menu_.reset(new Menu({"RESTART GAME", "BACK TO MAIN MENU"},
                         *defaultFont, DEFAULT_FONT_SIZE, DEFAULT_FONT_SIZE));
    menu_->setPosition(sf::Vector2f(WINDOW_HALF_WIDTH, WINDOW_HALF_HEIGHT));
    menu_->create();
}

void GameOverState::update() {
    if (delay_) {
        sf::Time time = clock_.getElapsedTime();
        if (time.asSeconds() >= 2.0f) {
            delay_ = false;
        }
    }
}

void GameOverState::endTick() {
    if (selected_ == MenuOption::RESTART) {
        app_->newGame();
    } else if (selected_ == MenuOption::BACK_TO_MAIN_MENU) {
        app_->changeToMainMenu();
    }
    selected_ = MenuOption::NONE;
}

void GameOverState::processEvent(const sf::Event& event) {
    DefaultState::processEvent(event);

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            if (delay_) {
                delay_ = false;
            } else {
                menu_->previous();
            }
        } else if (event.key.code == sf::Keyboard::Down) {
            if (delay_) {
                delay_ = false;
            } else {
                menu_->next();
            }
        } else if (event.key.code == sf::Keyboard::Return) {
            if (delay_) {
                delay_ = false;
            } else {
                selected_ = menu_->selected();
            }
        }
    }
}

void GameOverState::render(sf::RenderTarget& renderTarget) {
    gameState_->render();

    if (delay_) {
        renderTarget.draw(message_);
    } else {
        renderTarget.draw(*menu_);
    }
}

} /* namespace pong */
