#include "pong/application.hpp"

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

namespace pong {

void Application::exit() {
    exit(0);
}

void Application::exit(int errorCode) {
    this->errorCode = errorCode;
    running = false;
}

int Application::run() {
    create();

    while (running) {
        update();
    }

    destroy();
    return errorCode;
}

void Application::create() {
    createWindow();
    loadAssets();
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
            exit();
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

void Application::createWindow() {
    window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
}

void Application::loadAssets() {
    if (!sansFont.loadFromFile("assets/DejaVuSans.ttf")) {
        cout << "Não foi possível carregar a fonte.\n";
        exit(1);
    }

    gameObjectFactory.setDefaultFont(sansFont);
}

void Application::setupShapes() {
    topWallShape = gameObjectFactory.makeTopWall();
    bottomWallShape = gameObjectFactory.makeBottomWall();

    midfieldPartShape = gameObjectFactory.makeMidfieldPart();

    playerOneShape = gameObjectFactory.makePlayerOnePaddle();
    playerTwoShape = gameObjectFactory.makePlayerTwoPaddle();

    ballShape = gameObjectFactory.makeBall();
}

void Application::setupFonts() {
    playerOneScore = 0;
    playerOneScoreText = gameObjectFactory.makePlayerOneScoreText(to_string(playerOneScore));

    playerTwoScore = 0;
    playerTwoScoreText = gameObjectFactory.makePlayerTwoScoreText(to_string(playerTwoScore));
}

} /* namespace pong */
