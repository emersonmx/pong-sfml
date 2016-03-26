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

void GameState::enter(Game* game) {
    game_ = game;

    setupGameWorld();
#ifndef NDEBUG
    setupDebugDraw();
#endif /* ifndef NDEBUG */
    setupControllers();
}

void GameState::exit() {
}

void GameState::update() {
    handleControllers();
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

void GameState::setupControllers() {
    firstPlayer_.reset(new KeyboardController());
    firstPlayer_->setupButton(Controller::UP, sf::Keyboard::W);
    firstPlayer_->setupButton(Controller::DOWN, sf::Keyboard::S);
    firstPlayer_->setupButton(Controller::START, sf::Keyboard::Return);

    secondPlayer_.reset(new KeyboardController());
    secondPlayer_->setupButton(Controller::UP, sf::Keyboard::Up);
    secondPlayer_->setupButton(Controller::DOWN, sf::Keyboard::Down);
    secondPlayer_->setupButton(Controller::START, sf::Keyboard::Return);
}

void GameState::handleControllers() {
    b2Body* leftRaquet = gameWorld_.leftRaquet();
    b2Body* rightRaquet = gameWorld_.rightRaquet();

    if (firstPlayer_->isButtonPressed(Controller::UP)) {
        leftRaquet->SetLinearVelocity(b2Vec2(0.0f, RAQUET_BASE_SPEED));
    } else if (firstPlayer_->isButtonPressed(Controller::DOWN)) {
        leftRaquet->SetLinearVelocity(b2Vec2(0.0f, -RAQUET_BASE_SPEED));
    } else {
        leftRaquet->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
    }

    if (secondPlayer_->isButtonPressed(Controller::UP)) {
        rightRaquet->SetLinearVelocity(b2Vec2(0.0f, RAQUET_BASE_SPEED));
    } else if (secondPlayer_->isButtonPressed(Controller::DOWN)) {
        rightRaquet->SetLinearVelocity(b2Vec2(0.0f, -RAQUET_BASE_SPEED));
    } else {
        rightRaquet->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
    }
}

} /* namespace pong */
