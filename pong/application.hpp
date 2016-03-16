#ifndef PONG_APPLICATION_HPP
#define PONG_APPLICATION_HPP

#include <memory>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "pong/defs.hpp"
#include "pong/state.hpp"

namespace pong {

class Application {
    public:
        Application() {}
        virtual ~Application() {}

        sf::RenderWindow& window() { return window_; }

        void ChangeState(State* state);

        void Exit();
        void Exit(int errorCode);
        int Run();

    protected:

        virtual void Create();
        virtual void Destroy();

        virtual void Update();

        sf::RenderWindow window_;
        sf::Event event_;
        sf::Clock clock_;

    private:
        void CreateWindow();

        std::unique_ptr<State> current_state_ = make_unique<DefaultState>();

        int error_code_ = 0;
        bool running_ = true;
};

} /* namespace pong */
#endif /* PONG_APPLICATION_HPP */
