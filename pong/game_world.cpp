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

    leftRaquetJoint_ = createLeftRaquetJoint();
    rightRaquetJoint_ = createRightRaquetJoint();
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
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.filter.categoryBits = WALL;
    fixtureDef.filter.maskBits = BALL;
    body->CreateFixture(&fixtureDef);

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
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.filter.categoryBits = WALL;
    fixtureDef.filter.maskBits = BALL;
    body->CreateFixture(&fixtureDef);

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
    bodyDef.linearVelocity.x = -10.0f;
    b2Body* body = world_->CreateBody(&bodyDef);
    b2PolygonShape shape;
    shape.SetAsBox(
        halfWidth / static_cast<float>(PIXELS_PER_METER),
        halfHeight / static_cast<float>(PIXELS_PER_METER)
    );
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.1f;
    fixtureDef.restitution = 1.0f;
    fixtureDef.filter.categoryBits = BALL;
    fixtureDef.filter.maskBits = ALL;
    body->CreateFixture(&fixtureDef);

    return body;
}

b2Body* GameWorld::createLeftRaquet() {
    float halfWidth = 10.0f;
    float halfHeight = 40.0f;

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
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
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.friction = 1.0f;
    fixtureDef.density = 1.0f;
    fixtureDef.filter.categoryBits = RAQUET;
    fixtureDef.filter.maskBits = BALL;

    body->CreateFixture(&fixtureDef);

    return body;
}

b2Body* GameWorld::createRightRaquet() {
    float halfWidth = 10.0f;
    float halfHeight = 40.0f;

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
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

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &shape;
    fixtureDef.friction = 1.0f;
    fixtureDef.density = 1.0f;
    fixtureDef.filter.categoryBits = RAQUET;
    fixtureDef.filter.maskBits = BALL;

    body->CreateFixture(&fixtureDef);

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
    fixtureDef.filter.categoryBits = GAME_AREA;
    fixtureDef.filter.maskBits = BALL;

    body->CreateFixture(&fixtureDef);

    return body;
}

b2Joint* GameWorld::createLeftRaquetJoint() {
    float margin = 50.0f;
    float limit = (WINDOW_HEIGHT / 2.0f) - margin;

    b2PrismaticJointDef jointDef;
    b2Vec2 axis(0.0f, 1.0f);

    jointDef.Initialize(gameArea_, leftRaquet_, gameArea_->GetWorldCenter(), axis);
    jointDef.collideConnected = false;
    jointDef.lowerTranslation = -limit / static_cast<float>(PIXELS_PER_METER);
    jointDef.upperTranslation = limit / static_cast<float>(PIXELS_PER_METER);
    jointDef.enableLimit = true;

    return world_->CreateJoint(&jointDef);
}

b2Joint* GameWorld::createRightRaquetJoint() {
    float margin = 50.0f;
    float limit = (WINDOW_HEIGHT / 2.0f) - margin;

    b2PrismaticJointDef jointDef;
    b2Vec2 axis(0.0f, 1.0f);

    jointDef.Initialize(gameArea_, rightRaquet_, gameArea_->GetWorldCenter(), axis);
    jointDef.collideConnected = false;
    jointDef.lowerTranslation = -limit / static_cast<float>(PIXELS_PER_METER);
    jointDef.upperTranslation = limit / static_cast<float>(PIXELS_PER_METER);
    jointDef.enableLimit = true;

    return world_->CreateJoint(&jointDef);
}

} /* namespace pong */
