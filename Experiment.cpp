#include "Experiment.hpp"
#include "randomizer.hpp"

RKB4RExp::RKB4RExp(){
    uint64_t key1 = randomizer.rnd64();
    std::cout << "TRY RECOVER KEY1 = " << std::hex << key1 << std::endl;
    uint64_t key2 = randomizer.rnd64();

    encryptor1 = khazad_reduced(key1, key2);
    encryptor2 = khazad_reduced(key1, key2^(randomizer.rnd_notnull()));
    std::cout << "when KEY2 = " << std::hex << key2 << " and Key2' = " << encryptor2.ekeys_[1] << std::endl;
}

void RKB4RExp::Run()  {
    std::unordered_set<uint64_t> set;
    reserve(set);

    for (int t{}; /*t < (2 << 16)*/; ++t) {
        plaintext = randomizer.rnd64();

        uint64_t q1 = encryptor1.encrypt(plaintext);
        uint64_t q2 = encryptor2.encrypt(plaintext);

        uint64_t diff = randomizer.rnd_notnull();

        uint64_t z1 = q1^diff;
        uint64_t z2 = q2^diff;

        uint64_t w1 = encryptor1.decrypt(z1);
        uint64_t w2 = encryptor2.decrypt(z2);

        if(w1 != w2)
            for (int theta{1}; theta < 256; ++theta) {
                auto v = brute_key(w1, w2, khazad_reduced::L(theta));
                if (v != std::nullopt)
                    if (variants(*v, set))
                        goto ex;
            } //for
    }

    ex:
    if(true){}
//            if(set.contains(key1)) {
//                std::cout << "set does contain our key" << std::endl;
//            }
}

auto
RKB4RExp::brute_key(uint64_t z1, uint64_t z2, uint64_t ltheta)
-> std::optional<std::vector<std::vector<uint8_t>>>
{
    //std::cout << "brute key called" << std::endl;
    uint64_t mask = 0x00000000000000FF;

    uint8_t tmp1[8];
    tmp1[0] = (uint8_t)(z1 & mask);
    tmp1[1] = (uint8_t)((z1 >> 8) & mask);
    tmp1[2] = (uint8_t)((z1 >> 16) & mask);
    tmp1[3] = (uint8_t)((z1 >> 24) & mask);
    tmp1[4] = (uint8_t)((z1 >> 32) & mask);
    tmp1[5] = (uint8_t)((z1 >> 40) & mask);
    tmp1[6] = (uint8_t)((z1 >> 48) & mask);
    tmp1[7] = (uint8_t)((z1 >> 56) & mask);

    uint8_t tmp2[8];
    tmp2[0] = (uint8_t)(z2 & mask);
    tmp2[1] = (uint8_t)((z2 >> 8) & mask);
    tmp2[2] = (uint8_t)((z2 >> 16) & mask);
    tmp2[3] = (uint8_t)((z2 >> 24) & mask);
    tmp2[4] = (uint8_t)((z2 >> 32) & mask);
    tmp2[5] = (uint8_t)((z2 >> 40) & mask);
    tmp2[6] = (uint8_t)((z2 >> 48) & mask);
    tmp2[7] = (uint8_t)((z2 >> 56) & mask);

    uint8_t ltheta_tmp[8];
    ltheta_tmp[0] = (uint8_t)(ltheta & mask);
    ltheta_tmp[1] = (uint8_t)((ltheta >> 8) & mask);
    ltheta_tmp[2] = (uint8_t)((ltheta >> 16) & mask);
    ltheta_tmp[3] = (uint8_t)((ltheta >> 24) & mask);
    ltheta_tmp[4] = (uint8_t)((ltheta >> 32) & mask);
    ltheta_tmp[5] = (uint8_t)((ltheta >> 40) & mask);
    ltheta_tmp[6] = (uint8_t)((ltheta >> 48) & mask);
    ltheta_tmp[7] = (uint8_t)((ltheta >> 56) & mask);

    std::vector<std::vector<uint8_t>> variants(8, std::vector<uint8_t>());
    for(int i{}; i < 8; ++i) {
        for (int x{}; x < 256; ++x)
            if ((khazad_reduced::S(tmp1[i] ^ x) ^ khazad_reduced::S(tmp2[i] ^ x)) == ltheta_tmp[i])
                variants.at(i).push_back(x);

        if(variants.at(i).empty()) return std::nullopt;
    }

    return variants;
}

bool RKB4RExp::variants(const std::vector<std::vector<uint8_t>>& v, std::unordered_set<uint64_t>& map) {
    auto it0 = v.at(0).begin();
    auto it1 = v.at(1).begin();
    auto it2 = v.at(2).begin();
    auto it3 = v.at(3).begin();
    auto it4 = v.at(4).begin();
    auto it5 = v.at(5).begin();
    auto it6 = v.at(6).begin();
    auto it7 = v.at(7).begin();

    auto eit0 = v.at(0).end();
    auto eit1 = v.at(1).end();
    auto eit2 = v.at(2).end();
    auto eit3 = v.at(3).end();
    auto eit4 = v.at(4).end();
    auto eit5 = v.at(5).end();
    auto eit6 = v.at(6).end();
    auto eit7 = v.at(7).end();

    uint8_t tmp[8] = {0};

    for(; it0 != eit0; ++it0) {
        tmp[0] = *it0;

        for(; it1 != eit1; ++it1) {
            tmp[1] = *it1;

            for(; it2 != eit2; ++it2) {
                tmp[2] = *it2;

                for(; it3 != eit3; ++it3) {
                    tmp[3] = *it3;

                    for(; it4 != eit4; ++it4) {
                        tmp[4] = *it4;

                        for(; it5 != eit5; ++it5) {
                            tmp[5] = *it5;

                            for(; it6 != eit6; ++it6) {
                                tmp[6] = *it6;

                                for(; it7 != eit7; ++it7) {
                                    tmp[7] = *it7;
                                    uint64_t key = arr_to_64(tmp);
//                                    map.insert({key, 0});
//                                    if(key == 0x123456789ABCDEF) {
//                                        return key;
//                                    }

                                    if(map.count(key) == 0) {
                                        map.insert(key);
//                                        std::cout << "inserted" << std::endl;
                                    } else {
                                        std::cout << "WTF" << std::endl;
                                        std::cout << std::setw(16) << std::setfill('0') << std::hex << key << " <- KEY HAS BEEN FOUND" << std::endl;
                                        return true;
                                    }

                                }
                                it7 = v.at(7).begin();
                            }
                            it6 = v.at(6).begin();
                            it7 = v.at(7).begin();
                        }
                        it5 = v.at(5).begin();
                        it6 = v.at(6).begin();
                        it7 = v.at(7).begin();
                    }
                    it4 = v.at(4).begin();
                    it5 = v.at(5).begin();
                    it6 = v.at(6).begin();
                    it7 = v.at(7).begin();
                }
                it3 = v.at(3).begin();
                it4 = v.at(4).begin();
                it5 = v.at(5).begin();
                it6 = v.at(6).begin();
                it7 = v.at(7).begin();
            }
            it2 = v.at(2).begin();
            it3 = v.at(3).begin();
            it4 = v.at(4).begin();
            it5 = v.at(5).begin();
            it6 = v.at(6).begin();
            it7 = v.at(7).begin();
        }
        it1 = v.at(1).begin();
        it2 = v.at(2).begin();
        it3 = v.at(3).begin();
        it4 = v.at(4).begin();
        it5 = v.at(5).begin();
        it6 = v.at(6).begin();
        it7 = v.at(7).begin();
    }

    return false;
}

template<size_t N>
uint64_t RKB4RExp::arr_to_64(const uint8_t (&arr)[N]) {
    uint64_t x = 0;

    x <<= 8;
    x ^= arr[7];
    x <<= 8;
    x ^= arr[6];
    x <<= 8;
    x ^= arr[5];
    x <<= 8;
    x ^= arr[4];
    x <<= 8;
    x ^= arr[3];
    x <<= 8;
    x ^= arr[2];
    x <<= 8;
    x ^= arr[1];
    x <<= 8;
    x ^= arr[0];

    return x;
}