#include "Pong/States/GameMenuState.hpp"

#include "Pong/Application.hpp"
#include "Pong/States/GameState.hpp"

namespace pong {

GameMenuState::GameMenuState(Application* app, GameState* gameState)
    : DefaultState(app), gameState_(gameState) {}

void GameMenuState::create() {
    sf::Font* defaultFont = app_->assets().defaultFont();

    menu_.reset(new Menu({"RESUME GAME", "RESTART GAME", "BACK TO MAIN MENU"},
                         *defaultFont, DEFAULT_FONT_SIZE, DEFAULT_FONT_SIZE));
    menu_->setPosition(sf::Vector2f(WINDOW_HALF_WIDTH, WINDOW_HALF_HEIGHT));
    menu_->create();
}

void GameMenuState::endTick() {
    switch (selected_) {
        case MenuOption::RESUME:
            app_->popState();
            break;
        case MenuOption::RESTART:
            app_->newGame();
            break;
        case MenuOption::BACK_TO_MAIN_MENU:
            app_->backToMainMenu();
            break;
    }
}

void GameMenuState::processEvent(const sf::Event& event) {
    DefaultState::processEvent(event);

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            menu_->previous();
        } else if (event.key.code == sf::Keyboard::Down) {
            menu_->next();
        } else if (event.key.code == sf::Keyboard::Return) {
            selected_ = menu_->selected();
        }
    }
}

void GameMenuState::render(sf::RenderTarget& renderTarget) {
    gameState_->render();

    renderTarget.draw(*menu_);
}

} /* namespace pong */
