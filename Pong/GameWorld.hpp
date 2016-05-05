#ifndef PONG_GAMEWORLD_HPP_
#define PONG_GAMEWORLD_HPP_

#include <vector>
#include <memory>

#include <Box2D/Box2D.h>

namespace pong {

class GameWorld: public b2ContactListener {
    public:
        enum Filter {
            NONE = 0,
            RACKET = 1,
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

        b2Body* topWall() { return topWall_; }
        b2Body* bottomWall() { return bottomWall_; }
        b2Body* ball() { return ball_; }
        b2Body* leftRacket() { return leftRacket_; }
        b2Body* rightRacket() { return rightRacket_; }
        b2Body* gameArea() { return gameArea_; }
        b2Joint* leftRacketJoint() { return leftRacketJoint_; }
        b2Joint* rightRacketJoint() { return rightRacketJoint_; }

        void addScoreListener(ScoreListener* listener);
        void removeScoreListener(ScoreListener* listener);
        void removeAllScoreListeners();

        void create();
        void update();

        void start() { running_ = true; }
        void stop() { running_ = false; }
        void toggleRunning() { running_ = !running_; }

        void resetBall();
        void playBall();

        void setDebugDraw(b2Draw* debugDraw);
        void drawDebugData();

        void EndContact(b2Contact* contact) override;

    protected:
        virtual b2Body* createTopWall();
        virtual b2Body* createBottomWall();
        virtual b2Body* createBall();
        virtual b2Body* createLeftRacket();
        virtual b2Body* createRightRacket();
        virtual b2Body* createGameArea();
        virtual b2Joint* createLeftRacketJoint();
        virtual b2Joint* createRightRacketJoint();

        void postUpdate();
        void limitBallSpeed();
        void limitBallRotation();

        void fireScoreLeft();
        void fireScoreRight();

    private:
        enum class Scored {
            NONE, LEFT, RIGHT
        };

        std::unique_ptr<b2World> world_;
        b2Body* topWall_;
        b2Body* bottomWall_;
        b2Body* ball_;
        b2Body* leftRacket_;
        b2Body* rightRacket_;
        b2Body* gameArea_;

        b2Joint* leftRacketJoint_;
        b2Joint* rightRacketJoint_;

        std::vector<ScoreListener*> scoreListeners_;

        int stepCount_ = 0;
        Scored scored_;

        bool running_ = false;
};

} /* namespace pong */
#endif /* PONG_GAMEWORLD_HPP_ */
