//
// Created by kadius on 01.08.23.
//

#include "KHAZAD.hpp"
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <string.h>

struct Indexes {
    int i;
    int j;
};

int main() {

    KHAZAD cipher(0x0000000000000000,0x0000000000000000);

    for(int i{}; i <= KHAZAD::R; ++i)
        std::cout << std::hex << std::setfill('0') << std::setw(16) << cipher.ekeys_[i] << std::endl;

    std::cout << std::endl;
    KHAZAD cipher2(0xFF00000000000000,0x0000000000000000);

    for(int i{}; i <= KHAZAD::R; ++i)
        std::cout << std::hex << std::setfill('0') << std::setw(16) << cipher2.ekeys_[i] << std::endl;

//    uint8_t plain[8] = {0xE6,0xB0,0xCD,0x70,0x81,0xD6,0xD0,0x22};
//    uint8_t master[16] = {0x4F, 0x4F,0x4F,0x4F,0x4F, 0x4F,0x4F,0x4F,0x4F, 0x4F,0x4F,0x4F,0x4F, 0x4F,0x4F,0x4F,};
//    KHAZAD cipher(plain, master);
//    cipher.decrypt();
//    std::vector<std::vector<int>> DDT(256, std::vector<int>(256,0));
//
//
//    for(int x{}; x < 256; ++x)
//        for(int y{}; y < 256; ++y) {
//            ++DDT[(uint8_t)(x^y)][(uint8_t)(cipher.S(x)^cipher.S(y))];
//        }
//
//    for(int i{}; i < 256; ++i) {
//        for (int j{}; j < 256; ++j)
//            std::cout << DDT[i][j] << " ";
//
//        std::cout << std::endl;
//    }
//
//    std::vector<Indexes> indexes;
//
//    int max{};
//    for(int i{1}; i < 256; ++i) {
//        for (int j{}; j < 256; ++j) {
//            if(DDT[i][j] == 8) {
//                indexes.push_back({i,j});
//            }
//        }
//    }
//
//    for(auto item: indexes)
//        std::cout << item.i << "," << item.j << std::endl;



    return 0;
}
