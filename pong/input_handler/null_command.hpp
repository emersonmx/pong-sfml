#ifndef PONG_INPUT_HANDLER_NULL_COMMAND_HPP_
#define PONG_INPUT_HANDLER_NULL_COMMAND_HPP_

#include "pong/input_handler/command.hpp"

namespace pong {

class NullCommand: public Command {
    public:
        virtual void execute() {}
};

} /* namespace pong */
#endif /* PONG_INPUT_HANDLER_NULL_COMMAND_HPP_ */
