#ifndef PONG_INPUTHANDLER_COMMAND_MOVERAQUETCOMMAND_HPP_
#define PONG_INPUTHANDLER_COMMAND_MOVERAQUETCOMMAND_HPP_

#include <Box2D/Box2D.h>

#include "Pong/InputHandler/Command/Command.hpp"

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
#endif /* PONG_INPUTHANDLER_COMMAND_MOVERAQUETCOMMAND_HPP_ */
