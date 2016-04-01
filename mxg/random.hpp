#ifndef MXG_RANDOM_HPP_
#define MXG_RANDOM_HPP_

#include <random>

#include <SFML/Graphics.hpp>

namespace mxg {

class Random {
    public:
        int nextInt() {
            std::mt19937 rng(device());
            std::uniform_int_distribution<> uniform;
            return uniform(rng);
        }
        int nextInt(int min, int max) {
            std::mt19937 rng(device());
            std::uniform_int_distribution<> uniform(min, max);
            return uniform(rng);
        }
        float nextFloat() {
            std::mt19937 rng(device());
            std::uniform_real_distribution<> uniform;
            return uniform(rng);
        }
        float nextFloat(float min, float max) {
            std::mt19937 rng(device());
            std::uniform_real_distribution<> uniform(min, max);
            return uniform(rng);
        }
    private:
        std::random_device device;
};

} /* namespace mxg */
#endif /* MXG_RANDOM_HPP_ */