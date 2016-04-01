#ifndef MXG_DEFAULTSCREEN_HPP_
#define MXG_DEFAULTSCREEN_HPP_

#include "mxg/Screen.hpp"

namespace mxg {

class DefaultScreen: public Screen {
    public:
        virtual void enter() {}
        virtual void exit() {}

        virtual void processEvent(const sf::Event& event) {}
        virtual void update() {}
        virtual void render(sf::RenderTarget& renderTarget) {}
};

} /* namespace mxg */
#endif /* MXG_DEFAULTSCREEN_HPP_ */
