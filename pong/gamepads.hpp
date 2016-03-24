#ifndef PONG_GAMEPADS_HPP
#define PONG_GAMEPADS_HPP

#include <SFML/Window.hpp>

namespace pong {

class Gamepad {
    public:
        enum Button {
            NONE,
            UP, RIGHT, DOWN, LEFT, A, B, START, SELECT,
            BUTTON_SIZE
        };

        virtual ~Gamepad() {}

        virtual bool isButtonPressed(Button button) = 0;
        virtual bool isConnected() { return true; }
        virtual void setupButton(Button button, sf::Keyboard::Key key) = 0;
        virtual void clearButtons() = 0;
};

class KeyboardGamepad: public Gamepad {
    public:
        KeyboardGamepad();

        virtual bool isButtonPressed(Button button);

        virtual void setupButton(Button button, sf::Keyboard::Key key);
        virtual void clearButtons();

    private:
        struct ButtonHash {
            template <typename T>
            std::size_t operator()(T t) const {
                return static_cast<std::size_t>(t);
            }
        };

        sf::Keyboard::Key buttonMap_[Gamepad::BUTTON_SIZE];
};

} /* namespace pong */
#endif /* PONG_GAMEPADS_HPP */
