#ifndef PONG_STATE_GAMESTATE_HPP_
#define PONG_STATE_GAMESTATE_HPP_

#include <memory>

#include "Pong/States/DefaultState.hpp"
#include "Pong/Defs.hpp"
#include "Pong/GameWorld.hpp"

#include "Pong/GameObjects/GameObject.hpp"

#include "MXG/SFMLDebugDraw.hpp"

namespace pong {

class GameState: public DefaultState {
    public:
        using DefaultState::DefaultState;

        virtual void create();
        virtual void update();

        using DefaultState::render;

    protected:
        void setupGameWorld();
        void setupGameObjects();

        virtual void processEvent(const sf::Event& event);
        virtual void render(sf::RenderTarget& renderTarget);

        GameWorld gameWorld_;

        std::unique_ptr<GameObject> ball_;
        std::unique_ptr<GameObject> leftRacket_;
        std::unique_ptr<GameObject> rightRacket_;
        std::unique_ptr<GameObject> topWall_;
        std::unique_ptr<GameObject> bottomWall_;
        std::unique_ptr<GameObject> midfield_;
        std::unique_ptr<GameObject> scoreBoard_;

        std::unique_ptr<mxg::SFMLDebugDraw> debugDraw_;
};

} /* namespace pong */
#endif /* PONG_STATE_GAMESTATE_HPP_ */
