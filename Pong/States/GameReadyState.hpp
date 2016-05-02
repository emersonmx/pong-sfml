#ifndef PONG_STATE_GAMEREADYSTATE_HPP_
#define PONG_STATE_GAMEREADYSTATE_HPP_

#include "Pong/State/DefaultState.hpp"

namespace pong {

class GameState;

class GameReadyState : public DefaultState {
    public:
        GameReadyState(Pong* pong, GameState* gameState);

        virtual void create();

    protected:
        virtual void processEvent(const sf::Event& event);
        virtual void render(sf::RenderTarget& renderTarget);

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
