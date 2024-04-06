//
// Created by kadius on 04.12.23.
//

#ifndef CRYPTOGRAPHY_EXPERIMENT_HPP
#define CRYPTOGRAPHY_EXPERIMENT_HPP

#include <KHAZAD.hpp>
#include <randomizer.hpp>
#include <unordered_set>
#include <optional>
#include <iostream>
#include <iomanip>

struct RKB4RExp {
    RKB4RExp(khazad_reduced& enc1, khazad_reduced& enc2):encryptor1(enc1), encryptor2(enc2) {
    }

    //randomly initializes keys
    RKB4RExp();

    void Run();

private:
    void reserve(std::unordered_set<uint64_t>& set) {
        set.reserve(2<<12);
    }

    template<size_t N>
    uint64_t arr_to_64(const uint8_t(&arr)[N]);

    auto
    brute_key(uint64_t z1, uint64_t z2, uint64_t ltheta)
    -> std::optional<std::vector<std::vector<uint8_t>>>;

    bool variants(const std::vector<std::vector<uint8_t>>& v, std::unordered_set<uint64_t>& map);

private:
    Randomizer randomizer;
    khazad_reduced encryptor1;
    khazad_reduced encryptor2;
    uint64_t plaintext{};
};



#endif //CRYPTOGRAPHY_EXPERIMENT_HPP