#ifndef PONG_STATE_HPP
#define PONG_STATE_HPP

#include <iostream>

#include <SFML/Graphics.hpp>

using namespace std;

namespace pong {

class Application;

class State {
    public:
        virtual ~State() {}

        virtual void enter() = 0;
        virtual void exit() = 0;

        virtual void update(sf::Time& time) = 0;
        virtual void render(sf::RenderWindow& window) = 0;
};

class DefaultState: public State {
    public:
        virtual void enter() {}
        virtual void exit() {}

        virtual void update(sf::Time& time) {}
        virtual void render(sf::RenderWindow& window) {}
};

class BaseState: public DefaultState {
    public:
        void setup(Application* application);

        virtual void update(sf::Time& time) {}
        virtual void render(sf::RenderWindow& window) {}

    protected:
        Application* application_;
};

class GameState: public BaseState {
    public:
        virtual void enter();
        virtual void exit();

        virtual void update(sf::Time& time);
        virtual void render(sf::RenderWindow& window);
};

} /* namespace pong */
#endif /* PONG_STATE_HPP */
