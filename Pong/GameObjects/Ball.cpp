#include "Pong/GameObjects/Ball.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "Pong/Defs.hpp"
#include "Pong/Utils.hpp"
#include "Pong/GameWorld.hpp"

namespace pong {

void Ball::create() {
    body_ = gameWorld_.ball();

    shape_.setSize(sf::Vector2f(BALL_WIDTH, BALL_HEIGHT));
    shape_.setOrigin(shape_.getSize() / 2.0f);

    reset();

    Utils::syncBodyToTransformable(body_, shape_);
}

void Ball::update() {
    Utils::syncBodyToTransformable(body_, shape_);

    if (delay_) {
        sf::Time time = clock_.getElapsedTime();
        if (time.asSeconds() > 0.5f) {
            gameWorld_.playBall();
            delay_ = false;
        }
    }
}

void Ball::reset() {
    gameWorld_.resetBall();
    delay_ = true;
    clock_.restart();
}

void Ball::leftScored(GameWorld& gameWorld) {
    reset();
}

void Ball::rightScored(GameWorld& gameWorld) {
    reset();
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape_, states);
}

} /* namespace pong */
