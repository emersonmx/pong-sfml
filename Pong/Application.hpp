#ifndef PONG_APPLICATION_HPP_
#define PONG_APPLICATION_HPP_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

#include "MXG/Game.hpp"

#include "Pong/Assets.hpp"

namespace pong {

class Application: public mxg::Game {
    public:
        Application() {}
        virtual ~Application() {}

        sf::RenderWindow& window() { return window_; }
        Assets& assets() { return assets_; }

    protected:
        void create() override;
        void destroy() override;

        void tick() override;

        sf::RenderWindow window_;
        sf::Clock clock_;

        Assets assets_;

    private:
        float timeAccumulator_ = 0.0f;
};

} /* namespace pong */
#endif /* PONG_APPLICATION_HPP_ */
