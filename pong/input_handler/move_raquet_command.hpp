#ifndef PONG_INPUT_HANDLER_MOVE_RAQUET_COMMAND_HPP_
#define PONG_INPUT_HANDLER_MOVE_RAQUET_COMMAND_HPP_

#include "Box2D/Box2D.h"

#include "pong/input_handler/command.hpp"

namespace pong {

class MoveRaquetCommand: public Command {
    public:
        MoveRaquetCommand(b2Body* body, b2Vec2 velocity)
            : body_(body), velocity_(velocity) {}

        virtual void execute() { body_->SetLinearVelocity(velocity_); }

    protected:
        b2Body* body_;
        b2Vec2 velocity_;
};

} /* namespace pong */
#endif /* PONG_INPUT_HANDLER_MOVE_RAQUET_COMMAND_HPP_ */
