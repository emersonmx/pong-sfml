#include "Pong/Assets.hpp"

#include <iostream>

#include "Pong/Defs.hpp"

namespace pong {

void Assets::loadAssets() {
    defaultFont_ = loadDefaultFont();
    loadLogoTexture();
}

std::unique_ptr<sf::Font> Assets::loadDefaultFont() {
    std::unique_ptr<sf::Font> font(new sf::Font());
    std::string fileName = ASSETS_PATH + "Square.ttf";
    if (!font->loadFromFile(fileName)) {
        std::cout << "Unable to load font \"" << fileName << "\"." << std::endl;
    }
    return font;
}

void Assets::loadLogoTexture() {
    std::string fileName = ASSETS_PATH + "logo.png";
    if (!logoTexture_.loadFromFile(fileName)) {
        std::cout << "Unable to load texture \"" << fileName << "\"." << std::endl;
        return;
    }
    logoTexture_.setSmooth(true);
}

} /* namespace pong */
