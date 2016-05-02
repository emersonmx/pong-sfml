#ifndef PONG_STATE_GAMESTATE_HPP_
#define PONG_STATE_GAMESTATE_HPP_

#include <memory>

#include "Pong/States/DefaultState.hpp"
#include "Pong/Defs.hpp"
#include "Pong/GameWorld.hpp"

#include "Pong/GameObjects/Ball.hpp"
#include "Pong/GameObjects/PlayerRacket.hpp"

#include "MXG/SFMLDebugDraw.hpp"

namespace pong {

class GameState: public DefaultState, public GameWorld::ScoreListener {
    public:
        using DefaultState::DefaultState;

        virtual void create();
        virtual void destroy();

        virtual void update();

        using DefaultState::render;

        virtual void enter();
        virtual void exit();

        virtual void leftScored(GameWorld& gameWorld);
        virtual void rightScored(GameWorld& gameWorld);

    protected:
        void setupGameWorld();
        void setupGameObjects();

        virtual void processEvent(const sf::Event& event);
        virtual void render(sf::RenderTarget& renderTarget);

        GameWorld gameWorld_;

        std::unique_ptr<Ball> ball_;
        std::unique_ptr<Racket> leftRacket_;
        std::unique_ptr<Racket> rightRacket_;

        std::unique_ptr<mxg::SFMLDebugDraw> debugDraw_;
};

} /* namespace pong */
#endif /* PONG_STATE_GAMESTATE_HPP_ */
