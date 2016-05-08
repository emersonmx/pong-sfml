#ifndef PONG_STATES_MAINMENUSTATE_HPP_
#define PONG_STATES_MAINMENUSTATE_HPP_

#include <memory>

#include <SFML/Graphics/Sprite.hpp>

#include "Pong/States/DefaultState.hpp"
#include "Pong/GameObjects/Menu.hpp"

namespace pong {

class MainMenuState : public DefaultState {
public:
    using DefaultState::DefaultState;

        void create() override;

        void endTick() override;

    protected:
        enum MenuOption {
            NONE = -1, START_GAME, QUIT_GAME
        };

        void processEvent(const sf::Event& event) override;
        void render(sf::RenderTarget& renderTarget) override;

        sf::Sprite logo_;
        std::unique_ptr<Menu> menu_;
        int selected_ = MenuOption::NONE;
};

} /* namespace pong */
#endif /* PONG_STATES_MAINMENUSTATE_HPP_ */
