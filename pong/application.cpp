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

void Application::createWindow() {
    window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
}

void Application::loadAssets() {
    if (!sansFont.loadFromFile("assets/DejaVuSans.ttf")) {
        cout << "Não foi possível carregar a fonte.\n";
        exit(1);
    }

    factory.setDefaultFont(sansFont);
}

void Application::setupShapes() {
    topWallShape = factory.makeTopWall();
    bottomWallShape = factory.makeBottomWall();

    midfieldPartShape = factory.makeMidfieldPart();

    playerOneShape = factory.makePlayerOnePaddle();
    playerTwoShape = factory.makePlayerTwoPaddle();

    ballShape = factory.makeBall();
}

void Application::setupFonts() {
    playerOneScore = 0;
    playerOneScoreText = factory.makePlayerOneScoreText(to_string(playerOneScore));

    playerTwoScore = 0;
    playerTwoScoreText = factory.makePlayerTwoScoreText(to_string(playerTwoScore));
}

} /* namespace pong */
