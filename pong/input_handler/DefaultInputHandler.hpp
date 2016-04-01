#ifndef PONG_INPUT_HANDLER_DEFAULTINPUTHANDLER_HPP_
#define PONG_INPUT_HANDLER_DEFAULTINPUTHANDLER_HPP_

#include <memory>

#include "pong/input_handler/InputHandler.hpp"
#include "pong/input_handler/NullCommand.hpp"

namespace pong {

class DefaultInputHandler: public InputHandler {
    public:
        DefaultInputHandler() { unbindAllCommands(); }

        Command* command(Button button) { return commands_[button].get(); }

        void bindCommand(Button button, Command* command);
        void unbindCommand(Button button);
        void unbindAllCommands();

        virtual Command* handleInput() { return &nullCommand_; }

    private:
        NullCommand nullCommand_;

        std::array< std::unique_ptr<Command>, BUTTON_SIZE > commands_;
};

} /* namespace pong */
#endif /* PONG_INPUT_HANDLER_DEFAULTINPUTHANDLER_HPP_ */
