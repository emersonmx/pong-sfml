#include "Pong/States/GameState.hpp"

#include "Pong/Application.hpp"

#include "Pong/States/GameOverState.hpp"
#include "Pong/States/GameMenuState.hpp"

#include "Pong/GameObjects/Ball.hpp"
#include "Pong/GameObjects/Racket.hpp"
#include "Pong/GameObjects/Wall.hpp"
#include "Pong/GameObjects/Midfield.hpp"
#include "Pong/GameObjects/PlayerRacket.hpp"
#include "Pong/GameObjects/ComputerRacket.hpp"

namespace pong {

void GameState::create() {
    setupGameWorld();
    setupGameObjects();
    gameStarted_ = true;
}

void GameState::update() {
    gameWorld_.update();

    ball_->update();
    leftRacket_->update();
    rightRacket_->update();
    scoreBoard_->update();

    if (scoreBoard_->isGameOver()) {
        highlightScoreBoard_ = true;
        ScoreBoard::Winner winner = scoreBoard_->winner();
        GameOverState* gameOver = new GameOverState(app_, this, winner);
        gameOver->create();
        app_->pushState(gameOver);
    }
}

void GameState::enter() {
    shade_->visible = false;
    gameStarted_ = true;
    highlightScoreBoard_ = false;
    scoreBoard_->hide();
}

void GameState::exit() {
    shade_->visible = true;
    gameStarted_ = false;
}

void GameState::reset() {
    Ball* ball = static_cast<Ball*>(ball_.get());
    ball->reset();
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
    midfield_.reset(new Midfield());
    midfield_->create();

    Ball* ball = new Ball(gameWorld_);
    ball_.reset(ball);
    ball_->create();
    gameWorld_.addScoreListener(ball);

    leftRacket_.reset(new PlayerRacket(gameWorld_.leftRacket()));
    leftRacket_->create();

    ComputerRacket* computerRacket = new ComputerRacket(
        gameWorld_.rightRacket(),
        gameWorld_.ball()
    );
    computerRacket->xMaxDistance = (WINDOW_HALF_WIDTH - RACKET_WIDTH) / PIXELS_PER_METER;
    computerRacket->yMaxDistance = (RACKET_HALF_HEIGHT - 20.0f) / PIXELS_PER_METER;
    rightRacket_.reset(computerRacket);
    rightRacket_->create();

    topWall_.reset(new Wall(gameWorld_.topWall()));
    topWall_->create();
    bottomWall_.reset(new Wall(gameWorld_.bottomWall()));
    bottomWall_->create();

    ScoreBoard* scoreBoard = new ScoreBoard(app_->assets().defaultFont());
    gameWorld_.addScoreListener(scoreBoard);
    scoreBoard_.reset(scoreBoard);
    scoreBoard_->create();

    shade_.reset(new Shade());
    shade_->create();
}

void GameState::processEvent(const sf::Event& event) {
    DefaultState::processEvent(event);

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Return) {
            if (gameStarted_) {
                highlightScoreBoard_ = true;
                scoreBoard_->show();
                GameMenuState* gameMenuState = new GameMenuState(app_, this);
                gameMenuState->create();
                app_->pushState(gameMenuState);
            }
        }
    }
}

void GameState::render(sf::RenderTarget& renderTarget) {
#ifndef NDEBUG
    gameWorld_.drawDebugData();
#endif /* ifndef NDEBUG  */

    renderTarget.draw(*midfield_);
    renderTarget.draw(*ball_);
    renderTarget.draw(*leftRacket_);
    renderTarget.draw(*rightRacket_);
    renderTarget.draw(*topWall_);
    renderTarget.draw(*bottomWall_);
    if (highlightScoreBoard_) {
        renderTarget.draw(*shade_);
        renderTarget.draw(*scoreBoard_);
    } else {
        renderTarget.draw(*scoreBoard_);
        renderTarget.draw(*shade_);
    }
}

} /* namespace pong */
