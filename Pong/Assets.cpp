#include "Pong/Assets.hpp"

#include <iostream>

#include "Pong/Defs.hpp"

namespace pong {

void Assets::loadAssets() {
    defaultFont_ = createDefaultFont();
}

std::unique_ptr<sf::Font> Assets::createDefaultFont() {
    std::unique_ptr<sf::Font> font(new sf::Font());
    std::string fileName = ASSETS_PATH + "Square.ttf";
    if (!font->loadFromFile(fileName)) {
        std::cout << "Unable to load font \"" << fileName << "\"." << std::endl;
    }
    return font;
}

} /* namespace pong */
