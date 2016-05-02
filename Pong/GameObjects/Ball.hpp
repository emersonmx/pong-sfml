#ifndef PONG_GAMEOBJECTS_BALL_HPP_
#define PONG_GAMEOBJECTS_BALL_HPP_

#include <SFML/Graphics/RectangleShape.hpp>
#include <Box2D/Dynamics/b2Body.h>

#include "Pong/GameObjects/GameObject.hpp"

namespace pong {

class GameWorld;

class Ball : public GameObject {
    public:
        Ball(GameWorld& gameWorld) : gameWorld_(gameWorld) {}

        virtual void create();

        virtual void update();

    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        GameWorld& gameWorld_;

        b2Body* body_;
        sf::RectangleShape shape_;
};

} /* namespace pong */
#endif /* PONG_GAMEOBJECTS_BALL_HPP_ */
