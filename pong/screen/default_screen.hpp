#ifndef PONG_SCREEN_DEFAULT_SCREEN_HPP_
#define PONG_SCREEN_DEFAULT_SCREEN_HPP_

#include "mxg/default_screen.hpp"

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
#endif /* PONG_SCREEN_DEFAULT_SCREEN_HPP_ */
