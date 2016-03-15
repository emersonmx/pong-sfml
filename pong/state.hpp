#ifndef PONG_STATE_HPP
#define PONG_STATE_HPP

#include <iostream>

using namespace std;

#include "pong/application.hpp"

namespace pong {

class State {
    public:
        virtual ~State() {}

        virtual void create() = 0;
        virtual void destroy() = 0;

        virtual void show() = 0;
        virtual void hide() = 0;

        virtual void update() = 0;
};

class DefaultState: public State {
    public:
        virtual void create() {}
        virtual void destroy() {}

        virtual void show() {}
        virtual void hide() {}

        virtual void update() {}
};

class BaseState: public DefaultState {
    public:
        BaseState() : application(nullptr) {}
        BaseState(Application* application) : this->application(application) {}

        void setApplication(Application* application) {
            $this->application = application;
        }
        Application* getApplication() { return application; }

    protected:
        Application* application;
};

class GameState: public BaseState {
    public:
        virtual void create() {
            cout << "Create\n";
        }
        virtual void destroy() {
            cout << "Destroy\n";
        }

        virtual void show() {
            cout << "Show\n";
        }
        virtual void hide() {
            cout << "Hide\n";
        }

        virtual void update() {
            cout << "Update\n";
        }
};

} /* namespace pong */
#endif /* PONG_STATE_HPP */
