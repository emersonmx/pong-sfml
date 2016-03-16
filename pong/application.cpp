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

    currentState_->exit();
    currentState_.reset(state);
    currentState_->enter();
}

void Application::exit() {
    exit(0);
}

void Application::exit(int errorCode) {
    errorCode_ = errorCode;
    running_ = false;
}

int Application::run() {
    create();

    clock_.restart();
    while (running_) {
        update();
    }

    destroy();
    return errorCode_;
}

void Application::create() {
    createWindow();
}

void Application::destroy() {
    window_.close();
}

void Application::update() {
    sf::Time time = clock_.restart();
    handleEvents();
    currentState_->update(time);
}

void Application::createWindow() {
    window_.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    window_.setFramerateLimit(GAME_FRAMES_PER_SECOND);
}

void Application::handleEvents() {
    while (window_.pollEvent(event_)) {
        if (event_.type == sf::Event::Closed) {
            exit();
        }
    }
}

} /* namespace pong */
