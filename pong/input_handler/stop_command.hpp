#ifndef PONG_INPUT_HANDLER_STOP_COMMAND_HPP_
#define PONG_INPUT_HANDLER_STOP_COMMAND_HPP_

#include "pong/input_handler/move_raquet_command.hpp"

namespace pong {

class StopCommand: public MoveRaquetCommand {
    public:
        StopCommand(b2Body* body)
            : MoveRaquetCommand(body, b2Vec2(0.0f, 0.0f)) {}
};

} /* namespace pong */
#endif /* PONG_INPUT_HANDLER_STOP_COMMAND_HPP_ */
