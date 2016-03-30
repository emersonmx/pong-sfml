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

void GameState::enter() {
    DefaultState::enter();

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
    b2Body* rightRaquet = gameWorld_.rightRaquet();
    b2Body* ball = gameWorld_.ball();
    b2Vec2 upVelocity(0.0f, RAQUET_BASE_SPEED);
    b2Vec2 downVelocity(0.0f, -RAQUET_BASE_SPEED);

    float xMaxDistance = (WINDOW_HALF_WIDHT - RAQUET_WIDTH) / PIXELS_PER_METER;
    float yMaxDistance = (RAQUET_HALF_HEIGHT - 20.0f) / PIXELS_PER_METER;
    ComputerPlayerInputHandler* rightHandler =
        new ComputerPlayerInputHandler(rightRaquet, ball,
                                       xMaxDistance, yMaxDistance);

    Command* command = new MoveRaquetCommand(rightRaquet, upVelocity);
    rightHandler->bindCommand(InputHandler::UP, command);
    command = new MoveRaquetCommand(rightRaquet, downVelocity);
    rightHandler->bindCommand(InputHandler::DOWN, command);

    inputHandlers_[PLAYER_2].reset(rightHandler);
}

void GameState::exit() {
}

void GameState::processEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::R) {
            create();
        } else if (event.key.code == sf::Keyboard::P) {
            gameWorld_.toggleRunning();
        }
    } else {
        DefaultState::processEvent(event);
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
