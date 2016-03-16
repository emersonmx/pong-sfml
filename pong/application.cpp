#include "pong/application.hpp"

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

namespace pong {

void Application::ChangeState(State* state) {
    if (state == nullptr) {
        cout << "Ignoring null state.\n";
        return;
    }

    current_state_->Exit();
    current_state_.reset(state);
    current_state_->Enter();
}

void Application::Exit() {
    exit(0);
}

void Application::Exit(int error_code) {
    this->error_code_ = error_code;
    running_ = false;
}

int Application::Run() {
    Create();

    clock_.restart();
    while (running_) {
        Update();
    }

    Destroy();
    return error_code_;
}

void Application::Create() {
    CreateWindow();
}

void Application::Destroy() {
    window_.close();
}

void Application::Update() {
    sf::Time time = clock_.restart();
    current_state_->Update(time);
}

void Application::CreateWindow() {
    window_.create(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    window_.setFramerateLimit(GAME_FRAMES_PER_SECOND);
}

} /* namespace pong */
