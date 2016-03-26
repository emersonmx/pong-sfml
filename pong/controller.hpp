#ifndef PONG_CONTROLLER_HPP
#define PONG_CONTROLLER_HPP

#include <array>

#include <SFML/Window.hpp>

namespace pong {

class Controller {
    public:
        enum Button {
            NONE,
            UP, RIGHT, DOWN, LEFT, A, B, START, SELECT,
            BUTTON_SIZE
        };

        virtual ~Controller() {}

        virtual bool isButtonPressed(Button button) = 0;
        virtual bool isConnected() { return true; }
        virtual void setupButton(Button button, sf::Keyboard::Key key) = 0;
        virtual void clearButtons() = 0;
};

class KeyboardController: public Controller {
    public:
        KeyboardController();

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

        std::array<sf::Keyboard::Key, Controller::BUTTON_SIZE> buttonMap_;
};

} /* namespace pong */
#endif /* PONG_CONTROLLER_HPP */
