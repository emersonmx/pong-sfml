#ifndef PONG_INPUT_HANDLER_COMPUTER_PLAYER_INPUT_HANDLER_HPP_
#define PONG_INPUT_HANDLER_COMPUTER_PLAYER_INPUT_HANDLER_HPP_

#include <Box2D/Box2D.h>

#include "pong/input_handler/default_input_handler.hpp"
#include "pong/input_handler/stop_command.hpp"

namespace pong {

class ComputerPlayerInputHandler: public DefaultInputHandler {
    public:
        ComputerPlayerInputHandler(b2Body* raquet, b2Body* ball,
                                   float xMaxDistance_, float yMaxDistance);

        virtual Command* handleInput();

    private:
        b2Body* raquet_;
        b2Body* ball_;
        float xMaxDistance_;
        float yMaxDistance_;

        StopCommand stopCommand_;
};

} /* namespace pong */
#endif /* PONG_INPUT_HANDLER_COMPUTER_PLAYER_INPUT_HANDLER_HPP_ */
