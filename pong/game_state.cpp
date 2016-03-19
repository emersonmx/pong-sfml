#include "pong/state.hpp"

#include "pong/defs.hpp"

namespace pong {

sf::RectangleShape createRectangleShape(float width, float height) { sf::RectangleShape shape;
    shape.setOrigin(width / 2, height / 2);
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::White);
    return shape;
}

void syncBodyToTransformable(b2Body* body, sf::Transformable& transformable) {
    b2Vec2 position = body->GetPosition();
    float angle = body->GetAngle();
    transformable.setPosition(position.x * PIXELS_PER_METER,
                          position.y * PIXELS_PER_METER);
    transformable.setRotation(angle);
}

void GameState::setup(Application* application) {
}

void GameState::enter() {
    gameWorld_.create();

    box_ = createRectangleShape(50, 50);
    box_.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 100);
    box_.setFillColor(sf::Color::Red);
    ground_ = createRectangleShape(WINDOW_WIDTH, 20);
    ground_.setPosition(WINDOW_WIDTH / 2, 10);
    ground_.setFillColor(sf::Color::Green);
}

void GameState::exit() {
}

void GameState::update() {
    gameWorld_.update();

    syncBodyToTransformable(gameWorld_.box(), box_);
    syncBodyToTransformable(gameWorld_.ground(), ground_);
}

void GameState::render(sf::RenderTarget& renderTarget) {
    renderTarget.draw(box_);
    renderTarget.draw(ground_);
}

} /* namespace pong */
