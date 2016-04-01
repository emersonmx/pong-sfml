#include "pong/screen/default_screen.hpp"

#include "pong/pong.hpp"

namespace pong {

void DefaultScreen::processEvent(const sf::Event& event) {
    if (event.type == sf::Event::Closed) {
        game_->exit();
    }
}

} /* namespace pong */
