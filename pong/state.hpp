#ifndef PONG_STATE_HPP
#define PONG_STATE_HPP

#include <SFML/Graphics.hpp>

#include "pong/game_world.hpp"

using namespace std;

namespace pong {

class Application;

class State {
    public:
        virtual ~State() {}

        virtual void enter() = 0;
        virtual void exit() = 0;

        virtual void update() = 0;
        virtual void render(sf::RenderTarget& renderTarget) = 0;
};

class DefaultState: public State {
    public:
        virtual void enter() {}
        virtual void exit() {}

        virtual void update() {}
        virtual void render(sf::RenderTarget& renderTarget) {}
};

class BaseState: public DefaultState {
    public:
        virtual void setup(Application* application) {}
};

class GameState: public BaseState {
    public:
        virtual void setup(Application* application);

        virtual void enter();
        virtual void exit();

        virtual void update();
        virtual void render(sf::RenderTarget& renderTarget);

    private:
        GameWorld gameWorld_;
        sf::RectangleShape box_;
        sf::RectangleShape ground_;
};

} /* namespace pong */
#endif /* PONG_STATE_HPP */
