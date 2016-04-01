#ifndef MXG_SCREEN_HPP_
#define MXG_SCREEN_HPP_

#include <SFML/Graphics.hpp>

namespace mxg {

class Screen {
    public:
        virtual ~Screen() {}

        virtual void enter() = 0;
        virtual void exit() = 0;

        virtual void processEvent(const sf::Event& event) = 0;
        virtual void update() = 0;
        virtual void render(sf::RenderTarget& renderTarget) = 0;
};

} /* namespace mxg */
#endif /* MXG_SCREEN_HPP_ */
