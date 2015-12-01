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
    window.display();
}

void Application::setupConfig() {
    config.windowTitle = L"Pong";
    config.windowWidth = 640;
    config.windowHeight = 480;
}

void Application::setupWindow() {
    window.create(VideoMode(config.windowWidth, config.windowHeight),
        config.windowTitle);
} 

} /* namespace pong */
