#ifndef PONG_INPUT_HANDLER_COMMAND_HPP_
#define PONG_INPUT_HANDLER_COMMAND_HPP_

namespace pong {

class Command {
    public:
        virtual ~Command() {}

        virtual void execute() = 0;
};

} /* namespace pong */
#endif /* PONG_INPUT_HANDLER_COMMAND_HPP_ */
