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

        int defaultFontSize;
        int scoreFontSize;
};

enum {
    PLAYER_1, PLAYER_2, BALL, TOP_WALL, BOTTOM_WALL, MIDFIELD, OBJECTS_SIZE
}; 

} /* namespace pong */ 

#endif /* PONG_CONFIG_HPP */
