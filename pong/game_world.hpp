#ifndef PONG_GAME_WORLD_HPP
#define PONG_GAME_WORLD_HPP

#include <memory>

#include <Box2D/Box2D.h>

#include "pong/defs.hpp"

namespace pong {

class GameWorld: public b2ContactListener {
    public:
        enum Filter {
            NONE = 0,
            RAQUET = 1,
            BALL = 2,
            WALL = 4,
            GAME_AREA = 8,
            ALL = 15
        };

        class ScoreListener {
            public:
                virtual ~ScoreListener() {}

                virtual void leftScored(GameWorld& gameWorld) {}
                virtual void rightScored(GameWorld& gameWorld) {}
        };

        b2World* world() { return world_.get(); }

        b2Body* topWall() { return topWall_; }
        b2Body* bottomWall() { return bottomWall_; }
        b2Body* ball() { return ball_; }
        b2Body* leftRaquet() { return leftRaquet_; }
        b2Body* rightRaquet() { return rightRaquet_; }
        b2Body* gameArea() { return gameArea_; }
        b2Joint* leftRaquetJoint() { return leftRaquetJoint_; }
        b2Joint* rightRaquetJoint() { return rightRaquetJoint_; }

        void addScoreListener(ScoreListener* listener) {
            scoreListener_ = listener;
        }

        void create();
        void update();

        void start() { running_ = true; }
        void stop() { running_ = false; }
        void toggleRunning() { running_ = !running_; }
        void restart();
        void resetBall();

        virtual void EndContact(b2Contact* contact);

    protected:
        virtual b2Body* createTopWall();
        virtual b2Body* createBottomWall();
        virtual b2Body* createBall();
        virtual b2Body* createLeftRaquet();
        virtual b2Body* createRightRaquet();
        virtual b2Body* createGameArea();
        virtual b2Joint* createLeftRaquetJoint();
        virtual b2Joint* createRightRaquetJoint();

        void limitBallSpeed();
        void limitBallRotation();
        void handleResets();

        void fireScoreLeft();
        void fireScoreRight();

    private:
        std::unique_ptr<b2World> world_;
        b2Body* topWall_;
        b2Body* bottomWall_;
        b2Body* ball_;
        b2Body* leftRaquet_;
        b2Body* rightRaquet_;
        b2Body* gameArea_;

        b2Joint* leftRaquetJoint_;
        b2Joint* rightRaquetJoint_;

        ScoreListener* scoreListener_;

        bool softReset_ = false;
        bool hardReset_ = false;

        int stepCount_ = 0;

        bool running_ = false;
};

} /* namespace pong */
#endif /* PONG_GAME_WORLD_HPP */
