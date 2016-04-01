#include "pong/screen.hpp"

#include <Box2D/Box2D.h>

#include "pong/pong.hpp"
#include "pong/defs.hpp"

namespace pong {

void DefaultScreen::processEvent(const sf::Event& event) {
    if (event.type == sf::Event::Closed) {
        game_->exit();
    }
}

} /* namespace pong */
