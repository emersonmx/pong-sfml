#ifndef PONG_GAMEOBJECTS_MIDFIELD_HPP_
#define PONG_GAMEOBJECTS_MIDFIELD_HPP_

#include <SFML/Graphics/RectangleShape.hpp>

#include "Pong/GameObjects/GameObject.hpp"

namespace pong {

class Midfield : public GameObject {
    public:
        void create() override;

    protected:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        sf::RectangleShape shape_;
};

} /* namespace pong */
#endif /* PONG_GAMEOBJECTS_MIDFIELD_HPP_ */
