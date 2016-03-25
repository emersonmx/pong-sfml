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
#ifndef NDEBUG
    setupDebugDraw();
#endif /* ifndef NDEBUG */
    setupGamepads();
}

void GameState::exit() {
}

void GameState::update() {
    handleGamepads();
    gameWorld_.update();
}

void GameState::render(sf::RenderTarget& renderTarget) {
#ifndef NDEBUG
    gameWorld_.world()->DrawDebugData();
#endif /* ifndef NDEBUG  */
}

void GameState::leftScored(GameWorld& gameWorld) {
    gameWorld.resetBall();
}

void GameState::rightScored(GameWorld& gameWorld) {
    gameWorld.resetBall();
}

void GameState::setupGameWorld() {
    gameWorld_.create();
    gameWorld_.addScoreListener(this);
}

void GameState::setupDebugDraw() {
    b2World* world = gameWorld_.world();
    debugDraw_.reset(new SFMLDebugDraw(application_->window(), pong::PIXELS_PER_METER));
    world->SetDebugDraw(debugDraw_.get());
    debugDraw_->SetFlags(b2Draw::e_shapeBit);
}

void GameState::setupGamepads() {
    firstPlayer_.reset(new KeyboardGamepad());
    firstPlayer_->setupButton(Gamepad::UP, sf::Keyboard::W);
    firstPlayer_->setupButton(Gamepad::DOWN, sf::Keyboard::S);
    firstPlayer_->setupButton(Gamepad::START, sf::Keyboard::Return);

    secondPlayer_.reset(new KeyboardGamepad());
    secondPlayer_->setupButton(Gamepad::UP, sf::Keyboard::Up);
    secondPlayer_->setupButton(Gamepad::DOWN, sf::Keyboard::Down);
    secondPlayer_->setupButton(Gamepad::START, sf::Keyboard::Return);
}

void GameState::handleGamepads() {
    b2Body* leftRaquet = gameWorld_.leftRaquet();
    b2Body* rightRaquet = gameWorld_.rightRaquet();

    if (firstPlayer_->isButtonPressed(Gamepad::UP)) {
        leftRaquet->SetLinearVelocity(b2Vec2(0.0f, RAQUET_BASE_SPEED));
    } else if (firstPlayer_->isButtonPressed(Gamepad::DOWN)) {
        leftRaquet->SetLinearVelocity(b2Vec2(0.0f, -RAQUET_BASE_SPEED));
    } else {
        leftRaquet->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
    }

    if (secondPlayer_->isButtonPressed(Gamepad::UP)) {
        rightRaquet->SetLinearVelocity(b2Vec2(0.0f, RAQUET_BASE_SPEED));
    } else if (secondPlayer_->isButtonPressed(Gamepad::DOWN)) {
        rightRaquet->SetLinearVelocity(b2Vec2(0.0f, -RAQUET_BASE_SPEED));
    } else {
        rightRaquet->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
    }
}

} /* namespace pong */
