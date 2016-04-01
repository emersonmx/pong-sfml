#include "pong/Factories.hpp"

#include "pong/Defs.hpp"

using namespace sf;

namespace pong {

RectangleShape GameShapeFactory::makeRectangle(const Vector2f& size) {
    RectangleShape shape;
    shape.setOrigin(size.x / 2.0f, size.y / 2.0f);
    shape.setSize(size);
    shape.setFillColor(Color::White);
    return shape;
}

RectangleShape GameShapeFactory::makeRaquet() {
    return makeRectangle(Vector2f(RAQUET_WIDTH, RAQUET_HEIGHT));
}

RectangleShape GameShapeFactory::makeWall() {
    return makeRectangle(Vector2f(WALL_WIDTH, WALL_HEIGHT));
}

RectangleShape GameShapeFactory::makeLeftRaquet() {
    return makeRaquet();
}

RectangleShape GameShapeFactory::makeRightRaquet() {
    return makeRaquet();
}

RectangleShape GameShapeFactory::makeBall() {
    return makeRectangle(Vector2f(BALL_WIDTH, BALL_HEIGHT));
}

RectangleShape GameShapeFactory::makeMidfield() {
    sf::RectangleShape shape = makeRectangle(Vector2f(2, WINDOW_HEIGHT));
    shape.setPosition(WINDOW_HALF_WIDHT, WINDOW_HALF_HEIGHT);
    return shape;
}

RectangleShape GameShapeFactory::makeTopWall() {
    return makeWall();
}

RectangleShape GameShapeFactory::makeBottomWall() {
    return makeWall();
}

} /* GameObjectFactory::namespace pong */
