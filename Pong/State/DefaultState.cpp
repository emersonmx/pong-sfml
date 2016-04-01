#include "Pong/State/DefaultState.hpp"

#include "Pong/Pong.hpp"

namespace pong {

void DefaultState::processEvent(const sf::Event& event) {
    if (event.type == sf::Event::Closed) {
        game_->exit();
    }
}

} /* namespace pong */
