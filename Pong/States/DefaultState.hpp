#ifndef PONG_STATE_DEFAULTSTATE_HPP_
#define PONG_STATE_DEFAULTSTATE_HPP_

#include "MXG/DefaultState.hpp"

namespace pong {

class Pong;

class DefaultState: public mxg::DefaultState {
    public:
        DefaultState(Pong* game) : game_(game) {}

        virtual void processEvents();
        virtual void render();

    protected:
        virtual void processEvent(const sf::Event& event);
        virtual void render(sf::RenderTarget& renderTarget) {}

        Pong* game_;
};

} /* namespace pong */
#endif /* PONG_STATE_DEFAULTSTATE_HPP_ */
