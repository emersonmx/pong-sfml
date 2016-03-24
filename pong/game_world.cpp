#include "pong/game_world.hpp"

namespace pong {

void GameWorld::create() {
    b2Vec2 gravity(0, 0);
    world_.reset(new b2World(gravity));
    world_->SetAllowSleeping(true);

    topWall_ = createTopWall();
    bottomWall_ = createBottomWall();
    ball_ = createBall();
    leftRaquet_ = createLeftRaquet();
    rightRaquet_ = createRightRaquet();
    gameArea_ = createGameArea();
}

void GameWorld::update() {
    world_->Step(GAME_TIME_STEP, GAME_VELOCITY_ITERATIONS,
                 GAME_POSITION_ITERATIONS);
}

b2Body* GameWorld::createTopWall() {
    float halfWidth = WINDOW_WIDTH / 2.0f;
    float halfHeight = 5.0f;

    b2BodyDef bodyDef;
    bodyDef.position.Set(
        halfWidth / static_cast<float>(PIXELS_PER_METER),
        halfHeight / static_cast<float>(PIXELS_PER_METER)
    );
    b2Body* body = world_->CreateBody(&bodyDef);
    b2PolygonShape shape;
    shape.SetAsBox(
        halfWidth / static_cast<float>(PIXELS_PER_METER),
        halfHeight / static_cast<float>(PIXELS_PER_METER)
    );
    body->CreateFixture(&shape, 0.0f);

    return body;
}

b2Body* GameWorld::createBottomWall() {
    float halfWidth = WINDOW_WIDTH / 2.0f;
    float halfHeight = 5.0f;

    b2BodyDef bodyDef;
    bodyDef.position.Set(
        halfWidth / static_cast<float>(PIXELS_PER_METER),
        (WINDOW_HEIGHT - halfHeight) / static_cast<float>(PIXELS_PER_METER)
    );
    b2Body* body = world_->CreateBody(&bodyDef);
    b2PolygonShape shape;
    shape.SetAsBox(
        halfWidth / static_cast<float>(PIXELS_PER_METER),
        halfHeight / static_cast<float>(PIXELS_PER_METER)
    );
    body->CreateFixture(&shape, 0.0f);

    return body;
}

b2Body* GameWorld::createBall() {
    float halfWidth = 5.0f;
    float halfHeight = 5.0f;

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
        halfWidth / static_cast<float>(PIXELS_PER_METER),
        halfHeight / static_cast<float>(PIXELS_PER_METER)
    );
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 1.0f;
    body->CreateFixture(&fixtureDef);

    return body;
}

b2Body* GameWorld::createLeftRaquet() {
    float halfWidth = 10.0f;
    float halfHeight = 40.0f;

    b2BodyDef bodyDef;
    bodyDef.type = b2_kinematicBody;
    bodyDef.fixedRotation = true;
    bodyDef.position.Set(
        15.0f / static_cast<float>(PIXELS_PER_METER),
        (WINDOW_HEIGHT / 2.0f) / static_cast<float>(PIXELS_PER_METER)
    );
    b2Body* body = world_->CreateBody(&bodyDef);
    b2PolygonShape shape;
    shape.SetAsBox(
        halfWidth / static_cast<float>(PIXELS_PER_METER),
        halfHeight / static_cast<float>(PIXELS_PER_METER)
    );
    body->CreateFixture(&shape, 0.0f);

    return body;
}

b2Body* GameWorld::createRightRaquet() {
    float halfWidth = 10.0f;
    float halfHeight = 40.0f;

    b2BodyDef bodyDef;
    bodyDef.type = b2_kinematicBody;
    bodyDef.fixedRotation = true;
    bodyDef.position.Set(
        (WINDOW_WIDTH - 15.0f) / static_cast<float>(PIXELS_PER_METER),
        (WINDOW_HEIGHT / 2.0f) / static_cast<float>(PIXELS_PER_METER)
    );
    b2Body* body = world_->CreateBody(&bodyDef);
    b2PolygonShape shape;
    shape.SetAsBox(
        halfWidth / static_cast<float>(PIXELS_PER_METER),
        halfHeight / static_cast<float>(PIXELS_PER_METER)
    );
    body->CreateFixture(&shape, 0.0f);

    return body;
}

b2Body* GameWorld::createGameArea() {
    float halfWidth = WINDOW_WIDTH / 2.0f;
    float halfHeight = WINDOW_HEIGHT / 2.0f - 10.0f;

    b2BodyDef bodyDef;
    bodyDef.position.Set(
        (WINDOW_WIDTH / 2.0f) / static_cast<float>(PIXELS_PER_METER),
        (WINDOW_HEIGHT / 2.0f) / static_cast<float>(PIXELS_PER_METER)
    );
    b2Body* body = world_->CreateBody(&bodyDef);
    b2PolygonShape shape;
    shape.SetAsBox(
        halfWidth / static_cast<float>(PIXELS_PER_METER),
        halfHeight / static_cast<float>(PIXELS_PER_METER)
    );
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.isSensor = true;

    body->CreateFixture(&fixtureDef);

    return body;
}

} /* namespace pong */
