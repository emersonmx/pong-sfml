#ifndef PONG_FACTORY_HPP
#define PONG_FACTORY_HPP

#include <SFML/Graphics.hpp>

namespace pong {

class DefaultGameObjectFactory {
    public:
        DefaultGameObjectFactory() {}
        virtual ~DefaultGameObjectFactory() {}

        sf::RectangleShape makeRectangle(const sf::Vector2f& size);
        sf::RectangleShape makePaddle();
        sf::RectangleShape makeBall();
        sf::RectangleShape makeMidfieldPart();
        sf::RectangleShape makeWall();

        sf::Text makeScoreText(const sf::Font& font, const sf::String& text);
        sf::Text makePlayerOneScoreText(const sf::Font& font, const sf::String& text); 
        sf::Text makePlayerTwoScoreText(const sf::Font& font, const sf::String& text);
};

} /* namespace pong */ 
#endif /* PONG_FACTORY_HPP */
