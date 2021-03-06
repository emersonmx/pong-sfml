#include "Pong/GameWorld.hpp"

#include "Pong/Defs.hpp"

#include "MXG/Random.hpp"

namespace pong {

void GameWorld::addScoreListener(ScoreListener* listener) {
    if (listener == nullptr) {
        return;
    }

    scoreListeners_.push_back(listener);
}

void GameWorld::removeScoreListener(ScoreListener* listener) {
    if (listener == nullptr) {
        return;
    }

    auto it = std::remove(scoreListeners_.begin(), scoreListeners_.end(), listener);
    scoreListeners_.erase(it);
}

void GameWorld::removeAllScoreListeners() {
    scoreListeners_.clear();
}

void GameWorld::create() {
    b2Vec2 gravity(0, 0);
    world_.reset(new b2World(gravity));
    world_->SetAllowSleeping(true);

    topWall_ = createTopWall();
    bottomWall_ = createBottomWall();
    ball_ = createBall();
    leftRacket_ = createLeftRacket();
    rightRacket_ = createRightRacket();
    gameArea_ = createGameArea();

    leftRacketJoint_ = createLeftRacketJoint();
    rightRacketJoint_ = createRightRacketJoint();

    world_->SetContactListener(this);

    stepCount_ = 0;
}

void GameWorld::update() {
    if (running_) {
        world_->Step(GAME_TIME_STEP, GAME_VELOCITY_ITERATIONS,
                    GAME_POSITION_ITERATIONS);
        world_->ClearForces();

        if (ball_->IsActive()) {
            limitBallSpeed();
            limitBallRotation();
        }
        postUpdate();

        stepCount_++;
    }
}

void GameWorld::resetBall() {
    b2Vec2 position;
    position.Set(
        WINDOW_HALF_WIDTH / static_cast<float>(PIXELS_PER_METER),
        WINDOW_HALF_HEIGHT / static_cast<float>(PIXELS_PER_METER)
    );

    ball_->SetTransform(position, 0);
    ball_->SetActive(false);
    stepCount_ = 0;
}

void GameWorld::playBall() {
    mxg::Random random;

    b2Vec2 velocity;
    velocity.x = random.nextInt() % 2 == 0 ? -1 : 1;
    velocity.y = random.nextFloat(-1, 1);
    ball_->SetLinearVelocity(velocity);

    float rotation = random.nextFloat(
        BALL_MIN_ROTATION_SPEED,
        BALL_MAX_ROTATION_SPEED
    ) * (random.nextInt() % 2 == 0 ? -1 : 1);
    ball_->SetAngularVelocity(rotation);
    ball_->SetActive(true);
}

void GameWorld::setDebugDraw(b2Draw* debugDraw) {
    world_->SetDebugDraw(debugDraw);
}

void GameWorld::drawDebugData() {
    world_->DrawDebugData();
}

void GameWorld::EndContact(b2Contact* contact) {
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();
    uint16 categoryA = fixtureA->GetFilterData().categoryBits;
    uint16 categoryB = fixtureB->GetFilterData().categoryBits;
    b2Body* ball = nullptr;
    b2Body* gameArea = nullptr;

    if (categoryA == BALL && categoryB == GAME_AREA) {
        ball = fixtureA->GetBody();
        gameArea = fixtureB->GetBody();
    } else if(categoryA == GAME_AREA && categoryB == BALL) {
        ball = fixtureB->GetBody();
        gameArea = fixtureA->GetBody();
    } else {
        return;
    }

    b2Vec2 ballPosition = ball->GetPosition();
    b2Vec2 gameAreaPosition = gameArea->GetPosition();

    if (ballPosition.x < gameAreaPosition.x) {
        scored_ = Scored::RIGHT;
    } else if (ballPosition.x > gameAreaPosition.x) {
        scored_ = Scored::LEFT;
    }
}

b2Body* GameWorld::createTopWall() {
    float halfWidth = WALL_HALF_WIDTH;
    float halfHeight = WALL_HALF_HEIGHT;

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
    float halfWidth = WALL_HALF_WIDTH;
    float halfHeight = WALL_HALF_HEIGHT;

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
    float halfWidth = BALL_HALF_WIDTH;
    float halfHeight = BALL_HALF_HEIGHT;

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(
        WINDOW_HALF_WIDTH / static_cast<float>(PIXELS_PER_METER),
        WINDOW_HALF_HEIGHT / static_cast<float>(PIXELS_PER_METER)
    );
    bodyDef.active = false;

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

b2Body* GameWorld::createLeftRacket() {
    float halfWidth = RACKET_HALF_WIDTH;
    float halfHeight = RACKET_HALF_HEIGHT;
    float margin = RACKET_MARGIN;

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.fixedRotation = true;
    bodyDef.position.Set(
        margin / static_cast<float>(PIXELS_PER_METER),
        WINDOW_HALF_HEIGHT / static_cast<float>(PIXELS_PER_METER)
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
    fixtureDef.filter.categoryBits = RACKET;
    fixtureDef.filter.maskBits = BALL;

    body->CreateFixture(&fixtureDef);

    return body;
}

b2Body* GameWorld::createRightRacket() {
    float halfWidth = RACKET_HALF_WIDTH;
    float halfHeight = RACKET_HALF_HEIGHT;
    float margin = RACKET_MARGIN;

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.fixedRotation = true;
    bodyDef.position.Set(
        (WINDOW_WIDTH - margin) / static_cast<float>(PIXELS_PER_METER),
        WINDOW_HALF_HEIGHT / static_cast<float>(PIXELS_PER_METER)
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
    fixtureDef.filter.categoryBits = RACKET;
    fixtureDef.filter.maskBits = BALL;

    body->CreateFixture(&fixtureDef);

    return body;
}

b2Body* GameWorld::createGameArea() {
    float halfWidth = WINDOW_HALF_WIDTH;
    float halfHeight = WINDOW_HALF_HEIGHT - (2 * WALL_HALF_HEIGHT);

    b2BodyDef bodyDef;
    bodyDef.position.Set(
        WINDOW_HALF_WIDTH / static_cast<float>(PIXELS_PER_METER),
        WINDOW_HALF_HEIGHT / static_cast<float>(PIXELS_PER_METER)
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

b2Joint* GameWorld::createLeftRacketJoint() {
    float margin = 50.0f;
    float limit = (WINDOW_HEIGHT / 2.0f) - margin;

    b2PrismaticJointDef jointDef;
    b2Vec2 axis(0.0f, 1.0f);

    jointDef.Initialize(gameArea_, leftRacket_, gameArea_->GetWorldCenter(), axis);
    jointDef.collideConnected = false;
    jointDef.lowerTranslation = -limit / static_cast<float>(PIXELS_PER_METER);
    jointDef.upperTranslation = limit / static_cast<float>(PIXELS_PER_METER);
    jointDef.enableLimit = true;

    return world_->CreateJoint(&jointDef);
}

b2Joint* GameWorld::createRightRacketJoint() {
    float margin = 50.0f;
    float limit = (WINDOW_HEIGHT / 2.0f) - margin;

    b2PrismaticJointDef jointDef;
    b2Vec2 axis(0.0f, 1.0f);

    jointDef.Initialize(gameArea_, rightRacket_, gameArea_->GetWorldCenter(), axis);
    jointDef.collideConnected = false;
    jointDef.lowerTranslation = -limit / static_cast<float>(PIXELS_PER_METER);
    jointDef.upperTranslation = limit / static_cast<float>(PIXELS_PER_METER);
    jointDef.enableLimit = true;

    return world_->CreateJoint(&jointDef);
}

void GameWorld::postUpdate() {
    if (scored_ == Scored::LEFT) {
        fireScoreLeft();
        scored_ = Scored::NONE;
    } else if (scored_ == Scored::RIGHT) {
        fireScoreRight();
        scored_ = Scored::NONE;
    }
}

void GameWorld::limitBallSpeed() {
    b2Vec2 velocity = ball_->GetLinearVelocity();
    float speed = velocity.Length();
    float minSpeen = BALL_MIN_SPEED + (stepCount_ * BALL_VELOCITY_STEP);
    minSpeen = minSpeen > BALL_MAX_SPEED ? BALL_MAX_SPEED : minSpeen;
    if (speed > BALL_MAX_SPEED) {
        velocity *= BALL_MAX_SPEED / speed;
        ball_->SetLinearVelocity(velocity);
    } else if (speed < minSpeen) {
        velocity *= minSpeen / speed;
        ball_->SetLinearVelocity(velocity);
    }
}

void GameWorld::limitBallRotation() {
    float rotation = ball_->GetAngularVelocity();
    int direction = rotation > 0 ? 1 : -1;
    if (abs(rotation) > BALL_MAX_ROTATION_SPEED) {
        rotation = BALL_MAX_ROTATION_SPEED * direction;
    } else if (-BALL_MIN_ROTATION_SPEED <= rotation &&
            rotation <= BALL_MIN_ROTATION_SPEED) {
        rotation = BALL_MIN_ROTATION_SPEED * direction;
    }
    ball_->SetAngularVelocity(rotation);
}

void GameWorld::fireScoreLeft() {
    for (auto listener : scoreListeners_) {
        listener->leftScored(*this);
    }
}

void GameWorld::fireScoreRight() {
    for (auto listener : scoreListeners_) {
        listener->rightScored(*this);
    }
}

} /* namespace pong */
