#ifndef PONG_INPUT_HANDLER_RAQUETINPUTHANDLER_HPP_
#define PONG_INPUT_HANDLER_RAQUETINPUTHANDLER_HPP_

#include "pong/input_handler/KeyboardInputHandler.hpp"
#include "pong/input_handler/StopCommand.hpp"

namespace pong {

class RaquetInputHandler: public KeyboardInputHandler {
    public:
        RaquetInputHandler(b2Body* raquet) : stopCommand_(raquet) {
            unbindAllKeys();
        }

        virtual Command* handleInput();

    private:
        StopCommand stopCommand_;
};

} /* namespace pong */
#endif /* PONG_INPUT_HANDLER_RAQUETINPUTHANDLER_HPP_ */
