#ifndef MXG_DEFAULTSTATE_HPP_
#define MXG_DEFAULTSTATE_HPP_

#include "MXG/State.hpp"

namespace mxg {

class DefaultState: public State {
    public:
        virtual void create() {}
        virtual void destroy() {}

        virtual void enter() {}
        virtual void exit() {}

        virtual void processEvents() {}
        virtual void update() {}
        virtual void render() {}
};

} /* namespace mxg */
#endif /* MXG_DEFAULTSTATE_HPP_ */
