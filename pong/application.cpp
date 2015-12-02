#include "pong/application.hpp"

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

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

void Application::setupWindow() {
    window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
} 

void Application::setupShapes() {
    topWallShape = factory.makeWall(); 
    auto wallRect = topWallShape.getLocalBounds();
    topWallShape.setPosition(Vector2f(0, 0));
    bottomWallShape = factory.makeWall();
    bottomWallShape.setOrigin(0, wallRect.height);
    bottomWallShape.setPosition(Vector2f(0, WINDOW_HEIGHT));

    midfieldPartShape = factory.makeMidfieldPart();
    auto midfieldPartRect = midfieldPartShape.getLocalBounds();
    midfieldPartShape.setOrigin(midfieldPartRect.width / 2, 0);
    midfieldPartShape.setPosition(Vector2f(WINDOW_WIDTH / 2, 0)); 

    int paddleOffset = 10;
    playerOneShape = factory.makePaddle();
    auto paddleRect = playerOneShape.getLocalBounds();
    playerOneShape.setOrigin(0, paddleRect.height / 2);
    playerOneShape.setPosition(Vector2f(paddleOffset, WINDOW_HEIGHT/ 2)); 
    playerTwoShape = factory.makePaddle();
    playerTwoShape.setOrigin(paddleRect.width, paddleRect.height / 2);
    playerTwoShape.setPosition(Vector2f(WINDOW_WIDTH - paddleOffset,
        WINDOW_HEIGHT / 2)); 

    ballShape = factory.makeBall();
    auto ballRect = ballShape.getLocalBounds();
    ballShape.setOrigin(ballRect.width / 2, ballRect.height / 2);
    ballShape.setPosition(Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2));
}

void Application::setupFonts() {
    if (!sansFont.loadFromFile("assets/DejaVuSans.ttf")) {
        cout << "Não foi possível carregar a fonte.\n";
        exit(1);
    }

    int scoreTextOffset = 25;
    playerOneScore = 0;
    playerOneScoreText = factory.makePlayerOneScoreText(sansFont,
        to_string(playerOneScore));
    playerOneScoreText.setPosition(Vector2f(WINDOW_WIDTH / 2 - scoreTextOffset, 30));

    playerTwoScore = 0;
    playerTwoScoreText = factory.makePlayerTwoScoreText(sansFont,
        to_string(playerTwoScore));
    playerTwoScoreText.setPosition(Vector2f(WINDOW_WIDTH / 2 + scoreTextOffset, 30));
}

} /* namespace pong */
