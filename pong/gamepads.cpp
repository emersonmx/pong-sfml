#include "pong/gamepads.hpp"

namespace pong {

KeyboardGamepad::KeyboardGamepad() {
    clearButtons();
}

bool KeyboardGamepad::isButtonPressed(Button button) {
    return sf::Keyboard::isKeyPressed(buttonMap_[button]);
}

void KeyboardGamepad::setupButton(Button button, sf::Keyboard::Key key) {
    buttonMap_[button] = key;
}

void KeyboardGamepad::clearButtons() {
    for (int i = 0; i < BUTTON_SIZE; ++i) {
        buttonMap_[i] = sf::Keyboard::Unknown;
    }
}

} /* namespace pong */
