#ifndef PONG_GAMEOBJECTS_WALL_HPP_
#define PONG_GAMEOBJECTS_WALL_HPP_

#include <SFML/Graphics/RectangleShape.hpp>
#include <Box2D/Dynamics/b2Body.h>

#include "Pong/GameObjects/GameObject.hpp"

namespace pong {

class Wall : public GameObject {
    public:
        Wall(b2Body* body) : body_(body) {}

        void create() override;

    protected:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        b2Body* body_;
        sf::RectangleShape shape_;
};

} /* namespace pong */
#endif /* PONG_GAMEOBJECTS_WALL_HPP_ */
