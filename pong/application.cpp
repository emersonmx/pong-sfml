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
    window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
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

} /* namespace pong */ 
