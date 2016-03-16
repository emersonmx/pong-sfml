#include "pong/application.hpp"

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

namespace pong {

void Application::changeState(State* state) {
    if (state == nullptr) {
        cout << "Ignoring null state.\n";
        return;
    }

    currentState->exit();
    currentState.reset(state);
    currentState->enter();
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
    window.close();
}

void Application::update() {
    static int i = 0;
    static int j = 0;
    i++;
    if (i > 10) {
        j++;
        if (j > 5) {
            exit();
            return;
        }
        changeState(new GameState());
        i=0;
    }

    clock.restart();
    currentState->update();
}

void Application::createWindow() {
    window.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    window.setFramerateLimit(GAME_FRAMES_PER_SECOND);
}

} /* namespace pong */
