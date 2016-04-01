#ifndef PONG_INPUTHANDLER_COMMAND_NULLCOMMAND_HPP_
#define PONG_INPUTHANDLER_COMMAND_NULLCOMMAND_HPP_

#include "Pong/InputHandler/Command/Command.hpp"

namespace pong {

class NullCommand: public Command {
    public:
        virtual void execute() {}
};

} /* namespace pong */
#endif /* PONG_INPUTHANDLER_COMMAND_NULLCOMMAND_HPP_ */
