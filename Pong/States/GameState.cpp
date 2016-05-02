#include "Pong/States/GameState.hpp"

#include <iostream>

#include "Pong/Pong.hpp"

namespace pong {

void GameState::create() {
    setupGameWorld();
}

void GameState::update() {
    gameWorld_.update();
}

void GameState::enter() {
}

void GameState::exit() {
}

void GameState::setupGameWorld() {
    gameWorld_.create();
    //gameWorld_.addScoreListener(&scoreBoard_);
    //gameWorld_.addScoreListener(this);
    gameWorld_.start();

#ifndef NDEBUG
    debugDraw_.reset(new mxg::SFMLDebugDraw(game_->window(), PIXELS_PER_METER));
    gameWorld_.setDebugDraw(debugDraw_.get());
    debugDraw_->SetFlags(b2Draw::e_shapeBit);
#endif /* ifndef NDEBUG */
}

void GameState::processEvent(const sf::Event& event) {
    DefaultState::processEvent(event);
}

void GameState::render(sf::RenderTarget& renderTarget) {
#ifndef NDEBUG
    gameWorld_.drawDebugData();
#endif /* ifndef NDEBUG  */
}

} /* namespace pong */
