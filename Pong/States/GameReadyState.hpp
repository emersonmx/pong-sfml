#ifndef PONG_STATE_GAMEREADYSTATE_HPP_
#define PONG_STATE_GAMEREADYSTATE_HPP_

#include "Pong/State/DefaultState.hpp"

namespace pong {

class GameState;

class GameReadyState : public DefaultState {
    public:
        GameReadyState(Application* app, GameState* gameState);

        void create() override;

    protected:
        void processEvent(const sf::Event& event) override;
        void render(sf::RenderTarget& renderTarget) override;

    private:
        void setupTexts();
        void setupMessage();
        void setupLeftReady();
        void setupRightReady();
        void applyDefaultStyle(sf::Text& text);

        GameState* gameState_;

        sf::Text message_;
        sf::Text leftReadyText_;
        sf::Text rightReadyText_;
        bool leftReady_ = false;
        bool rightReady_ = false;
};

} /* namespace pong */
#endif /* PONG_STATE_GAMEREADYSTATE_HPP_ */
