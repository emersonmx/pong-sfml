#ifndef PONG_GAMEOBJECTS_RACKET_HPP_
#define PONG_GAMEOBJECTS_RACKET_HPP_

#include <SFML/Graphics/RectangleShape.hpp>
#include <Box2D/Dynamics/b2Body.h>

#include "Pong/GameObjects/GameObject.hpp"

namespace pong {

class Racket : public GameObject {
    public:
        Racket(b2Body* body) : body_(body) {}

        virtual void create();

        virtual void update();

    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        b2Body* body_;
        sf::RectangleShape shape_;
};

} /* namespace pong */
#endif /* PONG_GAMEOBJECTS_RACKET_HPP_ */
