#ifndef PONG_UI_SCOREBOARD_HPP_
#define PONG_UI_SCOREBOARD_HPP_

#include <SFML/Graphics.hpp>

#include "Pong/GameWorld.hpp"

namespace pong {

class ScoreBoard : public sf::Transformable, public sf::Drawable, public GameWorld::ScoreListener {
    public:

        int leftScore() { return leftScore_; }
        int rightScore() { return rightScore_; }

        void create(const sf::Font* font);
        void resetScores() { leftScore_ = rightScore_ = 0; }

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        virtual void leftScored(GameWorld& gameWorld);
        virtual void rightScored(GameWorld& gameWorld);

    protected:
        virtual sf::RectangleShape createBackground();
        virtual sf::Text createLeftScoreText(const sf::Font* font);
        virtual sf::Text createRightScoreText(const sf::Font* font);

    private:
        void updateScores();

        sf::RectangleShape background_;
        sf::Text leftScoreText_;
        sf::Text rightScoreText_;

        int leftScore_ = 0;
        int rightScore_ = 0;
};

} /* namespace pong */
#endif /* PONG_UI_SCOREBOARD_HPP_ */
