#ifndef PONG_STATE_HPP
#define PONG_STATE_HPP

#include <memory>

#include <SFML/Graphics.hpp>

#include "pong/game_world.hpp"
#include "pong/controller.hpp"
#include "SFMLDebugDraw.h"

namespace pong {

class Game;

class State {
    public:
        virtual ~State() {}

        virtual void enter(Game* game) = 0;
        virtual void exit() = 0;

        virtual void update() = 0;
        virtual void render(sf::RenderTarget& renderTarget) = 0;
};

class DefaultState: public State {
    public:
        virtual void enter(Game* game) {}
        virtual void exit() {}

        virtual void update() {}
        virtual void render(sf::RenderTarget& renderTarget) {}
};

class GameState: public DefaultState, public GameWorld::ScoreListener {
    public:
        virtual void enter(Game* game);
        virtual void exit();

        virtual void update();
        virtual void render(sf::RenderTarget& renderTarget);

        virtual void leftScored(GameWorld& gameWorld);
        virtual void rightScored(GameWorld& gameWorld);

    private:
        void setupGameWorld();
        void setupDebugDraw();
        void setupControllers();

        void handleControllers();

        Game* game_;
        GameWorld gameWorld_;

        std::unique_ptr<Controller> firstPlayer_;
        std::unique_ptr<Controller> secondPlayer_;

        std::unique_ptr<SFMLDebugDraw> debugDraw_;
};

} /* namespace pong */
#endif /* PONG_STATE_HPP */
