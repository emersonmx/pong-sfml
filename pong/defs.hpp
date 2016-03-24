#ifndef PONG_DEFS_HPP
#define PONG_DEFS_HPP

#include <memory>

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

namespace pong {

constexpr const wchar_t* WINDOW_TITLE = L"Pong";
constexpr const int WINDOW_WIDTH = 640;
constexpr const int WINDOW_HEIGHT = 480;

constexpr const int GAME_FRAMES_PER_SECOND = 60;
constexpr const float GAME_TIME_STEP = 1.0f / GAME_FRAMES_PER_SECOND;
constexpr const int GAME_VELOCITY_ITERATIONS = 8;
constexpr const int GAME_POSITION_ITERATIONS = 3;

constexpr const int PIXELS_PER_METER = 64;

constexpr const float BALL_MIN_SPEED = 5.0f;
constexpr const float BALL_MAX_SPEED = 20.0f;
constexpr const float BALL_MIN_ROTATION_SPEED = -10.0f;
constexpr const float BALL_MAX_ROTATION_SPEED = 10.0f;
constexpr const float RAQUET_BASE_SPEED = 5.0f;

} /* namespace pong */
#endif /* PONG_DEFS_HPP */
