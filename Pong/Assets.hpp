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
        sf::Texture& logoTexture() { return logoTexture_; }

        void loadAssets();

    protected:
        virtual std::unique_ptr<sf::Font> loadDefaultFont();
        virtual void loadLogoTexture();

    private:
        std::unique_ptr<sf::Font> defaultFont_;
        sf::Texture logoTexture_;
};

} /* namespace pong */
#endif /* PONG_ASSETS_HPP_ */
