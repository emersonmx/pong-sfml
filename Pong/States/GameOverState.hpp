#ifndef PONG_STATES_GAMEOVERSTATE_HPP_
#define PONG_STATES_GAMEOVERSTATE_HPP_

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Pong/States/DefaultState.hpp"
#include "Pong/GameObjects/ScoreBoard.hpp"

namespace pong {

class GameState;

class GameOverState : public DefaultState {
    public:
        GameOverState(Application* app, GameState* gameState, ScoreBoard::Winner winner);

        void enter() override;

        void create() override;

        void update() override;

    protected:
        void render(sf::RenderTarget& renderTarget) override;

        GameState* gameState_;
        ScoreBoard::Winner winner_;

        sf::Text message_;
        sf::Clock clock_;
        bool delay_ = false;
};

} /* namespace pong */
#endif /* PONG_STATES_GAMEOVERSTATE_HPP_ */
