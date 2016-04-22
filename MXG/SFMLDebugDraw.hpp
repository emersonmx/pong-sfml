#ifndef MXG_SFMLDEBUGDRAW_HPP_
#define MXG_SFMLDEBUGDRAW_HPP_

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

namespace mxg {

class SFMLDebugDraw : public b2Draw {
    public:
        SFMLDebugDraw(sf::RenderWindow& window, float scale);

        void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
        void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
        void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
        void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
        void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
        void DrawTransform(const b2Transform& xf);

    private:
        sf::Color glColorToSfColor(const b2Color& color, sf::Uint8 alpha = 255);
        sf::Vector2f b2VecToSfVector(const b2Vec2& vector);

        sf::RenderWindow* window_;
        sf::RenderStates states_ = sf::RenderStates::Default;
        float scale_;
};

} /* namespace mx */
#endif /* MXG_SFMLDEBUGDRAW_HPP_ */
