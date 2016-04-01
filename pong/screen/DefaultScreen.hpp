#ifndef PONG_SCREEN_DEFAULTSCREEN_HPP_
#define PONG_SCREEN_DEFAULTSCREEN_HPP_

#include "mxg/DefaultScreen.hpp"

namespace pong {

class Pong;

class DefaultScreen: public mxg::DefaultScreen {
    public:
        DefaultScreen(Pong* game) : game_(game) {}

        virtual void processEvent(const sf::Event& event);

    protected:
        Pong* game_;
};

} /* namespace pong */
#endif /* PONG_SCREEN_DEFAULTSCREEN_HPP_ */
