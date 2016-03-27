#include "pong/state.hpp"

#include <Box2D/Box2D.h>

#include "pong/game.hpp"
#include "pong/defs.hpp"

namespace pong {

void DefaultState::enter(Game* game) {
    game_ = game;
}

void DefaultState::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::Closed) {
        game_->exit();
    }
}

} /* namespace pong */
