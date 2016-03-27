#include "pong/input_handler.hpp"

#include "pong/defs.hpp"

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

void DefaultInputHandler::bindCommand(Button button, Command* command) {
    commands_[button].reset(command);
}

void DefaultInputHandler::unbindCommand(Button button) {
    commands_[button].reset(new NullCommand());
}

void DefaultInputHandler::unbindAllCommands() {
    for (std::size_t i = 0; i < commands_.size(); i++) {
        commands_[i].reset(new NullCommand());
    }
}

Command* RaquetInputHandler::handleInput() {
    if (sf::Keyboard::isKeyPressed(button(UP))) {
        return command(Button::UP);
    } else if (sf::Keyboard::isKeyPressed(button(DOWN))) {
        return command(Button::DOWN);
    }

    return &stopCommand_;
}

ComputerPlayerInputHandler::ComputerPlayerInputHandler(b2Body* raquet,
        b2Body* ball, float xMaxDistance, float yMaxDistance)
    : raquet_(raquet), ball_(ball),  xMaxDistance_(xMaxDistance),
      yMaxDistance_(yMaxDistance), stopCommand_(raquet) {}

Command* ComputerPlayerInputHandler::handleInput() {
    b2Vec2 ballPosition = ball_->GetPosition();
    b2Vec2 raquetPosition = raquet_->GetPosition();

    if (abs(raquetPosition.x - ballPosition.x) > xMaxDistance_) {
        float windowHalfHeight = WINDOW_HALF_HEIGHT / PIXELS_PER_METER;

        if (raquetPosition.y + yMaxDistance_ < windowHalfHeight) {
            return command(Button::UP);
        } else if (raquetPosition.y - yMaxDistance_ > windowHalfHeight) {
            return command(Button::DOWN);
        }

        return &stopCommand_;
    }

    if (raquetPosition.y + yMaxDistance_ < ballPosition.y) {
        return command(Button::UP);
    } else if (raquetPosition.y - yMaxDistance_ > ballPosition.y) {
        return command(Button::DOWN);
    }

    return &stopCommand_;
}

} /* namespace pong */
