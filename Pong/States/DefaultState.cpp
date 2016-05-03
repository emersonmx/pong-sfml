#include "Pong/States/DefaultState.hpp"

#include "Pong/Application.hpp"

namespace pong {

void DefaultState::processEvents() {
    sf::Event event;
    sf::Window& window = app_->window();
    while (window.pollEvent(event)) {
        processEvent(event);
    }
}

void DefaultState::render() {
    render(app_->window());
}

void DefaultState::processEvent(const sf::Event& event) {
    if (event.type == sf::Event::Closed) {
        app_->exit();
    }
}

} /* namespace pong */
