#include "Pong/State/GameState.hpp"

#include <iostream>

#include "Pong/Pong.hpp"
#include "Pong/InputHandler/RaquetInputHandler.hpp"
#include "Pong/InputHandler/ComputerPlayerInputHandler.hpp"

namespace pong {

void syncBodyToTransformable(b2Body* body, sf::Transformable& transformable) {
    b2Vec2 position = body->GetPosition();
    float angle = body->GetAngle();
    transformable.setPosition(position.x * PIXELS_PER_METER,
                              position.y * PIXELS_PER_METER);
    transformable.setRotation(angle * 180.0f / M_PI);
}

void GameState::create() {
    setupGameWorld();
    setupInputHandlers();
    createShapes();
    createScoreBoard();
}

void GameState::setupGameWorld() {
    gameWorld_.create();
    gameWorld_.addScoreListener(&scoreBoard_);
    gameWorld_.addScoreListener(this);
    gameWorld_.start();

#ifndef NDEBUG
    setupDebugDraw();
#endif /* ifndef NDEBUG */
}

void GameState::setupDebugDraw() {
    debugDraw_.reset(new mxg::SFMLDebugDraw(game_->window(), PIXELS_PER_METER));
    gameWorld_.setDebugDraw(debugDraw_.get());
    debugDraw_->SetFlags(b2Draw::e_shapeBit);
}

void GameState::setupInputHandlers() {
    setupPlayerOneInputHandler();
    setupPlayerTwoInputHandler(); }

void GameState::setupPlayerOneInputHandler() {
    b2Body* leftRaquet = gameWorld_.leftRaquet();
    b2Vec2 upVelocity(0.0f, -RAQUET_BASE_SPEED);
    b2Vec2 downVelocity(0.0f, RAQUET_BASE_SPEED);

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

void GameState::createShapes() {
    midfield_ = shapeFactory_.makeMidfield();
    ball_ = shapeFactory_.makeBall();
    syncBodyToTransformable(gameWorld_.ball(), ball_);
    leftRaquet_ = shapeFactory_.makeLeftRaquet();
    syncBodyToTransformable(gameWorld_.leftRaquet(), leftRaquet_);
    rightRaquet_ = shapeFactory_.makeRightRaquet();
    syncBodyToTransformable(gameWorld_.rightRaquet(), rightRaquet_);
    topWall_ = shapeFactory_.makeTopWall();
    syncBodyToTransformable(gameWorld_.topWall(), topWall_);
    bottomWall_ = shapeFactory_.makeBottomWall();
    syncBodyToTransformable(gameWorld_.bottomWall(), bottomWall_);
}

void GameState::createScoreBoard() {
    sf::Vector2f position(WINDOW_HALF_WIDHT, 32);

    Assets& assets = game_->assets();
    scoreBoard_.create(assets.defaultFont());
    scoreBoard_.setPosition(position);
}

void GameState::updateShapes() {
    syncBodyToTransformable(gameWorld_.ball(), ball_);
    syncBodyToTransformable(gameWorld_.leftRaquet(), leftRaquet_);
    syncBodyToTransformable(gameWorld_.rightRaquet(), rightRaquet_);
}

void GameState::renderShapes(sf::RenderTarget& renderTarget) {
    renderTarget.draw(midfield_);
    renderTarget.draw(ball_);
    renderTarget.draw(leftRaquet_);
    renderTarget.draw(rightRaquet_);
    renderTarget.draw(topWall_);
    renderTarget.draw(bottomWall_);
    renderTarget.draw(scoreBoard_);
}

void GameState::enter() {
}

void GameState::exit() {
}

void GameState::processEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::R) {
            GameState* state = new GameState(game_);
            state->create();
            game_->changeState(state);
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

    updateShapes();
    scoreBoard_.update();

    if (scoreBoard_.rightScore() >= MATCH_POINT) {
        GameState* state = new GameState(game_);
        state->create();
        game_->changeState(state);
        std::cout << "Right win!" << std::endl;
    } else if (scoreBoard_.leftScore() >= MATCH_POINT) {
        GameState* state = new GameState(game_);
        state->create();
        game_->changeState(state);
        std::cout << "Left win!" << std::endl;
    }
}

void GameState::render(sf::RenderTarget& renderTarget) {
    renderShapes(renderTarget);

#ifndef NDEBUG
    gameWorld_.drawDebugData();
#endif /* ifndef NDEBUG  */
}

void GameState::leftScored(GameWorld& gameWorld) {
    gameWorld.resetBall();
    gameWorld.start();
}

void GameState::rightScored(GameWorld& gameWorld) {
    gameWorld.resetBall();
    gameWorld.start();
}

} /* namespace pong */
