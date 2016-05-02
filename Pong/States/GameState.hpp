#ifndef PONG_STATE_GAMESTATE_HPP_
#define PONG_STATE_GAMESTATE_HPP_

#include "Pong/States/DefaultState.hpp"
#include "Pong/Defs.hpp"

namespace pong {

class GameState: public DefaultState {
    public:
        using DefaultState::DefaultState;

        virtual void create();
        virtual void update();

        using DefaultState::render;

        virtual void enter();
        virtual void exit();

    protected:
        virtual void processEvent(const sf::Event& event);
        virtual void render(sf::RenderTarget& renderTarget);
};

} /* namespace pong */
#endif /* PONG_STATE_GAMESTATE_HPP_ */
