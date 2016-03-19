#include "pong/debug_draw.hpp"

#include <iostream>

#include "pong/defs.hpp"

using namespace std;

namespace pong {

sf::Color convertColor(const b2Color& color) {
    return sf::Color(color.r, color.g, color.b, color.a);
}

void DebugDraw::setup(sf::RenderTarget* renderTarget) {
    renderTarget_ = renderTarget;
}

void DebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
    cout << "DrawPolygon\n";
}

void DebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
    cout << "DrawSolidPolygon\n";
}

void DebugDraw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) {
    cout << "DrawCircle\n";
}

void DebugDraw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) {
    cout << "DrawSolidCircle\n";
}

void DebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) {
    cout << "DrawSegment\n";
}

void DebugDraw::DrawTransform(const b2Transform& xf) {
    cout << "DrawTransform\n";
}

} /* namespace pong */
