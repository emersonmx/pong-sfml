#include "pong/input_handler/default_input_handler.hpp"

namespace pong {

void DefaultInputHandler::bindCommand(Button button, Command* command) {
    commands_[button].reset(command);
}

void DefaultInputHandler::unbindCommand(Button button) {
    commands_[button].reset(new NullCommand());
}

void DefaultInputHandler::unbindAllCommands() {
    for (std::size_t i = 0; i < commands_.size(); i++) {
        commands_[i].reset(new NullCommand());
    }
}

} /* namespace pong */
