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
    currentState_->enter(this);
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
        tick();
    }

    destroy();
    return errorCode_;
}

void Application::create() {
    window_.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    sf::View view = window_.getDefaultView();
    view.setSize(WINDOW_WIDTH, -WINDOW_HEIGHT);
    window_.setView(view);

    GameState* gameState = new GameState();
    changeState(gameState);
}

void Application::destroy() {
    window_.close();
}

void Application::tick() {
    sf::Time time = clock_.restart();

    handleEvents();

    timeAccumulator_ += time.asSeconds();
    if (timeAccumulator_ >= GAME_TIME_STEP) {
        currentState_->update();
        timeAccumulator_ -= GAME_TIME_STEP;
    }

    window_.clear();
    currentState_->render(window_);
    window_.display();
}

void Application::handleEvents() {
    while (window_.pollEvent(event_)) {
        if (event_.type == sf::Event::Closed) {
            exit();
        }
#ifndef NDEBUG
        if (event_.type == sf::Event::KeyPressed) {
            if (event_.key.code == sf::Keyboard::R) {
                changeState(new GameState());
            }
        }
#endif /* ifndef NDEBUG  */
    }
}

} /* namespace pong */
