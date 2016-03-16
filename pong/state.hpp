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

        virtual void Enter() = 0;
        virtual void Exit() = 0;

        virtual void Update(sf::Time& time) = 0;
};

class DefaultState: public State {
    public:
        virtual void Enter() {}
        virtual void Exit() {}

        virtual void Update(sf::Time& time) {}
};

} /* namespace pong */
#endif /* PONG_STATE_HPP */
