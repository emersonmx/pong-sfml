#include "pong/application.hpp"

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "pong/config.hpp"

using namespace std;
using namespace sf;

namespace pong {

void Application::exit(int errorCode) {
    this->errorCode = errorCode;
    window.close();
}

int Application::run() {
    create();

    while (window.isOpen()) {
        update();
    }

    destroy();
    return errorCode;
}

void Application::create() {
    setupConfig();
    setupWindow();
    setupShapes();
    setupFonts();
}

void Application::destroy() {
}

void Application::update() {
    handleInput();
    processLogic();
    draw();
}

void Application::handleInput() {
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            exit(true);
        }
    }
}

void Application::processLogic() {
}

void Application::draw() {
    window.clear(Color::Black);

    window.draw(midfieldPartShape);
    window.draw(topWallShape);
    window.draw(bottomWallShape);

    window.draw(playerOneScoreText);
    window.draw(playerTwoScoreText);

    window.draw(playerOneShape);
    window.draw(playerTwoShape);

    window.draw(ballShape);

    window.display();
}

void Application::setupConfig() {
    config.windowTitle = L"Pong";
    config.windowWidth = 640;
    config.windowHeight = 480;
    config.scoreFontSize = 42;
}

void Application::setupWindow() {
    window.create(VideoMode(config.windowWidth, config.windowHeight),
        config.windowTitle);
} 

void Application::setupShapes() {
    Vector2f wallSize(config.windowWidth, 10);

    topWallShape.setSize(wallSize);
    topWallShape.setFillColor(Color::White);
    topWallShape.setPosition(Vector2f(0, 0));

    bottomWallShape.setSize(wallSize);
    bottomWallShape.setFillColor(Color::White);
    bottomWallShape.setPosition(Vector2f(0, config.windowHeight - wallSize.y));

    Vector2f midfieldPartSize (2, config.windowHeight);
    midfieldPartShape.setSize(midfieldPartSize);
    midfieldPartShape.setFillColor(Color::White);
    midfieldPartShape.setPosition(Vector2f(config.windowWidth / 2 - midfieldPartSize.x / 2,
        0));

    Vector2f paddleSize(20, 80);

    playerOneShape.setSize(paddleSize);
    playerOneShape.setFillColor(Color::White);
    playerOneShape.setPosition(Vector2f(10, config.windowHeight / 2 - paddleSize.y / 2));

    playerTwoShape.setSize(paddleSize);
    playerTwoShape.setFillColor(Color::White);
    playerTwoShape.setPosition(Vector2f(config.windowWidth - paddleSize.x - 10,
        config.windowHeight / 2 - paddleSize.y / 2)); 

    Vector2f ballSize(10, 10);
    ballShape.setSize(ballSize);
    ballShape.setFillColor(Color::White);
    ballShape.setPosition(Vector2f(config.windowWidth / 2 - ballSize.x / 2,
        config.windowHeight / 2 - ballSize.y / 2));
}

void Application::setupFonts() {
    if (!sansFont.loadFromFile("assets/DejaVuSans.ttf")) {
        cout << "Não foi possível carregar a fonte.\n";
        exit(1);
    }

    playerOneScore = 0;
    playerOneScoreText.setFont(sansFont);
    playerOneScoreText.setCharacterSize(config.scoreFontSize);
    playerOneScoreText.setColor(Color::White);
    playerOneScoreText.setString(to_string(playerOneScore)); 
    FloatRect playerOneRect = playerOneScoreText.getLocalBounds();
    playerOneScoreText.setOrigin(playerOneRect.left + playerOneRect.width, 0);
    playerOneScoreText.setPosition(Vector2f(config.windowWidth / 2 - 25, 30));

    playerTwoScore = 0;
    playerTwoScoreText.setFont(sansFont);
    playerTwoScoreText.setCharacterSize(config.scoreFontSize);
    playerTwoScoreText.setColor(Color::White);
    playerTwoScoreText.setString(to_string(playerTwoScore)); 
    FloatRect playerTwoRect = playerTwoScoreText.getLocalBounds();
    playerTwoScoreText.setOrigin(playerTwoRect.left, 0);
    playerTwoScoreText.setPosition(Vector2f(config.windowWidth / 2 + 25, 30));
}

} /* namespace pong */
