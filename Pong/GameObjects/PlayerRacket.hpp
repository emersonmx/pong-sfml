#ifndef PONG_GAMEOBJECTS_PLAYERRACKET_HPP_
#define PONG_GAMEOBJECTS_PLAYERRACKET_HPP_

#include "Pong/GameObjects/Racket.hpp"

namespace pong {

class PlayerRacket : public Racket {
    public:
        using Racket::Racket;

    protected:
        void handleInput() override;
};

} /* namespace pong */
#endif /* PONG_GAMEOBJECTS_PLAYERRACKET_HPP_ */
