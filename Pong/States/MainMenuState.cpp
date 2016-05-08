#include "Pong/States/MainMenuState.hpp"

#include "Pong/Application.hpp"
#include "Pong/Defs.hpp"
#include "Pong/Utils.hpp"

namespace pong {

void MainMenuState::create() {
    sf::Texture& logoTexture = app_->assets().logoTexture();
    logo_.setTexture(logoTexture);
    logo_.setOrigin(Utils::calculateCenterOfRect(logo_.getLocalBounds()));
    logo_.setPosition(WINDOW_HALF_WIDTH, WINDOW_HALF_HEIGHT / 2.0f);

    sf::Font* defaultFont = app_->assets().defaultFont();

    menu_.reset(new Menu({"START GAME", "QUIT GAME"},
                         *defaultFont, DEFAULT_FONT_SIZE, DEFAULT_FONT_SIZE));
    menu_->setPosition(sf::Vector2f(WINDOW_HALF_WIDTH, WINDOW_HALF_HEIGHT * 1.5));
    menu_->create();
}

void MainMenuState::endTick() {
    switch (selected_) {
        case MenuOption::START_GAME:
            app_->newGame();
            break;
        case MenuOption::QUIT_GAME:
            app_->exit();
            break;
    }
}

void MainMenuState::processEvent(const sf::Event& event) {
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

void MainMenuState::render(sf::RenderTarget& renderTarget) {
    renderTarget.draw(logo_);
    renderTarget.draw(*menu_);
}

} /* namespace pong */
