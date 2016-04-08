#include "MXG/Application.hpp"

namespace mxg {

void Application::exit() {
    exit(0);
}

void Application::exit(int errorCode) {
    errorCode_ = errorCode;
    running_ = false;
}

int Application::run() {
    create();

    while (running_) {
        tick();
    }

    destroy();
    return errorCode_;
}

} /* namespace mxg */
