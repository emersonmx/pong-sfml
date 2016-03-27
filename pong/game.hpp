#ifndef PONG_GAME_HPP
#define PONG_GAME_HPP

#include <memory>
#include <stack>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "pong/defs.hpp"
#include "pong/state.hpp"

namespace pong {

class Game {
    public:
        Game() {}
        virtual ~Game() {}

        sf::RenderWindow& window() { return window_; }

        State* currentState();
        void pushState(State* state);
        void popState();
        void changeState(State* state);

        void exit();
        void exit(int errorCode);
        int run();

    protected:

        virtual void create();
        virtual void destroy();

        virtual void tick();

        sf::RenderWindow window_;
        sf::Clock clock_;

    private:
        void handleEvents();

        std::stack< std::unique_ptr<State> > states_;

        int errorCode_ = 0;
        bool running_ = true;

        float timeAccumulator_ = 0.0f;
};

} /* namespace pong */
#endif /* PONG_GAME_HPP */
