#ifndef PONG_GAMEOBJECTS_SCOREBOARD_HPP_
#define PONG_GAMEOBJECTS_SCOREBOARD_HPP_

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Pong/GameObjects/GameObject.hpp"
#include "Pong/GameWorld.hpp"

namespace pong {

class ScoreBoard : public GameObject, public GameWorld::ScoreListener {
    public:
        ScoreBoard(sf::Font* font) : font_(font) {}

        virtual void create();

        virtual void update();

        void show();
        void hide();

        virtual void leftScored(GameWorld& gameWorld);
        virtual void rightScored(GameWorld& gameWorld);

    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        void updateLeftScoreText();
        void updateRightScoreText();

        sf::Font* font_;

        sf::Text leftScoreText_;
        sf::Text rightScoreText_;

        sf::Clock clock_;
        bool delay_;

        int leftScore_ = 0;
        int rightScore_ = 0;
        bool visibility_;
};

} /* namespace pong */
#endif /* PONG_GAMEOBJECTS_SCOREBOARD_HPP_ */
