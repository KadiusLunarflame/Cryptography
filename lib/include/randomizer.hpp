//
// Created by kadius on 27.12.23.
//

#ifndef CRYPTOGRAPHY_RANDOMIZER_HPP
#define CRYPTOGRAPHY_RANDOMIZER_HPP

#include <random>


struct Randomizer {
    uint8_t rnd();
    uint8_t rnd_notnull();
    uint64_t rnd64();
private:
    std::random_device seed;
    std::mt19937_64 rng{seed()};
    std::uniform_int_distribution<uint8_t> dst{0, 0xff};
    std::uniform_int_distribution<uint8_t> dst_notnull{1, 0xff};
};

#endif //CRYPTOGRAPHY_RANDOMIZER_HPP
