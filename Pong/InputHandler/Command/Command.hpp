#ifndef PONG_INPUTHANDLER_COMMAND_COMMAND_HPP_
#define PONG_INPUTHANDLER_COMMAND_COMMAND_HPP_

namespace pong {

class Command {
    public:
        virtual ~Command() {}

        virtual void execute() = 0;
};

} /* namespace pong */
#endif /* PONG_INPUTHANDLER_COMMAND_COMMAND_HPP_ */
