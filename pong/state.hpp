#ifndef PONG_STATE_HPP_
#define PONG_STATE_HPP_

#include <memory>

#include <SFML/Graphics.hpp>

#include "pong/game_world.hpp"
#include "pong/input_handler.hpp"
#include "pong/factories.hpp"

#include "mxg/sfml_debug_draw.hpp"
#include "mxg/screen.hpp"

namespace pong {

class Pong;

class DefaultState: public mxg::DefaultScreen {
    public:
        DefaultState(Pong* game) : game_(game) {}

        virtual void processEvent(const sf::Event& event);

    protected:
        Pong* game_;
};

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
#endif /* PONG_STATE_HPP_ */
