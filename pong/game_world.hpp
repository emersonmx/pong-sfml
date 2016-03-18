#ifndef PONG_GAME_WORLD_HPP
#define PONG_GAME_WORLD_HPP

#include <memory>

#include <Box2D/Box2D.h>

#include "pong/defs.hpp"

namespace pong {

class GameWorld {
    public:
        b2Body* box() { return box_; }
        b2Body* ground() { return ground_; }

        void create() {
            b2Vec2 gravity(0, -10);
            world_.reset(new b2World(gravity));

            ground_ = createGround();
            box_ = createBox();
        }

        void update() {
            world_->Step(GAME_TIME_STEP, GAME_VELOCITY_ITERATIONS,
                        GAME_POSITION_ITERATIONS);
        }

    protected:
        virtual b2Body* createBox() {
            b2BodyDef boxDef;
            boxDef.type = b2_dynamicBody;
            boxDef.position.Set((WINDOW_WIDTH / 2) / (float) PIXELS_PER_METER,
                                (WINDOW_HEIGHT - 100) / (float) PIXELS_PER_METER);
            b2Body* body = world_->CreateBody(&boxDef);
            b2PolygonShape dynamicBox;
            dynamicBox.SetAsBox(25 / (float) PIXELS_PER_METER,
                                25 / (float) PIXELS_PER_METER);
            b2FixtureDef fixDef;
            fixDef.shape = &dynamicBox;
            fixDef.density = 1;
            fixDef.friction = 0.3;
            body->CreateFixture(&fixDef);

            return body;
        }

        virtual b2Body* createGround() {
            b2BodyDef groundDef;
            groundDef.position.Set((WINDOW_WIDTH / 2) / (float) PIXELS_PER_METER,
                                   10 / (float) PIXELS_PER_METER);
            b2Body* body = world_->CreateBody(&groundDef);
            b2PolygonShape groundBox;
            groundBox.SetAsBox(WINDOW_WIDTH / (float) PIXELS_PER_METER,
                               10 / (float) PIXELS_PER_METER);
            body->CreateFixture(&groundBox, 0);

            return body;
        }

    private:
        std::unique_ptr<b2World> world_;
        b2Body* box_;
        b2Body* ground_;
};

} /* namespace pong */
#endif /* PONG_GAME_WORLD_HPP */
