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

RectangleShape DefaultGameObjectFactory::makeBall() {
    return makeRectangle(Vector2f(10, 10));
}

RectangleShape DefaultGameObjectFactory::makeMidfieldPart() {
    return makeRectangle(Vector2f(2, WINDOW_HEIGHT));
}

RectangleShape DefaultGameObjectFactory::makeWall() {
    return makeRectangle(Vector2f(WINDOW_WIDTH, 10));
}

Text DefaultGameObjectFactory::makeScoreText(const sf::Font& font, const sf::String& text) {
    Text textObject;
    textObject.setFont(font);
    textObject.setCharacterSize(SCORE_FONT_SIZE);
    textObject.setColor(Color::White);
    textObject.setString(text); 
    return textObject;
} 

Text DefaultGameObjectFactory::makePlayerOneScoreText(const Font& font, 
        const String& text) {
    Text textObject = makeScoreText(font, text);
    FloatRect rect = textObject.getLocalBounds();
    textObject.setOrigin(rect.left + rect.width, 0);
    return textObject;
}

Text DefaultGameObjectFactory::makePlayerTwoScoreText(const Font& font,
        const String& text) {
    Text textObject = makeScoreText(font, text);
    FloatRect rect = textObject.getLocalBounds();
    textObject.setOrigin(rect.left, 0);
    return textObject;
}

} /* GameObjectFactory::namespace pong */ 
