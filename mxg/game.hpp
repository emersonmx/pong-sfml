#ifndef MXG_GAME_HPP_
#define MXG_GAME_HPP_

#include <memory>
#include <stack>

#include "mxg/screen.hpp"

namespace mxg {

class Game {
    public:
        Game() {}
        virtual ~Game() {}

        Screen* currentScreen();
        void pushScreen(Screen* screen);
        void popScreen();
        void changeScreen(Screen* screen);

        void exit();
        void exit(int errorCode);
        int run();

    protected:

        virtual void create() {}
        virtual void destroy() {}

        virtual void tick() {}

    private:
        std::stack< std::unique_ptr<Screen> > screens_;

        int errorCode_ = 0;
        bool running_ = true;
};

} /* namespace mxg */
#endif /* MXG_GAME_HPP_ */
