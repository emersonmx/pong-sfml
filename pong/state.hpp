#ifndef PONG_STATE_HPP
#define PONG_STATE_HPP

#include <iostream>

using namespace std;

namespace pong {

class Application;

class State {
    public:
        virtual ~State() {}

        virtual void enter() = 0;
        virtual void exit() = 0;

        virtual void update() = 0;
};

class DefaultState: public State {
    public:
        virtual void enter() {}
        virtual void exit() {}

        virtual void update() {}
};

class BaseState: public DefaultState {
    public:
        BaseState() : application(nullptr) {}
        BaseState(Application* application) : application(application) {}

        void setApplication(Application* application) {
            this->application = application;
        }
        Application* getApplication() { return application; }

    protected:
        Application* application;
};

class GameState: public BaseState {
    public:
        virtual void enter() {
            cout << "Enter " << this << endl;
        }

        virtual void exit() {
            cout << "Exit " << this << endl;
        }

        virtual void update() {
            cout << "Update " << this << endl;
        }
};

} /* namespace pong */
#endif /* PONG_STATE_HPP */
