#ifndef PONG_ASSETS_HPP_
#define PONG_ASSETS_HPP_

#include <memory>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace pong {

class Assets {
    public:
        virtual ~Assets() {}

        sf::Font* defaultFont() { return defaultFont_.get(); }
        sf::Texture* logo() { return logo_.get(); }

        void loadAssets();

    protected:
        virtual std::unique_ptr<sf::Font> loadDefaultFont();
        virtual std::unique_ptr<sf::Texture> loadLogoTexture();

    private:
        std::unique_ptr<sf::Font> defaultFont_;
        std::unique_ptr<sf::Texture> logo_;
};

} /* namespace pong */
#endif /* PONG_ASSETS_HPP_ */
