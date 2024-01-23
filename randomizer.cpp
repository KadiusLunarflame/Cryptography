#include "randomizer.hpp"

uint8_t Randomizer::rnd() {
    return dst(rng);
}

uint8_t Randomizer::rnd_notnull() {
    return dst_notnull(rng);
}

uint64_t Randomizer::rnd64() {
    uint64_t res = 0;
    for(int i{}; i < 8; ++i) {
        res <<= 8;
        res ^= rnd();
    }

    return res;
}
