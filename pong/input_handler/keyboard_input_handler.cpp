#include "pong/input_handler/keyboard_input_handler.hpp"

namespace pong {

void KeyboardInputHandler::bindKey(sf::Keyboard::Key key, Button button) {
    buttons_[button] = key;
}

void KeyboardInputHandler::unbindKey(Button button) {
    buttons_[button] = sf::Keyboard::Unknown;
}

void KeyboardInputHandler::unbindAllKeys() {
    for (size_t button = 0; button < buttons_.size(); button++) {
        buttons_[button] = sf::Keyboard::Unknown;
    }
}

} /* namespace pong */
