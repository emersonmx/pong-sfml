#include "pong/application.hpp"

#include <iostream>

using namespace std;

namespace pong {

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
}

void Application::destroy() {
} 

void Application::update() {
    handleInput();
    processLogic();
    draw();
}

void Application::handleInput() {
}

void Application::processLogic() {
}

void Application::draw() {
} 

} /* namespace pong */ 
