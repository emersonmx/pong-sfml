#include "MXG/SFMLDebugDraw.hpp"

#include <cmath>

namespace mxg {

SFMLDebugDraw::SFMLDebugDraw(sf::RenderWindow &window, float scale)
        : window_(&window), scale_(scale) {

    sf::Transform transform;
    transform.scale(scale, scale);
    states_.transform = transform;
}

sf::Color SFMLDebugDraw::glColorToSfColor(const b2Color& color, sf::Uint8 alpha) {
    return sf::Color(static_cast<sf::Uint8>(color.r * 255),
                     static_cast<sf::Uint8>(color.g * 255),
                     static_cast<sf::Uint8>(color.b * 255), alpha);
}

sf::Vector2f SFMLDebugDraw::b2VecToSfVector(const b2Vec2& vector) {
    return sf::Vector2f(vector.x, vector.y);
}

void SFMLDebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
	sf::ConvexShape polygon(vertexCount);
	sf::Vector2f center;
	for(int i = 0; i < vertexCount; i++) {
		sf::Vector2f transformedVec = b2VecToSfVector(vertices[i]);
		polygon.setPoint(i, sf::Vector2f(transformedVec.x, transformedVec.y));
	}
	polygon.setOutlineThickness(-1.f / scale_);
	polygon.setFillColor(sf::Color::Transparent);
	polygon.setOutlineColor(glColorToSfColor(color));

	window_->draw(polygon, states_);
}

void SFMLDebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
	sf::ConvexShape polygon(vertexCount);
	for(int i = 0; i < vertexCount; i++) {
		sf::Vector2f transformedVec = b2VecToSfVector(vertices[i]);
		polygon.setPoint(i, sf::Vector2f(transformedVec.x, transformedVec.y));
	}

    polygon.setOutlineThickness(1 / scale_);
	polygon.setFillColor(glColorToSfColor(color, 60));
    polygon.setOutlineColor(glColorToSfColor(color));

	window_->draw(polygon, states_);
}

void SFMLDebugDraw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) {
	sf::CircleShape circle(radius);
	circle.setOrigin(radius, radius);
	circle.setPosition(b2VecToSfVector(center));
	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineThickness(-1.f / scale_);
	circle.setOutlineColor(glColorToSfColor(color));

	window_->draw(circle, states_);
}

void SFMLDebugDraw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) {
	sf::CircleShape circle(radius);
	circle.setOrigin(radius, radius);
	circle.setPosition(b2VecToSfVector(center));
	circle.setFillColor(glColorToSfColor(color, 60));
	circle.setOutlineThickness(1.f / scale_);
	circle.setOutlineColor(glColorToSfColor(color));

	b2Vec2 endPoint = center + radius * axis;
    sf::VertexArray line(sf::Lines, 2);
    line.append(sf::Vertex(b2VecToSfVector(center), glColorToSfColor(color)));
    line.append(sf::Vertex(b2VecToSfVector(endPoint), glColorToSfColor(color)));

	window_->draw(circle, states_);
	window_->draw(line, states_);
}

void SFMLDebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) {
    sf::VertexArray line(sf::Lines, 2);
    line.append(sf::Vertex(b2VecToSfVector(p1), glColorToSfColor(color)));
	line.append(sf::Vertex(b2VecToSfVector(p2), glColorToSfColor(color)));

	window_->draw(line, states_);
}

void SFMLDebugDraw::DrawTransform(const b2Transform& xf) {
	float lineLength = 0.4;

	b2Vec2 xAxis = xf.p + lineLength * xf.q.GetXAxis();
    sf::VertexArray redLine(sf::Lines, 2);
    redLine.append(sf::Vertex(b2VecToSfVector(xf.p), sf::Color::Red));
    redLine.append(sf::Vertex(b2VecToSfVector(xAxis), sf::Color::Red));

	b2Vec2 yAxis = xf.p + lineLength * xf.q.GetYAxis();

    sf::VertexArray greenLine(sf::Lines, 2);
    greenLine.append(sf::Vertex(b2VecToSfVector(xf.p), sf::Color::Green));
    greenLine.append(sf::Vertex(b2VecToSfVector(yAxis), sf::Color::Green));

	window_->draw(redLine, states_);
	window_->draw(greenLine, states_);
}

} /* namespace mxg */
