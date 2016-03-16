#ifndef PONG_STATE_HPP
#define PONG_STATE_HPP

#include <iostream>

#include <SFML/System/Time.hpp>

using namespace std;

namespace pong {

class Application;

class State {
    public:
        virtual ~State() {}

        virtual void enter() = 0;
        virtual void exit() = 0;

        virtual void update(sf::Time& time) = 0;
};

class DefaultState: public State {
    public:
        virtual void enter() {}
        virtual void exit() {}

        virtual void update(sf::Time& time) {}
};

} /* namespace pong */
#endif /* PONG_STATE_HPP */
