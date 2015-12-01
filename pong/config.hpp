#ifndef PONG_CONFIG_HPP
#define PONG_CONFIG_HPP

#include <sstream>

namespace pong {

class Config {
    public:
        Config() {}
        virtual ~Config() {}

        std::wstring windowTitle;
        int windowWidth;
        int windowHeight;
};

} /* namespace pong */ 

#endif /* PONG_CONFIG_HPP */
