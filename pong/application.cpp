#include "pong/application.hpp"

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

namespace pong {

void Application::changeState(State* state) {
    this->currentState->hide();
}

void Application::exit() {
    exit(0);
}

void Application::exit(int errorCode) {
    this->errorCode = errorCode;
    running = false;
}

int Application::run() {
    create();

    clock.restart();
    while (running) {
        update();
    }

    destroy();
    return errorCode;
}

void Application::create() {
    createWindow();
}

void Application::destroy() {
}

void Application::update() {
    clock.restart();

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

    window.display();
}

void Application::createWindow() {
    window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
}

} /* namespace pong */
