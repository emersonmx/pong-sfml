#ifndef PONG_INPUT_HANDLER_HPP
#define PONG_INPUT_HANDLER_HPP

#include <memory>
#include <array>

#include <SFML/Window.hpp>
#include <Box2D/Box2D.h>

namespace pong {

class Command {
    public:
        virtual ~Command() {}

        virtual void execute() = 0;
};

class NullCommand: public Command {
    public:
        virtual void execute() {}
};

class InputHandler {
    public:
        enum Button {
            NONE,
            UP, DOWN, START, BACK,
            BUTTON_SIZE
        };

        virtual ~InputHandler() {}

        virtual Command* handleInput() = 0;
};

class DefaultInputHandler: public InputHandler {
    public:
        Command* command(Button button) { return commands_[button].get(); }

        void bindCommand(Button button, Command* command);
        void unbindCommand(Button button);
        void unbindAll();

        virtual Command* handleInput() { return &nullCommand_; }


    private:
        NullCommand nullCommand_;

        std::array< std::unique_ptr<Command>, BUTTON_SIZE > commands_;
};

class RaquetInputHandler: public DefaultInputHandler {
    public:
        RaquetInputHandler(b2Body* raquet) : raquet_(raquet) {}

        virtual Command* handleInput();

    private:
        b2Body* raquet_;
};

} /* namespace pong */
#endif /* PONG_INPUT_HANDLER_HPP */
