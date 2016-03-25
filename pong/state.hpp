#ifndef PONG_STATE_HPP
#define PONG_STATE_HPP

#include <memory>

#include <SFML/Graphics.hpp>

#include "pong/game_world.hpp"
#include "pong/gamepads.hpp"
#include "SFMLDebugDraw.h"

namespace pong {

class Application;

class State {
    public:
        virtual ~State() {}

        virtual void enter(Application* application) = 0;
        virtual void exit() = 0;

        virtual void update() = 0;
        virtual void render(sf::RenderTarget& renderTarget) = 0;
};

class DefaultState: public State {
    public:
        virtual void enter(Application* application) {}
        virtual void exit() {}

        virtual void update() {}
        virtual void render(sf::RenderTarget& renderTarget) {}
};

class GameState: public DefaultState, GameWorld::ScoreListener {
    public:
        virtual void enter(Application* application);
        virtual void exit();

        virtual void update();
        virtual void render(sf::RenderTarget& renderTarget);

        virtual void leftScored(GameWorld& gameWorld);
        virtual void rightScored(GameWorld& gameWorld);

    private:
        void setupGameWorld();
        void setupDebugDraw();
        void setupGamepads();

        void handleGamepads();

        Application* application_;
        GameWorld gameWorld_;

        std::unique_ptr<Gamepad> firstPlayer_;
        std::unique_ptr<Gamepad> secondPlayer_;

        std::unique_ptr<SFMLDebugDraw> debugDraw_;
};

} /* namespace pong */
#endif /* PONG_STATE_HPP */
