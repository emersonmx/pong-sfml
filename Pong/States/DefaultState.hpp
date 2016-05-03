#ifndef PONG_STATE_DEFAULTSTATE_HPP_
#define PONG_STATE_DEFAULTSTATE_HPP_

#include "MXG/DefaultState.hpp"

namespace pong {

class Application;

class DefaultState: public mxg::DefaultState {
    public:
        DefaultState(Application* app) : app_(app) {}

        virtual void processEvents();
        virtual void render();

    protected:
        virtual void processEvent(const sf::Event& event);
        virtual void render(sf::RenderTarget& renderTarget) {}

        Application* app_;
};

} /* namespace pong */
#endif /* PONG_STATE_DEFAULTSTATE_HPP_ */
