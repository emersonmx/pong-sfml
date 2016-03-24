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
        b2Body* leftRaquet() { return leftRaquet_; }
        b2Body* rightRaquet() { return rightRaquet_; }
        b2Body* gameArea() { return gameArea_; }

        void create();

        void update();

    protected:
        virtual b2Body* createTopWall();
        virtual b2Body* createBottomWall();
        virtual b2Body* createBall();
        virtual b2Body* createLeftRaquet();
        virtual b2Body* createRightRaquet();
        virtual b2Body* createGameArea();

    private:
        std::unique_ptr<b2World> world_;
        b2Body* topWall_;
        b2Body* bottomWall_;
        b2Body* ball_;
        b2Body* leftRaquet_;
        b2Body* rightRaquet_;
        b2Body* gameArea_;
};

} /* namespace pong */
#endif /* PONG_GAME_WORLD_HPP */
