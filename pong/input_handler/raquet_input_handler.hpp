#ifndef PONG_INPUT_HANDLER_RAQUET_INPUT_HANDLER_HPP_
#define PONG_INPUT_HANDLER_RAQUET_INPUT_HANDLER_HPP_

#include "pong/input_handler/keyboard_input_handler.hpp"
#include "pong/input_handler/stop_command.hpp"

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
#endif /* PONG_INPUT_HANDLER_RAQUET_INPUT_HANDLER_HPP_ */
