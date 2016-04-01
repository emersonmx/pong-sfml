#ifndef PONG_INPUT_HANDLER_STOPCOMMAND_HPP_
#define PONG_INPUT_HANDLER_STOPCOMMAND_HPP_

#include "Pong/InputHandler/Command/MoveRaquetCommand.hpp"

namespace pong {

class StopCommand: public MoveRaquetCommand {
    public:
        StopCommand(b2Body* body)
            : MoveRaquetCommand(body, b2Vec2(0.0f, 0.0f)) {}
};

} /* namespace pong */
#endif /* PONG_INPUT_HANDLER_STOPCOMMAND_HPP_ */
