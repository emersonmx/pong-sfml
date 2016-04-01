#ifndef PONG_STATE_GAMESTATE_HPP_
#define PONG_STATE_GAMESTATE_HPP_

#include "Pong/State/DefaultState.hpp"
#include "Pong/GameWorld.hpp"
#include "Pong/Factory/GameShapeFactory.hpp"
#include "Pong/InputHandler/InputHandler.hpp"
#include "Pong/Defs.hpp"

#include "MXG/SFMLDebugDraw.hpp"

namespace pong {

class GameState: public DefaultState, public GameWorld::ScoreListener {
    public:
        using DefaultState::DefaultState;

        virtual void enter();
        virtual void exit();

        virtual void processEvent(const sf::Event& event);
        virtual void update();
        virtual void render(sf::RenderTarget& renderTarget);

        virtual void leftScored(GameWorld& gameWorld);
        virtual void rightScored(GameWorld& gameWorld);

    private:
        void create();

        void setupGameWorld();
        void setupDebugDraw();

        void setupInputHandlers();
        void setupPlayerOneInputHandler();
        void setupPlayerTwoInputHandler();

        void createShapes();
        void updateShapes();
        void renderShapes(sf::RenderTarget& renderTarget);

        void resetScores();

        GameWorld gameWorld_;

        GameShapeFactory shapeFactory_;
        sf::RectangleShape midfield_;
        sf::RectangleShape ball_;
        sf::RectangleShape leftRaquet_;
        sf::RectangleShape rightRaquet_;
        sf::RectangleShape topWall_;
        sf::RectangleShape bottomWall_;

        std::array< std::unique_ptr<InputHandler>, PLAYER_COUNT > inputHandlers_;

        int leftRaquetScore_ = 0;
        int rightRaquetScore_ = 0;

        std::unique_ptr<mxg::SFMLDebugDraw> debugDraw_;
};

} /* namespace pong */
#endif /* PONG_STATE_GAMESTATE_HPP_ */
