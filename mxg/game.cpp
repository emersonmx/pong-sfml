#include "mxg/game.hpp"

#include <iostream>

namespace mxg {

void Game::pushScreen(Screen* screen) {
    if (screen == nullptr) {
        std::cout << "Ignoring null screen." << std::endl;
        return;
    }

    screen->enter();
    screens_.emplace(screen);
}

Screen* Game::currentScreen() {
    return screens_.top().get();
}

void Game::popScreen() {
    Screen* screen = currentScreen();
    screen->exit();
    screens_.pop();

    if (screens_.empty()) {
        pushScreen(new DefaultScreen());
    }
}

void Game::changeScreen(Screen* screen) {
    if (!screens_.empty()) {
        popScreen();
    }
    pushScreen(screen);
}

void Game::exit() {
    exit(0);
}

void Game::exit(int errorCode) {
    errorCode_ = errorCode;
    running_ = false;
}

int Game::run() {
    create();

    while (running_) {
        tick();
    }

    destroy();
    return errorCode_;
}

} /* namespace mxg */