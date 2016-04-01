#ifndef PONG_INPUT_HANDLER_NULLCOMMAND_HPP_
#define PONG_INPUT_HANDLER_NULLCOMMAND_HPP_

#include "pong/input_handler/Command.hpp"

namespace pong {

class NullCommand: public Command {
    public:
        virtual void execute() {}
};

} /* namespace pong */
#endif /* PONG_INPUT_HANDLER_NULLCOMMAND_HPP_ */
