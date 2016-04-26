#ifndef PONG_STATE_DEFAULTSTATE_HPP_
#define PONG_STATE_DEFAULTSTATE_HPP_

#include "MXG/DefaultState.hpp"

namespace pong {

class Pong;

class DefaultState: public mxg::DefaultState {
    public:
        DefaultState(Pong* game) : game_(game) {}

        virtual void processEvents();

    protected:
        virtual void processEvent(const sf::Event& event);

        Pong* game_;
};

} /* namespace pong */
#endif /* PONG_STATE_DEFAULTSTATE_HPP_ */
