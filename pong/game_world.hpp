#ifndef PONG_GAME_WORLD_HPP
#define PONG_GAME_WORLD_HPP

#include <memory>

#include <Box2D/Box2D.h>

#include "pong/defs.hpp"

namespace pong {

class GameWorld {
    public:
        b2World* world() { return world_.get(); }

        b2Body* topWall() { return topWall_; }
        b2Body* bottomWall() { return bottomWall_; }
        b2Body* ball() { return ball_; }

        void create() {
            b2Vec2 gravity(0, 0);
            world_.reset(new b2World(gravity));
            world_->SetAllowSleeping(true);

            topWall_ = createTopWall();
            bottomWall_ = createBottomWall();
            ball_ = createBall();
        }

        void update() {
            world_->Step(GAME_TIME_STEP, GAME_VELOCITY_ITERATIONS,
                         GAME_POSITION_ITERATIONS);
        }

    protected:
        virtual b2Body* createTopWall(); 
        virtual b2Body* createBottomWall(); 
        virtual b2Body* createBall();

    private:
        std::unique_ptr<b2World> world_;
        b2Body* topWall_;
        b2Body* bottomWall_;
        b2Body* ball_;
};

} /* namespace pong */
#endif /* PONG_GAME_WORLD_HPP */
