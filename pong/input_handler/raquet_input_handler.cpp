#include "pong/input_handler/raquet_input_handler.hpp"

namespace pong {

Command* RaquetInputHandler::handleInput() {
    if (sf::Keyboard::isKeyPressed(button(UP))) {
        return command(Button::UP);
    } else if (sf::Keyboard::isKeyPressed(button(DOWN))) {
        return command(Button::DOWN);
    }

    return &stopCommand_;
}

} /* namespace pong */
