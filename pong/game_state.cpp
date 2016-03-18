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

    b2Body* body = gameWorld_.box();
    b2Vec2 pos = body->GetPosition();
    float angle = body->GetAngle();
    box_.setPosition(pos.x * PIXELS_PER_METER, pos.y * PIXELS_PER_METER);
    box_.setRotation(angle);

    body = gameWorld_.ground();
    pos = body->GetPosition();
    angle = body->GetAngle();
    ground_.setPosition(pos.x * PIXELS_PER_METER, pos.y * PIXELS_PER_METER);
    ground_.setRotation(angle);
}

void GameState::render(sf::RenderTarget& renderTarget) {
    renderTarget.draw(box_);
    renderTarget.draw(ground_);
}

} /* namespace pong */
