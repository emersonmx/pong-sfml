#ifndef MXG_DEFAULT_SCREEN_HPP_
#define MXG_DEFAULT_SCREEN_HPP_

#include "mxg/screen.hpp"

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
#endif /* MXG_DEFAULT_SCREEN_HPP_ */
