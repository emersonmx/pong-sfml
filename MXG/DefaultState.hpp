#ifndef MXG_DEFAULTSTATE_HPP_
#define MXG_DEFAULTSTATE_HPP_

#include "MXG/State.hpp"

namespace mxg {

class DefaultState: public State {
    public:
        virtual void enter() {}
        virtual void exit() {}

        virtual void processEvent(const sf::Event& event) {}
        virtual void update() {}
        virtual void render(sf::RenderTarget& renderTarget) {}
};

} /* namespace mxg */
#endif /* MXG_DEFAULTSTATE_HPP_ */
