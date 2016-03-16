#ifndef PONG_APPLICATION_HPP
#define PONG_APPLICATION_HPP

#include <memory>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "pong/defs.hpp"
#include "pong/state.hpp"

namespace pong {

class Application {
    public:
        Application() {}
        virtual ~Application() {}

        sf::RenderWindow& window() { return window_; }

        void changeState(State* state);

        void exit();
        void exit(int errorCode);
        int run();

    protected:

        virtual void create();
        virtual void destroy();

        virtual void update();

        sf::RenderWindow window_;
        sf::Event event_;
        sf::Clock clock_;

    private:
        void createWindow();

        void handleEvents();

        std::unique_ptr<State> currentState_ = make_unique<DefaultState>();

        int errorCode_ = 0;
        bool running_ = true;
};

} /* namespace pong */
#endif /* PONG_APPLICATION_HPP */
