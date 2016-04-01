#ifndef PONG_INPUT_HANDLER_COMPUTERPLAYERINPUTHANDLER_HPP_
#define PONG_INPUT_HANDLER_COMPUTERPLAYERINPUTHANDLER_HPP_

#include <Box2D/Box2D.h>

#include "pong/input_handler/DefaultInputHandler.hpp"
#include "pong/input_handler/command/StopCommand.hpp"

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
#endif /* PONG_INPUT_HANDLER_COMPUTERPLAYERINPUTHANDLER_HPP_ */
