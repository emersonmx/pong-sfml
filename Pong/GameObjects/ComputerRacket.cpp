#include "Pong/GameObjects/ComputerRacket.hpp"

#include "Pong/Defs.hpp"
#include "Pong/GameWorld.hpp"

namespace pong {

void ComputerRacket::handleInput() {
    b2Vec2 ballPosition = ball_->GetPosition();
    b2Vec2 racketPosition = body_->GetPosition();

    if (abs(racketPosition.x - ballPosition.x) > xMaxDistance) {
        float windowHalfHeight = WINDOW_HALF_HEIGHT / PIXELS_PER_METER;

        if (racketPosition.y + yMaxDistance < windowHalfHeight) {
            body_->SetLinearVelocity(b2Vec2(0.0f, RACKET_BASE_SPEED));
            return;
        } else if (racketPosition.y - yMaxDistance > windowHalfHeight) {
            body_->SetLinearVelocity(b2Vec2(0.0f, -RACKET_BASE_SPEED));
            return;
        }

        body_->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
        return;
    }

    if (racketPosition.y + yMaxDistance < ballPosition.y) {
        body_->SetLinearVelocity(b2Vec2(0.0f, RACKET_BASE_SPEED));
        return;
    } else if (racketPosition.y - yMaxDistance > ballPosition.y) {
        body_->SetLinearVelocity(b2Vec2(0.0f, -RACKET_BASE_SPEED));
        return;
    }

    body_->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
}

} /* namespace pong */
