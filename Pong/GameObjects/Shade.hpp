#ifndef PONG_GAMEOBJECTS_SHADE_HPP_
#define PONG_GAMEOBJECTS_SHADE_HPP_

#include <SFML/Graphics/RectangleShape.hpp>

#include "Pong/GameObjects/GameObject.hpp"

namespace pong {

class Shade : public GameObject {
    public:
        sf::Vector2f position();
        void setPosition(const sf::Vector2f& position);
        sf::Vector2f size();
        void setSize(const sf::Vector2f& size);
        sf::Color fillColor();
        void setFillColor(const sf::Color& color);

        void show();
        void hide();
        bool isVisible() { return visible_; }

        void create() override;

    protected:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        sf::RectangleShape shape_;

        bool visible_;
};

} /* namespace pong */
#endif /* PONG_GAMEOBJECTS_SHADE_HPP_ */
