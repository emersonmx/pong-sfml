#ifndef PONG_DEFS_HPP
#define PONG_DEFS_HPP

namespace pong {

enum GameObjects {
    PLAYER_1, PLAYER_2, BALL, TOP_WALL, BOTTOM_WALL, MIDFIELD, GAME_OBJECTS_SIZE
};

constexpr const wchar_t* WINDOW_TITLE = L"Pong";
constexpr int WINDOW_WIDTH = 640;
constexpr int WINDOW_HEIGHT = 480;
constexpr int DEFAULT_FONT_SIZE = 32;
constexpr int SCORE_FONT_SIZE = 42;

} /* namespace pong */
#endif /* PONG_DEFS_HPP */
