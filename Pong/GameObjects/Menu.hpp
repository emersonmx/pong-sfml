#ifndef PONG_GAMEOBJECTS_MENU_HPP_
#define PONG_GAMEOBJECTS_MENU_HPP_

#include <vector>
#include <functional>

#include <SFML/Graphics/Text.hpp>

#include "Pong/GameObjects/GameObject.hpp"

namespace pong {

class Menu : public GameObject {
    public:
        using Options = std::vector<std::string>;

        Menu(const Options& options, const sf::Font& font, unsigned int characterSize, int spacing);

        void setPosition(sf::Vector2f position);
        int selected() { return selected_; }
        void setSelect(int index);

        void create() override;

        void next();
        void previous();

    protected:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        void updateTexts();
        void updateTextCenter(sf::Text& text);

        Options options_;
        const sf::Font& font_;
        unsigned int characterSize_;
        int spacing_;

        int selected_ = 0;

        std::vector<sf::Text> textArray_;
        sf::Transformable transformable_;
};

} /* namespace pong */
#endif /* PONG_GAMEOBJECTS_MENU_HPP_ */
