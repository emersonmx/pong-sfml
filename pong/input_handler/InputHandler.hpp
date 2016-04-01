#ifndef PONG_INPUT_HANDLER_INPUTHANDLER_HPP_
#define PONG_INPUT_HANDLER_INPUTHANDLER_HPP_

#include "pong/input_handler/command/Command.hpp"

namespace pong {

class InputHandler {
    public:
        enum Button {
            UP, DOWN, START, BACK,
            BUTTON_SIZE
        };

        virtual ~InputHandler() {}

        virtual Command* handleInput() = 0;
};

} /* namespace pong */
#endif /* PONG_INPUT_HANDLER_INPUTHANDLER_HPP_ */
