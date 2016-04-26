#ifndef MXG_STATE_HPP_
#define MXG_STATE_HPP_

#include <SFML/Graphics.hpp>

namespace mxg {

class State {
    public:
        virtual ~State() {}

        virtual void create() = 0;
        virtual void destroy() = 0;

        virtual void enter() = 0;
        virtual void exit() = 0;

        virtual void processEvents() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
};

} /* namespace mxg */
#endif /* MXG_STATE_HPP_ */
