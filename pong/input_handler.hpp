#ifndef PONG_INPUT_HANDLER_HPP_
#define PONG_INPUT_HANDLER_HPP_

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

class MoveRaquetCommand: public Command {
    public:
        MoveRaquetCommand(b2Body* body, b2Vec2 velocity)
            : body_(body), velocity_(velocity) {}

        virtual void execute() { body_->SetLinearVelocity(velocity_); }

    protected:
        b2Body* body_;
        b2Vec2 velocity_;
};

class StopCommand: public MoveRaquetCommand {
    public:
        StopCommand(b2Body* body)
            : MoveRaquetCommand(body, b2Vec2(0.0f, 0.0f)) {}
};

class InputHandler {
    public:
        enum Button {
            UP, DOWN, START, BACK,
            BUTTON_SIZE
        };

        virtual ~InputHandler() {}

        virtual Command* handleInput() = 0;
};

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

class KeyboardInputHandler: public DefaultInputHandler {
    public:
        KeyboardInputHandler() { unbindAllKeys(); }

        sf::Keyboard::Key button(Button button) { return buttons_[button]; }

        void bindKey(sf::Keyboard::Key key, Button button);
        void unbindKey(Button button);
        void unbindAllKeys();

    private:
        std::array<sf::Keyboard::Key, BUTTON_SIZE> buttons_;
};

class RaquetInputHandler: public KeyboardInputHandler {
    public:
        RaquetInputHandler(b2Body* raquet) : stopCommand_(raquet) {
            unbindAllKeys();
        }

        virtual Command* handleInput();

    private:
        StopCommand stopCommand_;
};

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
#endif /* PONG_INPUT_HANDLER_HPP_ */
