#include "Pong/States/GameState.hpp"

#include <iostream>

#include "Pong/Pong.hpp"

namespace pong {

void GameState::create() {
    setupGameWorld();
    setupGameObjects();
}

void GameState::destroy() {
    ball_->destroy();
}

void GameState::update() {
    gameWorld_.update();

    ball_->update();
    leftRacket_->update();
    //rightRacket_->update();
}

void GameState::enter() {
    gameWorld_.playBall();
}

void GameState::exit() {
}

void GameState::leftScored(GameWorld& gameWorld) {
    gameWorld_.resetBall();
    gameWorld_.playBall();
    std::cout << "Left Scored!" << std::endl;
}

void GameState::rightScored(GameWorld& gameWorld) {
    gameWorld_.resetBall();
    gameWorld_.playBall();
    std::cout << "Right Scored!" << std::endl;
}

void GameState::setupGameWorld() {
    gameWorld_.create();
    gameWorld_.addScoreListener(this);
    gameWorld_.start();

#ifndef NDEBUG
    debugDraw_.reset(new mxg::SFMLDebugDraw(game_->window(), PIXELS_PER_METER));
    gameWorld_.setDebugDraw(debugDraw_.get());
    debugDraw_->SetFlags(b2Draw::e_shapeBit);
#endif /* ifndef NDEBUG */
}

void GameState::setupGameObjects() {
    ball_.reset(new Ball(gameWorld_));
    ball_->create();

    leftRacket_.reset(new PlayerRacket(gameWorld_.leftRacket()));
    leftRacket_->create();

    //rightRacket_.reset(new Racket(gameWorld_.rightRacket()));
    //rightRacket_->create();
}

void GameState::processEvent(const sf::Event& event) {
    DefaultState::processEvent(event);
}

void GameState::render(sf::RenderTarget& renderTarget) {
    renderTarget.draw(*ball_);
    renderTarget.draw(*leftRacket_);
    //renderTarget.draw(*rightRacket_);

#ifndef NDEBUG
    gameWorld_.drawDebugData();
#endif /* ifndef NDEBUG  */
}

} /* namespace pong */
