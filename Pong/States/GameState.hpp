#ifndef PONG_STATE_GAMESTATE_HPP_
#define PONG_STATE_GAMESTATE_HPP_

#include <memory>

#include "Pong/States/DefaultState.hpp"
#include "Pong/Defs.hpp"
#include "Pong/GameWorld.hpp"

#include "Pong/GameObjects/GameObject.hpp"
#include "Pong/GameObjects/Shade.hpp"
#include "Pong/GameObjects/ScoreBoard.hpp"

#include "MXG/SFMLDebugDraw.hpp"

namespace pong {

class GameState: public DefaultState {
    public:
        using DefaultState::DefaultState;

        void create() override;
        void update() override;

        void enter() override;
        void exit() override;

        using DefaultState::render;

        void reset();

    protected:
        void setupGameWorld();
        void setupGameObjects();

        void processEvent(const sf::Event& event) override;
        void render(sf::RenderTarget& renderTarget) override;

        GameWorld gameWorld_;

        std::unique_ptr<GameObject> ball_;
        std::unique_ptr<GameObject> leftRacket_;
        std::unique_ptr<GameObject> rightRacket_;
        std::unique_ptr<GameObject> topWall_;
        std::unique_ptr<GameObject> bottomWall_;
        std::unique_ptr<GameObject> midfield_;
        std::unique_ptr<ScoreBoard> scoreBoard_;
        std::unique_ptr<Shade> shade_;

        std::unique_ptr<mxg::SFMLDebugDraw> debugDraw_;

        bool gameStarted_ = false;
        bool highlightScoreBoard_ = false;
};

} /* namespace pong */
#endif /* PONG_STATE_GAMESTATE_HPP_ */
