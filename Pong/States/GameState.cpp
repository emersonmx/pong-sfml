#include "Pong/States/GameState.hpp"

#include <iostream>

#include "Pong/Application.hpp"

#include "Pong/GameObjects/Ball.hpp"
#include "Pong/GameObjects/Racket.hpp"
#include "Pong/GameObjects/Wall.hpp"
#include "Pong/GameObjects/Midfield.hpp"
#include "Pong/GameObjects/PlayerRacket.hpp"
#include "Pong/GameObjects/ComputerRacket.hpp"
#include "Pong/GameObjects/ScoreBoard.hpp"

namespace pong {

void GameState::create() {
    setupGameWorld();
    setupGameObjects();
}

void GameState::update() {
    gameWorld_.update();

    for (auto& object : gameObjects_) {
        object->update();
    }
}

void GameState::setupGameWorld() {
    gameWorld_.create();
    gameWorld_.start();

#ifndef NDEBUG
    debugDraw_.reset(new mxg::SFMLDebugDraw(app_->window(), PIXELS_PER_METER));
    gameWorld_.setDebugDraw(debugDraw_.get());
    debugDraw_->SetFlags(b2Draw::e_shapeBit);
#endif /* ifndef NDEBUG */
}

void GameState::setupGameObjects() {
    Midfield* midfield = new Midfield();
    gameObjects_.emplace_back(midfield);

    Ball* ball = new Ball(gameWorld_);
    gameWorld_.addScoreListener(ball);
    gameObjects_.emplace_back(ball);

    PlayerRacket* playerRacket = new PlayerRacket(gameWorld_.leftRacket());
    gameObjects_.emplace_back(playerRacket);

    ComputerRacket* computerRacket = new ComputerRacket(
        gameWorld_.rightRacket(),
        gameWorld_.ball()
    );
    computerRacket->xMaxDistance = (WINDOW_HALF_WIDTH - RACKET_WIDTH) / PIXELS_PER_METER;
    computerRacket->yMaxDistance = (RACKET_HALF_HEIGHT - 20.0f) / PIXELS_PER_METER;
    gameObjects_.emplace_back(computerRacket);

    Wall* topWall = new Wall(gameWorld_.topWall());
    gameObjects_.emplace_back(topWall);

    Wall* bottomWall = new Wall(gameWorld_.bottomWall());
    gameObjects_.emplace_back(bottomWall);

    ScoreBoard* scoreBoard = new ScoreBoard(app_->assets().defaultFont());
    gameWorld_.addScoreListener(scoreBoard);
    gameObjects_.emplace_back(scoreBoard);

    for (auto& object : gameObjects_) {
        object->create();
    }
}

void GameState::processEvent(const sf::Event& event) {
    DefaultState::processEvent(event);
}

void GameState::render(sf::RenderTarget& renderTarget) {
    for (auto& object : gameObjects_) {
        renderTarget.draw(*object);
    }

#ifndef NDEBUG
    gameWorld_.drawDebugData();
#endif /* ifndef NDEBUG  */
}

} /* namespace pong */
