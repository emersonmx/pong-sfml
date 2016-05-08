#ifndef PONG_STATES_GAMEMENUSTATE_HPP_
#define PONG_STATES_GAMEMENUSTATE_HPP_

#include "Pong/States/DefaultState.hpp"

#include "Pong/GameObjects/Menu.hpp"

namespace pong {

class Application;
class GameState;

class GameMenuState : public DefaultState {
    public:
        GameMenuState(Application* app, GameState* gameState);

        void create() override;

        void endTick() override;

    protected:
        enum MenuOption {
            NONE = -1, RESUME, RESTART, BACK_TO_MAIN_MENU
        };

        void processEvent(const sf::Event& event) override;
        void render(sf::RenderTarget& renderTarget) override;

        GameState* gameState_;

        std::unique_ptr<Menu> menu_;
        int selected_ = MenuOption::NONE;
};

} /* namespace pong */
#endif /* PONG_STATES_GAMEMENUSTATE_HPP_ */
