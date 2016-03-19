#include "pong/debug_draw.hpp"

#include <iostream>

#include "pong/defs.hpp"

using namespace std;

namespace pong {

void DebugDraw::setup(sf::RenderTarget* renderTarget) {
    renderTarget_ = renderTarget;
    SetFlags(e_shapeBit | e_centerOfMassBit | e_aabbBit | e_jointBit | e_pairBit);
}

void DebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
    cout << "DrawPolygon\n";
    sf::Color polygonColor = sf::Color::White;
    sf::VertexArray vertexArray(sf::LinesStrip, vertexCount);

    b2Vec2 vertex;
    for (int i = 0; i < vertexCount; i++) { 
        vertex = vertices[i];
        vertexArray[i].position = sf::Vector2f(vertex.x, vertex.y);
        vertexArray[i].color = polygonColor;
    }

    renderTarget_->draw(vertexArray);
}

void DebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
    cout << "DrawSolidPolygon\n";
    sf::Color polygonColor = sf::Color::Red;
    sf::VertexArray vertexArray(sf::Quads, vertexCount);

    b2Vec2 vertex;
    for (int i = 0; i < vertexCount; i++) { 
        vertex = vertices[i];
        vertexArray[i].position = sf::Vector2f(vertex.x, vertex.y);
        vertexArray[i].color = polygonColor;
    }

    renderTarget_->draw(vertexArray);
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
