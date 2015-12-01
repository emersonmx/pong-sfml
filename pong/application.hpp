#ifndef PONG_APPLICATION_HPP
#define PONG_APPLICATION_HPP

namespace pong {

class Application {
    public:
        Application() {}
        virtual ~Application() {}

        void exit(int errorCode=0);
        int run();

    protected:
        virtual void create();
        virtual void destroy();

        virtual void update();
        virtual void handleInput();
        virtual void processLogic();
        virtual void draw();

    private:
        bool running = true;
        int errorCode = 0;
};

} /* namespace pong */ 
#endif /* PONG_APPLICATION_HPP */
