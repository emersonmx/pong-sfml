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

    private:
        void setupConfig();
        void setupWindow();

        int errorCode = 0;
};

} /* namespace pong */ 
#endif /* PONG_APPLICATION_HPP */
