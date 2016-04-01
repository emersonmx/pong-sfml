#include "pong/input_handler/ComputerPlayerInputHandler.hpp"

#include "pong/Defs.hpp"

namespace pong {

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
