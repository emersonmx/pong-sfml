#include "pong/state.hpp"

#include "pong/defs.hpp"

namespace pong {

void GameState::setup(Application* application) {
}

void GameState::enter() {
    gameWorld_.create();

    box_.setOrigin(25, 25);
    box_.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 100);
    box_.setSize(sf::Vector2f(50, 50));
    box_.setFillColor(sf::Color::Red);
    ground_.setOrigin(WINDOW_WIDTH / 2, 10);
    ground_.setPosition(WINDOW_WIDTH / 2, 10);
    ground_.setSize(sf::Vector2f(WINDOW_WIDTH, 20));
    ground_.setFillColor(sf::Color::Green);
}

void GameState::exit() {
}

void GameState::update() {
    gameWorld_.update();

    updateTransformable(box_, gameWorld_.box());
    updateTransformable(ground_, gameWorld_.ground());
}

void GameState::updateTransformable(sf::Transformable& transformable, b2Body* body) {
    b2Vec2 position = body->GetPosition();
    float angle = body->GetAngle();
    transformable.setPosition(position.x * PIXELS_PER_METER,
                          position.y * PIXELS_PER_METER);
    transformable.setRotation(angle);
}

void GameState::render(sf::RenderTarget& renderTarget) {
    renderTarget.draw(box_);
    renderTarget.draw(ground_);
}

} /* namespace pong */
