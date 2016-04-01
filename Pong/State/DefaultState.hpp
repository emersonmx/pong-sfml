#ifndef PONG_STATE_DEFAULTSTATE_HPP_
#define PONG_STATE_DEFAULTSTATE_HPP_

#include "MXG/DefaultState.hpp"

namespace pong {

class Pong;

class DefaultState: public mxg::DefaultState {
    public:
        DefaultState(Pong* game) : game_(game) {}

        virtual void processEvent(const sf::Event& event);

    protected:
        Pong* game_;
};

} /* namespace pong */
#endif /* PONG_STATE_DEFAULTSTATE_HPP_ */
