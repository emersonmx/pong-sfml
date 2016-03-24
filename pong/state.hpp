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

class GameState: public DefaultState {
    public:
        virtual void enter(Application* application);
        virtual void exit();

        virtual void update();
        virtual void render(sf::RenderTarget& renderTarget);

    private:
        void setupGameWorld();
        void setupGamepads();

        void handleGamepads();

        Application* application_;
        GameWorld gameWorld_;

        std::unique_ptr<Gamepad> firstPlayer_;
        std::unique_ptr<Gamepad> secondPlayer_;

#ifndef NDEBUG
        std::unique_ptr<SFMLDebugDraw> debugDraw_;
#endif /* ifndef NDEBUG */
};

} /* namespace pong */
#endif /* PONG_STATE_HPP */
