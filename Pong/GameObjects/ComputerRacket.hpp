#ifndef PONG_GAMEOBJECTS_COMPUTERRACKET_HPP_
#define PONG_GAMEOBJECTS_COMPUTERRACKET_HPP_

#include "Pong/GameObjects/Racket.hpp"

namespace pong {

class GameWorld;

class ComputerRacket : public Racket {
    public:
        ComputerRacket(b2Body* body, b2Body* ball) : Racket(body), ball_(ball) {}

        float xMaxDistance;
        float yMaxDistance;

    protected:
        virtual void handleInput();

        b2Body* ball_;
};

} /* namespace pong */
#endif /* PONG_GAMEOBJECTS_COMPUTERRACKET_HPP_ */
