#ifndef PONG_STATE_GAMEREADYSTATE_HPP_
#define PONG_STATE_GAMEREADYSTATE_HPP_

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Pong/States/DefaultState.hpp"

namespace pong {

class GameState;

class GameReadyState : public DefaultState {
    public:
        GameReadyState(Application* app, GameState* gameState);

        void create() override;

        void update() override;

    protected:
        void processEvent(const sf::Event& event) override;
        void render(sf::RenderTarget& renderTarget) override;

    private:
        void setupWaitMessage();
        void setupStartMessage();

        GameState* gameState_;

        sf::Text waitMessage_;
        sf::Text startMessage_;

        sf::Clock clock_;
        bool ready_ = false;
        bool startDelay_ = false;
};

} /* namespace pong */
#endif /* PONG_STATE_GAMEREADYSTATE_HPP_ */
