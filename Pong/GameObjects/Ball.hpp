#ifndef PONG_GAMEOBJECTS_BALL_HPP_
#define PONG_GAMEOBJECTS_BALL_HPP_

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <Box2D/Dynamics/b2Body.h>

#include "Pong/GameObjects/GameObject.hpp"
#include "Pong/GameWorld.hpp"

namespace pong {

class GameWorld;

class Ball : public GameObject, public GameWorld::ScoreListener {
    public:
        Ball(GameWorld& gameWorld) : gameWorld_(gameWorld) {}

        virtual void create();

        virtual void update();

        void reset();

        virtual void leftScored(GameWorld& gameWorld);
        virtual void rightScored(GameWorld& gameWorld);

    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        GameWorld& gameWorld_;

        b2Body* body_;
        sf::RectangleShape shape_;

        sf::Clock clock_;
        bool delay_;
};

} /* namespace pong */
#endif /* PONG_GAMEOBJECTS_BALL_HPP_ */
