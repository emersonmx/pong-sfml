#ifndef PONG_STATE_GAMESTATE_HPP_
#define PONG_STATE_GAMESTATE_HPP_

#include "Pong/States/DefaultState.hpp"
#include "Pong/Defs.hpp"
#include "Pong/GameWorld.hpp"

#include "MXG/SFMLDebugDraw.hpp"

namespace pong {

class GameState: public DefaultState {
    public:
        using DefaultState::DefaultState;

        virtual void create();
        virtual void update();

        using DefaultState::render;

        virtual void enter();
        virtual void exit();

    protected:
        void setupGameWorld();

        virtual void processEvent(const sf::Event& event);
        virtual void render(sf::RenderTarget& renderTarget);

        GameWorld gameWorld_;

        std::unique_ptr<mxg::SFMLDebugDraw> debugDraw_;
};

} /* namespace pong */
#endif /* PONG_STATE_GAMESTATE_HPP_ */
