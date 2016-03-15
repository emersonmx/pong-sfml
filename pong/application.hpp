#ifndef PONG_APPLICATION_HPP
#define PONG_APPLICATION_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "pong/defs.hpp"
#include "pong/state.hpp"

namespace pong {

class Application {
    public:
        Application() {}
        virtual ~Application() {}

        void changeState(State* state);
        State* getCurrentState() { return currentState; }

        void exit();
        void exit(int errorCode);
        int run();

    protected:

        virtual void create();
        virtual void destroy();

        virtual void update();
        virtual void handleInput();
        virtual void processLogic();
        virtual void draw();

        sf::RenderWindow window;
        sf::Event event;
        sf::Clock clock;

    private:
        void createWindow();

        State* currentState = nullptr;

        int errorCode = 0;
        bool running = true;
};

} /* namespace pong */
#endif /* PONG_APPLICATION_HPP */
