#include "pong/state.hpp"

#include "pong/application.hpp"

namespace pong {

void BaseState::setup(Application* application) {
    application_ = application;
}

} /* namespace pong */
