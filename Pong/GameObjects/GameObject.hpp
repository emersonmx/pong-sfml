#ifndef PONG_GAMEOBJECTS_GAMEOBJECT_HPP_
#define PONG_GAMEOBJECTS_GAMEOBJECT_HPP_

#include <SFML/Graphics/Drawable.hpp>

namespace pong {

class GameObject : public sf::Drawable {
    public:
        virtual ~GameObject() {}

        virtual void create() {}
        virtual void destroy() {}

        virtual void update() {}

        bool visible = true;

    protected:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override {}
};

} /* namespace pong */
#endif /* PONG_GAMEOBJECTS_GAMEOBJECT_HPP_ */
