#ifndef PONG_INPUTHANDLER_INPUTHANDLER_HPP_
#define PONG_INPUTHANDLER_INPUTHANDLER_HPP_

#include "Pong/InputHandler/Command/Command.hpp"

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
#endif /* PONG_INPUTHANDLER_INPUTHANDLER_HPP_ */
