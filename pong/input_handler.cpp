#include "pong/input_handler.hpp"

#include "pong/defs.hpp"

namespace pong {
void DefaultInputHandler::bindCommand(Button button, Command* command) {
    commands_[button].reset(command);
}

void DefaultInputHandler::unbindCommand(Button button) {
    commands_[button].reset(new NullCommand());
}

void DefaultInputHandler::unbindAll() {
    for (std::size_t i = 0; i < commands_.size(); i++) {
        commands_[i].reset(new NullCommand());
    }
}

Command* RaquetInputHandler::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        return command(Button::UP);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        return command(Button::DOWN);
    }

    return DefaultInputHandler::handleInput();
}

} /* namespace pong */
