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

    create();
}

void GameState::create() {
    setupGameWorld();
    setupInputHandlers();
}

void GameState::setupGameWorld() {
    gameWorld_.create();
    gameWorld_.setScoreListener(this);
    gameWorld_.start();

#ifndef NDEBUG
    setupDebugDraw();
#endif /* ifndef NDEBUG */
}

void GameState::setupDebugDraw() {
    debugDraw_.reset(new SFMLDebugDraw(game_->window(), pong::PIXELS_PER_METER));
    gameWorld_.setDebugDraw(debugDraw_.get());
    debugDraw_->SetFlags(b2Draw::e_shapeBit);
}

void GameState::setupInputHandlers() {
    setupPlayerOneInputHandler();
    setupPlayerTwoInputHandler();
}

void GameState::setupPlayerOneInputHandler() {
    b2Body* leftRaquet = gameWorld_.leftRaquet();
    b2Vec2 upVelocity(0.0f, RAQUET_BASE_SPEED);
    b2Vec2 downVelocity(0.0f, -RAQUET_BASE_SPEED);

    RaquetInputHandler* leftHandler = new RaquetInputHandler(leftRaquet);
    leftHandler->bindKey(sf::Keyboard::W, InputHandler::UP);
    leftHandler->bindKey(sf::Keyboard::S, InputHandler::DOWN);

    Command* command = new MoveRaquetCommand(leftRaquet, upVelocity);
    leftHandler->bindCommand(InputHandler::UP, command);
    command = new MoveRaquetCommand(leftRaquet, downVelocity);
    leftHandler->bindCommand(InputHandler::DOWN, command);

    inputHandlers_[PLAYER_1].reset(leftHandler);
}

void GameState::setupPlayerTwoInputHandler() {
    b2Body* leftRaquet = gameWorld_.rightRaquet();
    b2Vec2 upVelocity(0.0f, RAQUET_BASE_SPEED);
    b2Vec2 downVelocity(0.0f, -RAQUET_BASE_SPEED);

    RaquetInputHandler* rightHandler = new RaquetInputHandler(leftRaquet);
    rightHandler->bindKey(sf::Keyboard::Up, InputHandler::UP);
    rightHandler->bindKey(sf::Keyboard::Down, InputHandler::DOWN);

    Command* command = new MoveRaquetCommand(leftRaquet, upVelocity);
    rightHandler->bindCommand(InputHandler::UP, command);
    command = new MoveRaquetCommand(leftRaquet, downVelocity);
    rightHandler->bindCommand(InputHandler::DOWN, command);

    inputHandlers_[PLAYER_2].reset(rightHandler);
}

void GameState::exit() {
}

void GameState::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::R) {
            create();
        }
    } else {
        DefaultState::handleInput(event);
    }
}

void GameState::update() {
    for (auto& handler : inputHandlers_) {
        Command* command = handler->handleInput();
        command->execute();
    }

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
