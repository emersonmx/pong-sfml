#ifndef PONG_STATE_GAMESTATE_HPP_
#define PONG_STATE_GAMESTATE_HPP_

#include "Pong/State/DefaultState.hpp"
#include "Pong/GameWorld.hpp"
#include "Pong/Factory/GameShapeFactory.hpp"
#include "Pong/InputHandler/InputHandler.hpp"
#include "Pong/Defs.hpp"
#include "Pong/UI/ScoreBoard.hpp"
#include "Pong/UI/Shade.hpp"

#include "MXG/SFMLDebugDraw.hpp"

namespace pong {

class GameState: public DefaultState, public GameWorld::ScoreListener {
    public:
        using DefaultState::DefaultState;

        virtual void create();
        virtual void update();

        using DefaultState::render;

        virtual void enter();
        virtual void exit();

        virtual void leftScored(GameWorld& gameWorld);
        virtual void rightScored(GameWorld& gameWorld);

    protected:
        virtual void processEvent(const sf::Event& event);
        virtual void render(sf::RenderTarget& renderTarget);

    private:
        void setupGameWorld();
        void setupDebugDraw();

        void setupInputHandlers();
        void setupPlayerOneInputHandler();
        void setupPlayerTwoInputHandler();

        void createShapes();
        void createScoreBoard();
        void setupShade();

        void restartBallDelay();
        void updateBallDelay();

        void updateShapes();
        void renderShapes(sf::RenderTarget& renderTarget);

        void syncBodyToTransformable(b2Body* body, sf::Transformable& transformable);

        GameWorld gameWorld_;
        ScoreBoard scoreBoard_;

        GameShapeFactory shapeFactory_;
        sf::RectangleShape midfield_;
        sf::RectangleShape ball_;
        sf::RectangleShape leftRaquet_;
        sf::RectangleShape rightRaquet_;
        sf::RectangleShape topWall_;
        sf::RectangleShape bottomWall_;
        Shade shade_;

        sf::Clock ballClock_;
        bool ballDelay_ = true;

        std::array< std::unique_ptr<InputHandler>, PLAYER_COUNT > inputHandlers_;

        std::unique_ptr<mxg::SFMLDebugDraw> debugDraw_;
};

} /* namespace pong */
#endif /* PONG_STATE_GAMESTATE_HPP_ */
