#ifndef MXG_GAME_HPP_
#define MXG_GAME_HPP_

#include <memory>
#include <stack>

#include "MXG/DefaultState.hpp"

namespace mxg {

class Game {
    public:
        Game() {}
        virtual ~Game() {}

        State* currentState();
        void pushState(State* state);
        void popState();
        void clearStates();
        void changeState(State* state);

        void exit();
        void exit(int errorCode);
        int run();

    protected:

        virtual void create() {}
        virtual void destroy() {}

        virtual void tick() {}

    private:
        std::stack< std::unique_ptr<State> > states_;

        int errorCode_ = 0;
        bool running_ = true;
};

} /* namespace mxg */
#endif /* MXG_GAME_HPP_ */
