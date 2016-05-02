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
    Ball* ball = new Ball(gameWorld_);
    ball->create();
    ball_.reset(ball);
}

void GameState::processEvent(const sf::Event& event) {
    DefaultState::processEvent(event);
}

void GameState::render(sf::RenderTarget& renderTarget) {
    renderTarget.draw(*ball_);

#ifndef NDEBUG
    gameWorld_.drawDebugData();
#endif /* ifndef NDEBUG  */
}

} /* namespace pong */
