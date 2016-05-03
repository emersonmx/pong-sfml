#ifndef PONG_DEFS_HPP_
#define PONG_DEFS_HPP_

#include <string>

namespace pong {

constexpr const wchar_t* WINDOW_TITLE = L"Pong";
constexpr const int WINDOW_WIDTH = 640;
constexpr const int WINDOW_HEIGHT = 480;
constexpr const float WINDOW_HALF_WIDTH = WINDOW_WIDTH / 2.0f;
constexpr const float WINDOW_HALF_HEIGHT = WINDOW_HEIGHT / 2.0f;

enum class Player {
    NONE,
    PLAYER_1, PLAYER_2,
    PLAYER_COUNT
};

constexpr const int PIXELS_PER_METER = 64;

constexpr const int GAME_FRAMES_PER_SECOND = 60;
constexpr const float GAME_TIME_STEP = 1.0f / GAME_FRAMES_PER_SECOND;
constexpr const int GAME_VELOCITY_ITERATIONS = 8;
constexpr const int GAME_POSITION_ITERATIONS = 3;

constexpr const int MATCH_POINT = 10;

constexpr const float WALL_WIDTH = WINDOW_WIDTH;
constexpr const float WALL_HALF_WIDTH = WALL_WIDTH / 2.0f;
constexpr const float WALL_HEIGHT = 10.0f;
constexpr const float WALL_HALF_HEIGHT = WALL_HEIGHT / 2.0f;

constexpr const float BALL_WIDTH = 10.0f;
constexpr const float BALL_HALF_WIDTH = BALL_WIDTH / 2.0f;
constexpr const float BALL_HEIGHT = 10.0f;
constexpr const float BALL_HALF_HEIGHT = BALL_HEIGHT / 2.0f;
constexpr const float BALL_MIN_SPEED = 2.0f;
constexpr const float BALL_MAX_SPEED = 15.0f;
constexpr const float BALL_VELOCITY_STEP = 0.003;
constexpr const float BALL_MIN_ROTATION_SPEED = 0.1f;
constexpr const float BALL_MAX_ROTATION_SPEED = 10.0f;

constexpr const float RACKET_MARGIN = 15.0f;
constexpr const float RACKET_WIDTH = 20.0f;
constexpr const float RACKET_HALF_WIDTH = RACKET_WIDTH / 2.0f;
constexpr const float RACKET_HEIGHT = 80.0f;
constexpr const float RACKET_HALF_HEIGHT = RACKET_HEIGHT / 2.0f;
constexpr const float RACKET_BASE_SPEED = 5.0f;

const std::string ASSETS_PATH = "assets/";
constexpr const int DEFAULT_FONT_SIZE = 24;

} /* namespace pong */
#endif /* PONG_DEFS_HPP_ */
