#ifndef PONG_PONG_HPP_
#define PONG_PONG_HPP_

#include <SFML/Graphics.hpp>

#include "MXG/Game.hpp"

namespace pong {

class Pong: public mxg::Game {
    public:
        Pong() {}
        virtual ~Pong() {}

        sf::RenderWindow& window() { return window_; }

    protected:

        virtual void create();
        virtual void destroy();

        virtual void tick();

        sf::RenderWindow window_;
        sf::Clock clock_;

    private:
        float timeAccumulator_ = 0.0f;
};

} /* namespace pong */
#endif /* PONG_PONG_HPP_ */
