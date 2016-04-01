#ifndef PONG_INPUTHANDLER_KEYBOARDINPUTHANDLER_HPP_
#define PONG_INPUTHANDLER_KEYBOARDINPUTHANDLER_HPP_

#include <SFML/Window.hpp>

#include "Pong/InputHandler/DefaultInputHandler.hpp"

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
#endif /* PONG_INPUTHANDLER_KEYBOARDINPUTHANDLER_HPP_ */
