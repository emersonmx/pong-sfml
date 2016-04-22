#ifndef PONG_ASSETS_HPP_
#define PONG_ASSETS_HPP_

#include <memory>

#include <SFML/Graphics/Font.hpp>

namespace pong {

class Assets {
    public:
        virtual ~Assets() {}

        sf::Font* defaultFont() { return defaultFont_.get(); }

        void loadAssets();

    protected:
        virtual std::unique_ptr<sf::Font> createDefaultFont();

    private:
        std::unique_ptr<sf::Font> defaultFont_;
};

} /* namespace pong */
#endif /* PONG_ASSETS_HPP_ */
