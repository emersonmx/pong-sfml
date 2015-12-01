#ifndef PONG_APPLICATION_HPP
#define PONG_APPLICATION_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "pong/config.hpp"

namespace pong {

class Application {
    public:
        Application() {}
        virtual ~Application() {}

        void exit(int errorCode=0);
        int run();

    protected:

        virtual void create();
        virtual void destroy();

        virtual void update();
        virtual void handleInput();
        virtual void processLogic();
        virtual void draw();

        sf::RenderWindow window;
        sf::Event event;

        Config config;

        sf::RectangleShape playerOneShape;
        sf::RectangleShape playerTwoShape;
        sf::RectangleShape ballShape;
        sf::RectangleShape topWallShape;
        sf::RectangleShape bottomWallShape;
        sf::RectangleShape midfieldPartShape;

        sf::Font sansFont;
        sf::Text playerOneScoreText;
        sf::Text playerTwoScoreText;

        int playerOneScore;
        int playerTwoScore;

    private:
        void setupConfig();
        void setupWindow();
        void setupShapes();
        void setupFonts();

        int errorCode = 0;
};

} /* namespace pong */ 
#endif /* PONG_APPLICATION_HPP */
