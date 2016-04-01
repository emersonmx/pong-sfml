#ifndef PONG_SCREEN_GAME_SCREEN_HPP_
#define PONG_SCREEN_GAME_SCREEN_HPP_

#include "pong/screen/default_screen.hpp"
#include "pong/game_world.hpp"
#include "pong/factories.hpp"
#include "pong/input_handler.hpp"
#include "pong/defs.hpp"

#include "mxg/sfml_debug_draw.hpp"

namespace pong {

class GameScreen: public DefaultScreen, public GameWorld::ScoreListener {
    public:
        using DefaultScreen::DefaultScreen;

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
#endif /* PONG_SCREEN_GAME_SCREEN_HPP_ */
