#ifndef PONG_UI_SHADE_HPP_
#define PONG_UI_SHADE_HPP_

#include <SFML/Graphics.hpp>

namespace pong {

class Shade : public sf::Transformable, public sf::Drawable {
    public:
        virtual ~Shade() {}

        void show() { visible_ = true; }
        void hide() { visible_ = false; }

        const sf::Vector2f& size() const { return shade_.getSize(); }
        void setSize(const sf::Vector2f& size) { shade_.setSize(size); }
        const sf::Color& fillColor() const { return shade_.getFillColor(); }
        void setFillColor(const sf::Color& color) { shade_.setFillColor(color); }
        const sf::Color& outlineColor() const { return shade_.getOutlineColor(); }
        void setOutlineColor(const sf::Color& color) { shade_.setOutlineColor(color); }
        float outlineThickness() const { return shade_.getOutlineThickness(); }
        void setOutlineThickness(float thickness) { shade_.setOutlineThickness(thickness); }
        const sf::Texture* texture() const { return shade_.getTexture(); }
        void setTexture(const sf::Texture* texture, bool resetRect = false) {
            shade_.setTexture(texture, resetRect);
        }

    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;

    private:
        bool visible_ = true;
        sf::RectangleShape shade_;
};

} /* namespace pong */
#endif /* PONG_UI_SHADE_HPP_ */
