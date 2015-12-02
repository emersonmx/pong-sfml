#include "pong/factory.hpp"

#include "pong/defs.hpp"

using namespace sf;

namespace pong {

RectangleShape DefaultGameObjectFactory::makeRectangle(const Vector2f& size) {
    RectangleShape shape;
    shape.setSize(size);
    shape.setFillColor(Color::White);
    return shape;
}

RectangleShape DefaultGameObjectFactory::makePaddle() {
    return makeRectangle(Vector2f(20, 80));
}

RectangleShape DefaultGameObjectFactory::makePlayerOnePaddle() {
    RectangleShape shape = makePaddle();
    auto rect = shape.getLocalBounds();
    shape.setOrigin(0, rect.height / 2);
    shape.setPosition(Vector2f(10, WINDOW_HEIGHT/ 2));
    return shape;
}

RectangleShape DefaultGameObjectFactory::makePlayerTwoPaddle() {
    RectangleShape shape = makePaddle();
    auto rect = shape.getLocalBounds();
    shape.setOrigin(rect.width, rect.height / 2);
    shape.setPosition(Vector2f(WINDOW_WIDTH - 10, WINDOW_HEIGHT / 2));
    return shape;
}

RectangleShape DefaultGameObjectFactory::makeBall() {
    RectangleShape shape = makeRectangle(Vector2f(10, 10));
    auto rect = shape.getLocalBounds();
    shape.setOrigin(rect.width / 2, rect.height / 2);
    shape.setPosition(Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
    return shape;
}

RectangleShape DefaultGameObjectFactory::makeMidfieldPart() {
    RectangleShape shape = makeRectangle(Vector2f(2, WINDOW_HEIGHT));
    auto rect = shape.getLocalBounds();
    shape.setOrigin(rect.width / 2, 0);
    shape.setPosition(Vector2f(WINDOW_WIDTH / 2, 0));
    return shape;
}

RectangleShape DefaultGameObjectFactory::makeWall() {
    return makeRectangle(Vector2f(WINDOW_WIDTH, 10));
}

RectangleShape DefaultGameObjectFactory::makeTopWall() {
    return makeWall();
}

RectangleShape DefaultGameObjectFactory::makeBottomWall() {
    RectangleShape shape = makeWall();
    auto rect = shape.getLocalBounds();
    shape.setOrigin(0, rect.height);
    shape.setPosition(Vector2f(0, WINDOW_HEIGHT));
    return shape;
}

Text DefaultGameObjectFactory::makeScoreText(const sf::String& text) {
    Text textObject;
    textObject.setFont(defaultFont);
    textObject.setCharacterSize(SCORE_FONT_SIZE);
    textObject.setColor(Color::White);
    textObject.setString(text);
    return textObject;
}

Text DefaultGameObjectFactory::makePlayerOneScoreText(const String& text) {
    Text textObject = makeScoreText(text);
    auto rect = textObject.getLocalBounds();
    textObject.setOrigin(rect.left + rect.width, 0);
    textObject.setPosition(Vector2f(WINDOW_WIDTH / 2 - 25, 30));
    return textObject;
}

Text DefaultGameObjectFactory::makePlayerTwoScoreText(const String& text) {
    Text textObject = makeScoreText(text);
    auto rect = textObject.getLocalBounds();
    textObject.setOrigin(rect.left, 0);
    textObject.setPosition(Vector2f(WINDOW_WIDTH / 2 + 25, 30));
    return textObject;
}

} /* GameObjectFactory::namespace pong */
