// Debug draw for Box2D 2.2.1 - 2.3.0 for SFML 2.0 - SFMLDebugDraw.cpp
// Copyright (C) 2013  Matija Lovrekovic
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "MXG/SFMLDebugDraw.hpp"

#include <cmath>

namespace mxg {

SFMLDebugDraw::SFMLDebugDraw(sf::RenderWindow &window, float scale)
    : window_(&window), scale_(scale) {}

sf::Color SFMLDebugDraw::GLColorToSFML(const b2Color& color, sf::Uint8 alpha) {
    return sf::Color(static_cast<sf::Uint8>(color.r * 255),
                     static_cast<sf::Uint8>(color.g * 255),
                     static_cast<sf::Uint8>(color.b * 255), alpha);
}

sf::Vector2f SFMLDebugDraw::B2VecToSFVec(const b2Vec2& vector, bool scaleToPixels) {
    return sf::Vector2f(vector.x * (scaleToPixels ? scale_: 1.f),
                        vector.y * (scaleToPixels ? scale_ : 1.f));
}

void SFMLDebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
	sf::ConvexShape polygon(vertexCount);
	sf::Vector2f center;
	for(int i = 0; i < vertexCount; i++) {
		//polygon.setPoint(i, SFMLDraw::B2VecToSFVec(vertices[i]));
		sf::Vector2f transformedVec = SFMLDebugDraw::B2VecToSFVec(vertices[i]);
		polygon.setPoint(i, sf::Vector2f(std::floor(transformedVec.x), std::floor(transformedVec.y))); // flooring the coords to fix distorted lines on flat surfaces
	}																								   // they still show up though.. but less frequently
	polygon.setOutlineThickness(-1.f);
	polygon.setFillColor(sf::Color::Transparent);
	polygon.setOutlineColor(SFMLDebugDraw::GLColorToSFML(color));

	window_->draw(polygon);
}

void SFMLDebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
	sf::ConvexShape polygon(vertexCount);
	for(int i = 0; i < vertexCount; i++) {
		//polygon.setPoint(i, SFMLDraw::B2VecToSFVec(vertices[i]));
		sf::Vector2f transformedVec = SFMLDebugDraw::B2VecToSFVec(vertices[i]);
		polygon.setPoint(i, sf::Vector2f(std::floor(transformedVec.x), std::floor(transformedVec.y))); // flooring the coords to fix distorted lines on flat surfaces
	}																								   // they still show up though.. but less frequently
	polygon.setOutlineThickness(-1.f);
	polygon.setFillColor(SFMLDebugDraw::GLColorToSFML(color, 60));
	polygon.setOutlineColor(SFMLDebugDraw::GLColorToSFML(color));

	window_->draw(polygon);
}

void SFMLDebugDraw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) {
	sf::CircleShape circle(radius * scale_);
	circle.setOrigin(radius * scale_, radius * scale_);
	circle.setPosition(SFMLDebugDraw::B2VecToSFVec(center));
	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineThickness(-1.f);
	circle.setOutlineColor(SFMLDebugDraw::GLColorToSFML(color));

	window_->draw(circle);
}

void SFMLDebugDraw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) {
	sf::CircleShape circle(radius * scale_);
	circle.setOrigin(radius * scale_, radius * scale_);
	circle.setPosition(SFMLDebugDraw::B2VecToSFVec(center));
	circle.setFillColor(SFMLDebugDraw::GLColorToSFML(color, 60));
	circle.setOutlineThickness(1.f);
	circle.setOutlineColor(SFMLDebugDraw::GLColorToSFML(color));

	b2Vec2 endPoint = center + radius * axis;
	sf::Vertex line[2] = {
		sf::Vertex(SFMLDebugDraw::B2VecToSFVec(center), SFMLDebugDraw::GLColorToSFML(color)),
		sf::Vertex(SFMLDebugDraw::B2VecToSFVec(endPoint), SFMLDebugDraw::GLColorToSFML(color)),
	};

	window_->draw(circle);
	window_->draw(line, 2, sf::Lines);
}

void SFMLDebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) {
	sf::Vertex line[] = {
		sf::Vertex(SFMLDebugDraw::B2VecToSFVec(p1), SFMLDebugDraw::GLColorToSFML(color)),
		sf::Vertex(SFMLDebugDraw::B2VecToSFVec(p2), SFMLDebugDraw::GLColorToSFML(color))
	};

	window_->draw(line, 2, sf::Lines);
}

void SFMLDebugDraw::DrawTransform(const b2Transform& xf) {
	float lineLength = 0.4;

	/*b2Vec2 xAxis(b2Vec2(xf.p.x + (lineLength * xf.q.c), xf.p.y + (lineLength * xf.q.s)));*/
	b2Vec2 xAxis = xf.p + lineLength * xf.q.GetXAxis();
	sf::Vertex redLine[] = {
		sf::Vertex(SFMLDebugDraw::B2VecToSFVec(xf.p), sf::Color::Red),
		sf::Vertex(SFMLDebugDraw::B2VecToSFVec(xAxis), sf::Color::Red)
	};

	// You might notice that the ordinate(Y axis) points downward unlike the one in Box2D testbed
	// That's because the ordinate in SFML coordinate system points downward while the OpenGL(testbed) points upward
	/*b2Vec2 yAxis(b2Vec2(xf.p.x + (lineLength * -xf.q.s), xf.p.y + (lineLength * xf.q.c)));*/
	b2Vec2 yAxis = xf.p + lineLength * xf.q.GetYAxis();
	sf::Vertex greenLine[] = {
		sf::Vertex(SFMLDebugDraw::B2VecToSFVec(xf.p), sf::Color::Green),
		sf::Vertex(SFMLDebugDraw::B2VecToSFVec(yAxis), sf::Color::Green)
	};

	window_->draw(redLine, 2, sf::Lines);
	window_->draw(greenLine, 2, sf::Lines);
}

} /* namespace mxg */
