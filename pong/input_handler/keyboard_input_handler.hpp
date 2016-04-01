#ifndef PONG_INPUT_HANDLER_KEYBOARD_INPUT_HANDLER_HPP_
#define PONG_INPUT_HANDLER_KEYBOARD_INPUT_HANDLER_HPP_

#include <SFML/Window.hpp>

#include "pong/input_handler/default_input_handler.hpp"

namespace pong {

class KeyboardInputHandler: public DefaultInputHandler {
    public:
        KeyboardInputHandler() { unbindAllKeys(); }

        sf::Keyboard::Key button(Button button) { return buttons_[button]; }

        void bindKey(sf::Keyboard::Key key, Button button);
        void unbindKey(Button button);
        void unbindAllKeys();

    private:
        std::array<sf::Keyboard::Key, BUTTON_SIZE> buttons_;
};

} /* namespace pong */
#endif /* PONG_INPUT_HANDLER_KEYBOARD_INPUT_HANDLER_HPP_ */
