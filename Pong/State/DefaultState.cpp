#include "Pong/State/DefaultState.hpp"

#include "Pong/Pong.hpp"

namespace pong {

void DefaultState::processEvents() {
    sf::Event event;
    sf::Window& window = game_->window();
    while (window.pollEvent(event)) {
        processEvent(event);
    }
}

void DefaultState::render() {
    render(game_->window());
}

void DefaultState::processEvent(const sf::Event& event) {
    if (event.type == sf::Event::Closed) {
        game_->exit();
    }
}

} /* namespace pong */
