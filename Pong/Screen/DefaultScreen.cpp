#include "Pong/Screen/DefaultScreen.hpp"

#include "Pong/Pong.hpp"

namespace pong {

void DefaultScreen::processEvent(const sf::Event& event) {
    if (event.type == sf::Event::Closed) {
        game_->exit();
    }
}

} /* namespace pong */
