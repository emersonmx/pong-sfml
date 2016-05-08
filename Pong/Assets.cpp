#include "Pong/Assets.hpp"

#include <iostream>

#include "Pong/Defs.hpp"

namespace pong {

void Assets::loadAssets() {
    defaultFont_ = loadDefaultFont();
    logo_ = loadLogoTexture();
}

std::unique_ptr<sf::Font> Assets::loadDefaultFont() {
    std::unique_ptr<sf::Font> font(new sf::Font());
    std::string fileName = ASSETS_PATH + "Square.ttf";
    if (!font->loadFromFile(fileName)) {
        std::cout << "Unable to load font \"" << fileName << "\"." << std::endl;
    }
    return font;
}

std::unique_ptr<sf::Texture> Assets::loadLogoTexture() {
    std::unique_ptr<sf::Texture> texture(new sf::Texture());
    std::string fileName = ASSETS_PATH + "logo.png";
    if (!texture->loadFromFile(fileName)) {
        std::cout << "Unable to load texture \"" << fileName << "\"." << std::endl;
    }
    return texture;
}

} /* namespace pong */
