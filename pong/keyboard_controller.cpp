#include "pong/controller.hpp"

namespace pong {

KeyboardController::KeyboardController() {
    clearButtons();
}

bool KeyboardController::isButtonPressed(Button button) {
    return sf::Keyboard::isKeyPressed(buttonMap_[button]);
}

void KeyboardController::setupButton(Button button, sf::Keyboard::Key key) {
    buttonMap_[button] = key;
}

void KeyboardController::clearButtons() {
    for (int i = 0; i < BUTTON_SIZE; ++i) {
        buttonMap_[i] = sf::Keyboard::Unknown;
    }
}

} /* namespace pong */
