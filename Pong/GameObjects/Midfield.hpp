#ifndef PONG_GAMEOBJECTS_MIDFIELD_HPP_
#define PONG_GAMEOBJECTS_MIDFIELD_HPP_

#include <SFML/Graphics/RectangleShape.hpp>

#include "Pong/GameObjects/GameObject.hpp"

namespace pong {

class Midfield : public GameObject {
    public:
        virtual void create();

    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        sf::RectangleShape shape_;
};

} /* namespace pong */
#endif /* PONG_GAMEOBJECTS_MIDFIELD_HPP_ */
