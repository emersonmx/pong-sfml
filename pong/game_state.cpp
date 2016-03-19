#include "pong/state.hpp"

#include <Box2D/Box2D.h>

#include "pong/application.hpp"
#include "pong/defs.hpp"

namespace pong {

sf::RectangleShape createRectangleShape(float width, float height) {
    sf::RectangleShape shape;
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

void GameState::enter(Application* application) {
    application_ = application;

    setupGameWorld();
}

void GameState::exit() {
}

void GameState::update() {
    gameWorld_.update();

    syncBodyToTransformable(gameWorld_.box(), box_);
    syncBodyToTransformable(gameWorld_.ground(), ground_);
}

void GameState::render(sf::RenderTarget& renderTarget) {
    gameWorld_.world()->DrawDebugData();
}

void GameState::setupGameWorld() {
    gameWorld_.create();

    b2World* world = gameWorld_.world();
    debugDraw_.reset(new SFMLDebugDraw(application_->window(), pong::PIXELS_PER_METER));
    world->SetDebugDraw(debugDraw_.get());
    debugDraw_->SetFlags(b2Draw::e_shapeBit);
}

} /* namespace pong */
