#ifndef PONG_STATE_DEFAULTSTATE_HPP_
#define PONG_STATE_DEFAULTSTATE_HPP_

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "MXG/DefaultState.hpp"

namespace pong {

class Application;

class DefaultState: public mxg::DefaultState {
    public:
        DefaultState(Application* app) : app_(app) {}

        void processEvents() override;
        void render() override;

    protected:
        virtual void processEvent(const sf::Event& event);
        virtual void render(sf::RenderTarget& renderTarget) {}

        Application* app_;
};

} /* namespace pong */
#endif /* PONG_STATE_DEFAULTSTATE_HPP_ */
