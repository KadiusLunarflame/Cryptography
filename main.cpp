//
// Created by kadius on 01.08.23.
//

#include "KHAZAD.hpp"

#include <numeric>
#include <vector>
#include <iostream>
#include <iomanip>

//#include <randomizer.hpp>
#include <optional>
#include <unordered_set>

#include "Experiment.hpp"

//struct Indexes {
//    int i;
//    int j;
//};
//
//template<size_t N>
//uint64_t arr_to_64(const uint8_t(&arr)[N]) {
//    uint64_t x = 0;
//
//    x <<= 8;
//    x ^= arr[7];
//    x <<= 8;
//    x ^= arr[6];
//    x <<= 8;
//    x ^= arr[5];
//    x <<= 8;
//    x ^= arr[4];
//    x <<= 8;
//    x ^= arr[3];
//    x <<= 8;
//    x ^= arr[2];
//    x <<= 8;
//    x ^= arr[1];
//    x <<= 8;
//    x ^= arr[0];
//
//    return x;
//}
//
//auto
//brute_key(uint64_t z1, uint64_t z2, uint64_t ltheta)
//-> std::optional<std::vector<std::vector<uint8_t>>>
//{
////    std::cout << "brute key called" << std::endl;
//    uint64_t mask = 0x00000000000000FF;
//
//    uint8_t tmp1[8];
//    tmp1[0] = (uint8_t)(z1 & mask);
//    tmp1[1] = (uint8_t)((z1 >> 8) & mask);
//    tmp1[2] = (uint8_t)((z1 >> 16) & mask);
//    tmp1[3] = (uint8_t)((z1 >> 24) & mask);
//    tmp1[4] = (uint8_t)((z1 >> 32) & mask);
//    tmp1[5] = (uint8_t)((z1 >> 40) & mask);
//    tmp1[6] = (uint8_t)((z1 >> 48) & mask);
//    tmp1[7] = (uint8_t)((z1 >> 56) & mask);
//
//    uint8_t tmp2[8];
//    tmp2[0] = (uint8_t)(z2 & mask);
//    tmp2[1] = (uint8_t)((z2 >> 8) & mask);
//    tmp2[2] = (uint8_t)((z2 >> 16) & mask);
//    tmp2[3] = (uint8_t)((z2 >> 24) & mask);
//    tmp2[4] = (uint8_t)((z2 >> 32) & mask);
//    tmp2[5] = (uint8_t)((z2 >> 40) & mask);
//    tmp2[6] = (uint8_t)((z2 >> 48) & mask);
//    tmp2[7] = (uint8_t)((z2 >> 56) & mask);
//
//    uint8_t ltheta_tmp[8];
//    ltheta_tmp[0] = (uint8_t)(ltheta & mask);
//    ltheta_tmp[1] = (uint8_t)((ltheta >> 8) & mask);
//    ltheta_tmp[2] = (uint8_t)((ltheta >> 16) & mask);
//    ltheta_tmp[3] = (uint8_t)((ltheta >> 24) & mask);
//    ltheta_tmp[4] = (uint8_t)((ltheta >> 32) & mask);
//    ltheta_tmp[5] = (uint8_t)((ltheta >> 40) & mask);
//    ltheta_tmp[6] = (uint8_t)((ltheta >> 48) & mask);
//    ltheta_tmp[7] = (uint8_t)((ltheta >> 56) & mask);
//
//    std::vector<std::vector<uint8_t>> variants(8, std::vector<uint8_t>());
//    for(int i{}; i < 8; ++i) {
//        for (int x{}; x < 256; ++x)
//            if ((khazad_reduced::S(tmp1[i] ^ x) ^ khazad_reduced::S(tmp2[i] ^ x)) == ltheta_tmp[i])
//                variants.at(i).push_back(x);
//
//        if(variants.at(i).empty()) return std::nullopt;
//    }
//
//
////    for(int i{}; i < 1; ++i) {
////        for (int x{}; x < 256; ++x)
////            if ((KHAZAD::S(tmp1[i] ^ x) ^ KHAZAD::S(tmp2[i] ^ x)) == ltheta_tmp[i])
////                variants.at(i).push_back(x);
////
////    }
//
//    return variants;
//}
//
//bool variants(const std::vector<std::vector<uint8_t>>& v, std::unordered_set<uint64_t>& map) {
////    std::cout << "variants called" << std::endl;
//
//    auto it0 = v.at(0).begin();
//    auto it1 = v.at(1).begin();
//    auto it2 = v.at(2).begin();
//    auto it3 = v.at(3).begin();
//    auto it4 = v.at(4).begin();
//    auto it5 = v.at(5).begin();
//    auto it6 = v.at(6).begin();
//    auto it7 = v.at(7).begin();
//
//    auto eit0 = v.at(0).end();
//    auto eit1 = v.at(1).end();
//    auto eit2 = v.at(2).end();
//    auto eit3 = v.at(3).end();
//    auto eit4 = v.at(4).end();
//    auto eit5 = v.at(5).end();
//    auto eit6 = v.at(6).end();
//    auto eit7 = v.at(7).end();
//
//    uint8_t tmp[8] = {0};
//
//    for(; it0 != eit0; ++it0) {
//        tmp[0] = *it0;
//
//        for(; it1 != eit1; ++it1) {
//            tmp[1] = *it1;
//
//            for(; it2 != eit2; ++it2) {
//                tmp[2] = *it2;
//
//                for(; it3 != eit3; ++it3) {
//                    tmp[3] = *it3;
//
//                    for(; it4 != eit4; ++it4) {
//                        tmp[4] = *it4;
//
//                        for(; it5 != eit5; ++it5) {
//                            tmp[5] = *it5;
//
//                            for(; it6 != eit6; ++it6) {
//                                tmp[6] = *it6;
//
//                                for(; it7 != eit7; ++it7) {
//                                    tmp[7] = *it7;
//                                    uint64_t key = arr_to_64(tmp);
////                                    map.insert({key, 0});
////                                    if(key == 0x123456789ABCDEF) {
////                                        return key;
////                                    }
//
//                                    if(map.count(key) == 0) {
//                                        map.insert(key);
////                                        std::cout << "inserted" << std::endl;
//                                    } else {
//                                        std::cout << "WTF" << std::endl;
//                                        std::cout << std::setw(16) << std::setfill('0') << std::hex << key << " <- KEY HAS BEEN FOUND" << std::endl;
//                                        return true;
//                                    }
//
//                                }
//                                it7 = v.at(7).begin();
//                            }
//                            it6 = v.at(6).begin();
//                            it7 = v.at(7).begin();
//                        }
//                        it5 = v.at(5).begin();
//                        it6 = v.at(6).begin();
//                        it7 = v.at(7).begin();
//                    }
//                    it4 = v.at(4).begin();
//                    it5 = v.at(5).begin();
//                    it6 = v.at(6).begin();
//                    it7 = v.at(7).begin();
//                }
//                it3 = v.at(3).begin();
//                it4 = v.at(4).begin();
//                it5 = v.at(5).begin();
//                it6 = v.at(6).begin();
//                it7 = v.at(7).begin();
//            }
//            it2 = v.at(2).begin();
//            it3 = v.at(3).begin();
//            it4 = v.at(4).begin();
//            it5 = v.at(5).begin();
//            it6 = v.at(6).begin();
//            it7 = v.at(7).begin();
//        }
//        it1 = v.at(1).begin();
//        it2 = v.at(2).begin();
//        it3 = v.at(3).begin();
//        it4 = v.at(4).begin();
//        it5 = v.at(5).begin();
//        it6 = v.at(6).begin();
//        it7 = v.at(7).begin();
//    }
//
//    return false;
//}

//void reserve(std::unordered_set<uint64_t>& set) {
//    set.reserve(2<<12);
//}

//void Boomerang4RExperiment() {
//    uint64_t plaintext;
//
//    uint64_t key1 =
////            0xcfaf9adae8cc1ea1;
//            rnd64();
//
//    std::cout << "TRY RECOVER KEY1 = " << std::hex << key1 << std::endl;
//
//    uint64_t key2 = rnd64();
//
//    khazad_reduced encryptor1(key1, key2);
//    khazad_reduced encryptor2(key1, key2^rnd_notnull());
//
//    std::cout << "when KEY2 = " << std::hex << key2 << " and Key2' = " << encryptor2.ekeys_[1] << std::endl;
//
////    khazad_reduced encryptor1(key1, 0xFEDCBA9876543AA);
////    khazad_reduced encryptor2(key1, 0xFEDCBA9876543BB);
//
//
//    //cfaf9adae8cc1ea1
//
////    std::vector<int> terms;
////    for(int k{}; k < 5000; ++k) {
//    std::unordered_set<uint64_t> set;
//    reserve(set);
//
//        for (int t{}; /*t < (2 << 16)*/; ++t) {
////            std::cout << std::dec << "term = " << t << std::endl;
//            plaintext = rnd64();
//
//            auto state1 = plaintext;
//            auto state2 = plaintext;
//
////            state1 ^= encryptor1.ekeys_[0];
////            state2 ^= encryptor2.ekeys_[0];
////
////            state1 = KHAZAD::S(state1);
////            state2 = KHAZAD::S(state2);
////
////            state1 = KHAZAD::L(state1);
////            state2 = KHAZAD::L(state2);
////
////            state1 ^= encryptor1.ekeys_[1];
////            state2 ^= encryptor2.ekeys_[1];
////
////            state1 = KHAZAD::S(state1);
////            state2 = KHAZAD::S(state2);
////
////            state1 = KHAZAD::L(state1);
////            state2 = KHAZAD::L(state2);
////
////            state1 ^= encryptor1.ekeys_[2];
////            state2 ^= encryptor2.ekeys_[2];
////
////            state1 = KHAZAD::S(state1);
////            state2 = KHAZAD::S(state2);
////
////            state1 = KHAZAD::L(state1);
////            state2 = KHAZAD::L(state2);
////
////            state1 ^= encryptor1.ekeys_[3];
////            state2 ^= encryptor2.ekeys_[3];
////
////            state1 = KHAZAD::S(state1);
////            state2 = KHAZAD::S(state2);
////
////            state1 ^= encryptor1.ekeys_[4];
////            state2 ^= encryptor2.ekeys_[4];
//
//            state1 = encryptor1.encrypt(state1);
//            state2 = encryptor2.encrypt(state2);
//
//            uint64_t diff = rnd_notnull();
//
//            state1 ^= diff;
//            state2 ^= diff;
//
////            state1 ^= encryptor1.ekeys_[4];
////            state2 ^= encryptor2.ekeys_[4];
////
////            state1 = KHAZAD::S(state1);
////            state2 = KHAZAD::S(state2);
////
////            state1 ^= encryptor1.ekeys_[3];
////            state2 ^= encryptor2.ekeys_[3];
////
////            state1 = KHAZAD::L(state1);
////            state2 = KHAZAD::L(state2);
////
////            state1 = KHAZAD::S(state1);
////            state2 = KHAZAD::S(state2);
////
////            state1 ^= encryptor1.ekeys_[2];
////            state2 ^= encryptor2.ekeys_[2];
////
////            state1 = KHAZAD::L(state1);
////            state2 = KHAZAD::L(state2);
////
////            uint64_t afterl1 = state1;
////            uint64_t afterl2 = state2;
////
////            state1 = KHAZAD::S(state1);
////            state2 = KHAZAD::S(state2);
////
////            state1 ^= encryptor1.ekeys_[1];
////            state2 ^= encryptor2.ekeys_[1];
////
//////            uint64_t theta1 = state1;
//////            uint64_t theta2 = state2;
////
////            state1 = KHAZAD::L(state1);
////            state2 = KHAZAD::L(state2);
////
//////            uint64_t ltheta1 = state1;
//////            uint64_t ltheta2 = state2;
////
////            state1 = KHAZAD::S(state1);
////            state2 = KHAZAD::S(state2);
////
////            uint64_t w1 = state1 ^ encryptor1.ekeys_[0];
////            uint64_t w2 = state2 ^ encryptor2.ekeys_[0];
//
//            uint64_t w1 = encryptor1.decrypt(state1);
//            uint64_t w2 = encryptor2.decrypt(state2);
//
//            if(w1 != w2) {
//                for (int theta{1}; theta < 256; ++theta) {
//                    auto v = brute_key(w1, w2, khazad_reduced::L(theta));
//                    if (v != std::nullopt) {
//                        if (variants(*v, set)) {
//                            //terms.push_back(t);
//                            goto ex;
//                        }
//                    }
//                } //for
//            }
//        }
//ex:
//    if(set.contains(key1)) {
//        std::cout << "set does contain our key" << std::endl;
//    }
//}
//
//void exp3() {
//
//    uint8_t x;// = rnd_notnull();
//    uint8_t dx = rnd_notnull();
//
//    uint8_t nabla = rnd_notnull();
//
//    for(int i{1}; i < 256; ++i) {
//        x = i;
//        if((KHAZAD::S(KHAZAD::S(x)^nabla)^KHAZAD::S(KHAZAD::S(x^dx)^nabla)) == dx) {
//            std::cout << "WTF" << std::endl;
//        }
//    }
//}

int main() {
    //Boomerang4RExperiment();

//    uint64_t key1 = rnd64();
//
//    std::cout << "TRY RECOVER KEY1 = " << std::hex << key1 << std::endl;
//
//    uint64_t key2 = rnd64();
//
//    khazad_reduced encryptor1(key1, key2);
//    khazad_reduced encryptor2(key1, key2^rnd_notnull());
//
//    std::cout << "when KEY2 = " << std::hex << key2 << " and Key2' = " << encryptor2.ekeys_[1] << std::endl;

    RKB4RExp exp;
    exp.Run();


////    std::vector<std::vector<uint8_t>> v{{0xff},{0xaa, 0xbb},{0xaa},{0xaa},{0xaa, 0xee},{0xaa},{0xaa},{0xaa},};
////
////    variants(v, map);
////
////    for(const auto& [k, _]: map) {
////        std::cout << std::setw(16) << std::setfill('0') << std::hex << k  << std::endl;
////    }
////

//    std::cout << std::setw(16) << std::setfill('0') << std::hex << plaintext << " <-plaintext" << std::endl;
//    std::cout << std::setw(16) << std::setfill('0') << std::hex << z1 << " <-w1" << std::endl;
//    std::cout << std::setw(16) << std::setfill('0') << std::hex << z2 << " <-w2" << std::endl;
//
//    z1 = 0x5f0be45b2d171589;
//    z2 = 0x0c5d0ed3b7f5db7c;
//
//    uint64_t k = 0x9f824230362a0162;
//
//    std::cout << std::setw(16) << std::setfill('0') << std::hex << KHAZAD::L(KHAZAD::S(z1^k)^KHAZAD::S(z2^k)) << std::endl;


//    for(const auto& [k, _]: map) {
//        std::cout << std::setw(16) << std::setfill('0') << std::hex << k << std::endl;
//    }


//    auto dec = cipher.decrypt(enc);
//

//    cipher.decrypt();


//    std::vector<std::vector<int>> DDT(256, std::vector<int>(256,0));
//    for(int x{}; x < 256; ++x)
//        for(int y{}; y < 256; ++y)
//            ++DDT[(uint8_t)(x^y)][(uint8_t)(KHAZAD::Sbox(x)^KHAZAD::Sbox(y))];
//
//    int z{};
//    int sixes{};
//    int twos{};
//    int fours{};
//    int eights{};
//
//    std::unordered_set<uint8_t> set;
//    for(int i{}; i < 256; ++i) {
//        for (int j{}; j < 256; ++j) {
//            auto c = DDT[i][j];
////            set.insert(c);
//            if (c == 2)
//                ++twos;
//            else if (c == 4)
//                ++fours;
//            else if (c == 6)
//                ++sixes;
//            else if (c == 8)
//                ++eights;
//            else
//                ++z;
//        }
//    }

//    for(auto c: set) {
//        std::cout << std::dec << (int)(c) << std::endl;
//    }

//    std::cout << "|0| = " << z << std::endl;
//    std::cout << "|2| = " << twos << std::endl;
//    std::cout << "|4| = " << fours << std::endl;
//    std::cout << "|6| = " << sixes << std::endl;
//    std::cout << "|8| = " << eights << std::endl;
//
//    std::cout << z+twos+fours+sixes+eights << std::endl;
//
//    std::cout << (double)(eights+sixes+fours+twos+1)/(256*256) << std::endl;





//    std::cout << '(';
//    for(int i{}; i < 16; ++i) {
//        for(int j{}; j < 16; ++j) {
//            std::cout << std::hex << sbox[i][j];
//        }
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

//
//    uint64_t y = 0x0102030405060708;
//
//    uint8_t a[8] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};

//    uint8_t a[8] = {0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA};
//
//    for(int i{}; i < 8; ++i) {
//        a[i] = KHAZAD::S(a[i]);
//        std::cout << std::hex << (int)a[i];
//    }
//    std::cout << std::endl;
//
//    uint64_t z = 0xfefefefefefefefe;
//    std::cout << KHAZAD::L(z);
//    auto r = T0[0xaa]^T1[0xaa]^T2[0xaa]^T3[0xaa]^T4[0xaa]^T5[0xaa]^T6[0xaa]^T7[0xaa];
//    std::cout << std::endl;
//    std::cout << std::hex << r << std::endl;
//
//    std::cout << std::hex << KHAZAD::T(0xaaaaaaaaaaaaaaaa) << std::endl;

//    std::vector<uint64_t> kappa;
//    for(uint64_t x{1}; x < 256; ++x)
//        kappa.push_back(x);
//
//    std::vector<std::vector<uint64_t>> Sk;
//
//    for(const auto& diff: kappa) {
//        std::vector<uint64_t> ddiff;
//        ddiff.reserve(256);
//        for (int x{}; x < 256; ++x)
//            ddiff.push_back(KHAZAD::S(x)^KHAZAD::S(x^diff));
//
//        Sk.push_back(std::move(ddiff));
//    }
//
//    for(auto& ddiff: Sk) {
//        std::cout << "======================================================================================================" << std::endl;
//        for(auto& x: ddiff) {
////            std::cout << ddiff.size() << std::endl;
//            std::cout << std::hex << std::setw(2) << std::setfill('0') << x << ",";
//        }
//        std::cout << std::endl << "======================================================================================================" << std::endl;
//    }

//    std::vector<std::vector<uint64_t>> vec;
//    for(int i{}; i < 16; ++i) {
//        for(int j{}; j < 16; ++j) {
//            std::cout << std::hex << sbox[i][j];
//        }
//    }


//    for(int i{}; i < 100; ++i) {
//        std::cout << std::hex << (int)rnd() << std::endl;
//    }
//
//    uint8_t a[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,};
//    for(int i{}; i < 8; ++i) {
//
//    }
// 8ad0c2851e742d0e => faf984dba3e8e3bd with diff = d6


    return 0;
}
