#ifndef PONG_STATES_GAMEOVERSTATE_HPP_
#define PONG_STATES_GAMEOVERSTATE_HPP_

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Pong/States/DefaultState.hpp"
#include "Pong/GameObjects/ScoreBoard.hpp"
#include "Pong/GameObjects/Menu.hpp"

namespace pong {

class GameState;

class GameOverState : public DefaultState {
    public:
        GameOverState(Application* app, GameState* gameState, ScoreBoard::Winner winner);

        void enter() override;

        void create() override;

        void update() override;

        void endTick() override;

    protected:
        enum MenuOption {
            NONE = -1, RESTART, BACK_TO_MAIN_MENU
        };

        void processEvent(const sf::Event& event) override;
        void render(sf::RenderTarget& renderTarget) override;

        GameState* gameState_;
        ScoreBoard::Winner winner_;

        sf::Text message_;
        sf::Clock clock_;
        bool delay_ = false;

        std::unique_ptr<Menu> menu_;
        int selected_ = MenuOption::NONE;
};

} /* namespace pong */
#endif /* PONG_STATES_GAMEOVERSTATE_HPP_ */
