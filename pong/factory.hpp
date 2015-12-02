#ifndef PONG_FACTORY_HPP
#define PONG_FACTORY_HPP

#include <SFML/Graphics.hpp>

namespace pong {

class GameObjectFactory {
    public:
        virtual ~GameObjectFactory() {}

        virtual sf::RectangleShape makePlayerOnePaddle() = 0;
        virtual sf::RectangleShape makePlayerTwoPaddle() = 0;
        virtual sf::RectangleShape makeBall() = 0;
        virtual sf::RectangleShape makeMidfieldPart() = 0;
        virtual sf::RectangleShape makeTopWall() = 0;
        virtual sf::RectangleShape makeBottomWall() = 0;

        virtual sf::Text makePlayerOneScoreText(const sf::String& text) = 0;
        virtual sf::Text makePlayerTwoScoreText(const sf::String& text) = 0;
};

class DefaultGameObjectFactory : public GameObjectFactory {
    public:
        DefaultGameObjectFactory() {}
        virtual ~DefaultGameObjectFactory() {}

        sf::Font getDefaultFont() { return defaultFont; }
        void setDefaultFont(const sf::Font font) { defaultFont = font; }

        sf::RectangleShape makeRectangle(const sf::Vector2f& size);
        sf::RectangleShape makePaddle();
        virtual sf::RectangleShape makePlayerOnePaddle();
        virtual sf::RectangleShape makePlayerTwoPaddle();
        virtual sf::RectangleShape makeBall();
        virtual sf::RectangleShape makeMidfieldPart();
        sf::RectangleShape makeWall();
        virtual sf::RectangleShape makeTopWall();
        virtual sf::RectangleShape makeBottomWall();

        sf::Text makeScoreText(const sf::String& text);
        virtual sf::Text makePlayerOneScoreText(const sf::String& text);
        virtual sf::Text makePlayerTwoScoreText(const sf::String& text);

    private:
        sf::Font defaultFont;
};

} /* namespace pong */
#endif /* PONG_FACTORY_HPP */
