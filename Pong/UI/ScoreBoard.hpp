#ifndef PONG_UI_SCOREBOARD_HPP_
#define PONG_UI_SCOREBOARD_HPP_

#include <SFML/Graphics.hpp>

#include "Pong/GameWorld.hpp"

namespace pong {

class ScoreBoard : public sf::Drawable, public GameWorld::ScoreListener {
    public:
        int leftScore() { return leftScore_; }
        int rightScore() { return rightScore_; }

        const sf::Vector2f& getPosition() const { return transformable_.getPosition(); }
        void setPosition(const sf::Vector2f& position) { transformable_.setPosition(position); }

        void create(const sf::Font* font);
        void resetScores() { leftScore_ = rightScore_ = 0; }

        void show() { visibility_ = true; }
        void hide() { visibility_ = false; }

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;

        virtual void leftScored(GameWorld& gameWorld);
        virtual void rightScored(GameWorld& gameWorld);

    protected:
        virtual sf::Text createLeftScoreText(const sf::Font* font);
        virtual sf::Text createRightScoreText(const sf::Font* font);
        virtual void updateLeftScoreText();
        virtual void updateRightScoreText();

    private:
        sf::Transformable transformable_;
        sf::Text leftScoreText_;
        sf::Text rightScoreText_;

        int leftScore_ = 0;
        int rightScore_ = 0;
        bool visibility_;
};

} /* namespace pong */
#endif /* PONG_UI_SCOREBOARD_HPP_ */
