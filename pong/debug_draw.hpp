#ifndef PONG_DEBUG_DRAW_HPP
#define PONG_DEBUG_DRAW_HPP

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

namespace pong {

class DebugDraw: public b2Draw {
    public:
        ;
        void setup(sf::RenderTarget* renderTarget);

        virtual void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
        virtual void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
        virtual void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
        virtual void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
        virtual void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
        virtual void DrawTransform(const b2Transform& xf);

    private:
        sf::RenderTarget* renderTarget_;
};

} /* namespace pong */
#endif /* PONG_DEBUG_DRAW_HPP */
