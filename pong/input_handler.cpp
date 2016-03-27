#include "pong/input_handler.hpp"

#include "pong/defs.hpp"

namespace pong {

KeyboardInputHandler::KeyboardInputHandler() {
    unbindAllCommands();
}

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

void KeyboardInputHandler::bindCommand(Button button, Command* command) {
    commands_[button].reset(command);
}

void KeyboardInputHandler::unbindCommand(Button button) {
    commands_[button].reset(new NullCommand());
}

void KeyboardInputHandler::unbindAllCommands() {
    for (std::size_t i = 0; i < commands_.size(); i++) {
        commands_[i].reset(new NullCommand());
    }
}
RaquetInputHandler::RaquetInputHandler(b2Body* raquet)
        : stopCommand_(raquet) {
    unbindAllKeys();
}

Command* RaquetInputHandler::handleInput() {
    if (sf::Keyboard::isKeyPressed(button(UP))) {
        return command(Button::UP);
    } else if (sf::Keyboard::isKeyPressed(button(DOWN))) {
        return command(Button::DOWN);
    }

    return &stopCommand_;
}

} /* namespace pong */
