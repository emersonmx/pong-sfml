#include "pong/game_world.hpp"

namespace pong {

void GameWorld::create() {
    b2Vec2 gravity(0, 0);
    world_.reset(new b2World(gravity));
    world_->SetAllowSleeping(true);

    topWall_ = createTopWall();
    bottomWall_ = createBottomWall();
    ball_ = createBall();
}

void GameWorld::update() {
    world_->Step(GAME_TIME_STEP, GAME_VELOCITY_ITERATIONS,
                 GAME_POSITION_ITERATIONS);
}

b2Body* GameWorld::createTopWall() {
    float width = WINDOW_WIDTH / 2.0f;
    float height = 5.0f;

    b2BodyDef bodyDef;
    bodyDef.position.Set(
            width / static_cast<float>(PIXELS_PER_METER),
            height / static_cast<float>(PIXELS_PER_METER)
            );
    b2Body* body = world_->CreateBody(&bodyDef);
    b2PolygonShape shape;
    shape.SetAsBox(
            width / static_cast<float>(PIXELS_PER_METER),
            height / static_cast<float>(PIXELS_PER_METER)
            );
    body->CreateFixture(&shape, 0.0f);

    return body;
}

b2Body* GameWorld::createBottomWall() {
    float width = WINDOW_WIDTH / 2.0f;
    float height = 5.0f;

    b2BodyDef bodyDef;
    bodyDef.position.Set(
            width / static_cast<float>(PIXELS_PER_METER),
            (WINDOW_HEIGHT - height) / static_cast<float>(PIXELS_PER_METER)
            );
    b2Body* body = world_->CreateBody(&bodyDef);
    b2PolygonShape shape;
    shape.SetAsBox(
            width / static_cast<float>(PIXELS_PER_METER),
            height / static_cast<float>(PIXELS_PER_METER)
            );
    body->CreateFixture(&shape, 0.0f);

    return body;
}

b2Body* GameWorld::createBall() {
    float width = 5.0f;
    float height = 5.0f;

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(
            (WINDOW_WIDTH / 2.0f) / static_cast<float>(PIXELS_PER_METER),
            (WINDOW_HEIGHT / 2.0f) / static_cast<float>(PIXELS_PER_METER)
            );
    bodyDef.linearVelocity.y = -10.0f;
    b2Body* body = world_->CreateBody(&bodyDef);
    b2PolygonShape shape;
    shape.SetAsBox(
            width / static_cast<float>(PIXELS_PER_METER),
            height / static_cast<float>(PIXELS_PER_METER)
            );
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 1.0f;
    body->CreateFixture(&fixtureDef);

    return body;
}

} /* namespace pong */
