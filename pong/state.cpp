#include "pong/state.hpp"

#include <Box2D/Box2D.h>

#include "pong/game.hpp"
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

void DefaultState::enter(Game* game) {
    game_ = game;
}

void DefaultState::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::Closed) {
        game_->exit();
    }
}

void GameState::enter(Game* game) {
    DefaultState::enter(game);

    setupGameWorld();
#ifndef NDEBUG
    setupDebugDraw();
#endif /* ifndef NDEBUG */

    setupInputHandlers();
}

void GameState::setupGameWorld() {
    gameWorld_.create();
    gameWorld_.setScoreListener(this);
    gameWorld_.start();
}

void GameState::setupDebugDraw() {
    debugDraw_.reset(new SFMLDebugDraw(game_->window(), pong::PIXELS_PER_METER));
    gameWorld_.setDebugDraw(debugDraw_.get());
    debugDraw_->SetFlags(b2Draw::e_shapeBit);
}

void GameState::setupInputHandlers() {
}

void GameState::exit() {
}

void GameState::handleInput(const sf::Event& event) {
}

void GameState::update() {
    gameWorld_.update();
}

void GameState::render(sf::RenderTarget& renderTarget) {
#ifndef NDEBUG
    gameWorld_.drawDebugData();
#endif /* ifndef NDEBUG  */
}

void GameState::leftScored(GameWorld& gameWorld) {
    gameWorld.resetBall();
}

void GameState::rightScored(GameWorld& gameWorld) {
    gameWorld.resetBall();
}

} /* namespace pong */
