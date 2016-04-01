#ifndef PONG_FACTORY_GAMESHAPEFACTORY_HPP_
#define PONG_FACTORY_GAMESHAPEFACTORY_HPP_

#include <SFML/Graphics.hpp>

namespace pong {

class GameShapeFactory {
    public:
        GameShapeFactory() {}
        virtual ~GameShapeFactory() {}

        virtual sf::RectangleShape makeLeftRaquet();
        virtual sf::RectangleShape makeRightRaquet();
        virtual sf::RectangleShape makeBall();
        virtual sf::RectangleShape makeMidfield();
        virtual sf::RectangleShape makeTopWall();
        virtual sf::RectangleShape makeBottomWall();

    private:
        sf::RectangleShape makeRectangle(const sf::Vector2f& size);
        sf::RectangleShape makeRaquet();
        sf::RectangleShape makeWall();

        sf::Font defaultFont;
};

} /* namespace pong */
#endif /* PONG_FACTORY_GAMESHAPEFACTORY_HPP_ */
