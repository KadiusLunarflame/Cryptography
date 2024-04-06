//
// Created by kadius on 01.08.23.
//

#ifndef CRYPTOGRAPHY_KHAZAD_HPP
#define CRYPTOGRAPHY_KHAZAD_HPP

#include <vector>
#include <array>
#include <iostream>
#include <numeric>

#include <TTables.hpp>
#include <sbox.hpp>

//class KHAZAD {
//  public:
//    static constexpr uint32_t R = 8;
//    static constexpr int poly_ = 0x11D;
//
//    static uint8_t gf_multiply(uint8_t a, uint8_t b)
//    {
//        uint8_t acc = 0x00;
//        for (uint8_t i = 0; i < 8; i++)
//        {
//            if (b & 0x01)
//            {
//                acc ^= a;
//            }
//            uint8_t msb = a & 0x80;
//            a <<= 1;
//            if (msb)
//            {
//                a ^= KHAZAD::poly_;
//            }
//            b >>= 1;
//        }
//        return acc;
//    }
//
//public:
//    const uint64_t c[R + 1] = {
//            0xba542f7453d3d24d,
//            0x50ac8dbf70529a4c,
//            0xead597d133515ba6,
//            0xde48a899db32b7fc,
//            0xe39e919be2bb416e,
//            0xa5cb6b95a1f3b102,
//            0xccc41d14c363da5d,
//            0x5fdc7dcd7f5a6c5c,
//            0xf726ffede89d6f8e,
//    };
//
//    static uint64_t T(uint64_t plaintext) {
////        return T0[(byte)(block >> 56)]^T1[(byte)(block >> 48)]^T2[(byte)(block >> 40)]^T3[(byte)(block >> 32)]^T4[(byte)(block >> 24)]^T5[(byte)(block >> 16)]^T6[(byte)(block >> 8)]^T7[(byte)(block >> 0)];
////    }
//        return
//                T0[(int) (plaintext >> 56)] ^
//                T1[(int) (plaintext >> 48) & 0xff] ^
//                T2[(int) (plaintext >> 40) & 0xff] ^
//                T3[(int) (plaintext >> 32) & 0xff] ^
//                T4[(int) (plaintext >> 24) & 0xff] ^
//                T5[(int) (plaintext >> 16) & 0xff] ^
//                T6[(int) (plaintext >> 8) & 0xff] ^
//                T7[(int) (plaintext) & 0xff];
//    }
//
//public:
////    template<typename BlockType, typename MasterKeyType>
////    KHAZAD(const BlockType& block, const MasterKeyType& key) {
////        state_ = ((uint64_t)block[0] << 56)^
////                 ((uint64_t)block[1] << 48)^
////                 ((uint64_t)block[2] << 40)^
////                 ((uint64_t)block[3] << 32)^
////                 ((uint64_t)block[4] << 24)^
////                 ((uint64_t)block[5] << 16)^
////                 ((uint64_t)block[6] <<  8)^
////                 ((uint64_t)block[7]);
////
////        //K_{-2}
////        uint64_t k2 =  ((uint64_t)key[0] << 56)^
////                       ((uint64_t)key[1] << 48)^
////                       ((uint64_t)key[2] << 40)^
////                       ((uint64_t)key[3] << 32)^
////                       ((uint64_t)key[4] << 24)^
////                       ((uint64_t)key[5] << 16)^
////                       ((uint64_t)key[6] <<  8)^
////                       ((uint64_t)key[7]);
////        //K_{-1}
////        uint64_t k1 =  ((uint64_t)key[ 8] << 56)^
////                       ((uint64_t)key[ 9] << 48)^
////                       ((uint64_t)key[10] << 40)^
////                       ((uint64_t)key[11] << 32)^
////                       ((uint64_t)key[12] << 24)^
////                       ((uint64_t)key[13] << 16)^
////                       ((uint64_t)key[14] <<  8)^
////                       ((uint64_t)key[15]);
////
////        key_shedule(k2, k1);
////    }
//
//    KHAZAD(uint64_t block, uint64_t k2, uint64_t k1): state_(block) {
//        key_shedule(k2, k1);
//    }
//
//    KHAZAD(uint64_t k2, uint64_t k1) {
//        key_shedule(k2, k1);
//    }
//
//    uint64_t encrypt(uint64_t plaintext) {
//        plaintext ^= ekeys_[0];
//        for(int r{1}; r < R;  ++r)
////            plaintext = T(plaintext) ^ ekeys_[r];
//            plaintext =
//                    T0[(int)(plaintext >> 56)       ] ^
//                    T1[(int)(plaintext >> 48) & 0xff] ^
//                    T2[(int)(plaintext >> 40) & 0xff] ^
//                    T3[(int)(plaintext >> 32) & 0xff] ^
//                    T4[(int)(plaintext >> 24) & 0xff] ^
//                    T5[(int)(plaintext >> 16) & 0xff] ^
//                    T6[(int)(plaintext >>  8) & 0xff] ^
//                    T7[(int)(plaintext      ) & 0xff] ^
//                    ekeys_[r];
//
////        plaintext = T(plaintext) ^ ekeys_[R];<-wrong
//
//        plaintext =
//                (T0[(byte)(plaintext >> 56)] & uint64_t(0xff00000000000000)) ^
//                (T1[(byte)(plaintext >> 48)] & uint64_t(0x00ff000000000000)) ^
//                (T2[(byte)(plaintext >> 40)] & uint64_t(0x0000ff0000000000)) ^
//                (T3[(byte)(plaintext >> 32)] & uint64_t(0x000000ff00000000)) ^
//                (T4[(byte)(plaintext >> 24)] & uint64_t(0x00000000ff000000)) ^
//                (T5[(byte)(plaintext >> 16)] & uint64_t(0x0000000000ff0000)) ^
//                (T6[(byte)(plaintext >>  8)] & uint64_t(0x000000000000ff00)) ^
//                (T7[(byte)(plaintext      )] & uint64_t(0x00000000000000ff)) ^
//                ekeys_[R];
//        return plaintext;
//    }
//
//    uint64_t encrypt() {
//        state_ ^= ekeys_[0];
//        for(int r{1}; r < R;  ++r)
//            state_ = T(state_) ^ ekeys_[r];
//
////        state_ = T(state_) ^ ekeys_[R];<-wrong
////just s-box:
//        state_ =
//                (T0[(byte)(state_ >> 56)] & uint64_t(0xff00000000000000)) ^
//                (T1[(byte)(state_ >> 48)] & uint64_t(0x00ff000000000000)) ^
//                (T2[(byte)(state_ >> 40)] & uint64_t(0x0000ff0000000000)) ^
//                (T3[(byte)(state_ >> 32)] & uint64_t(0x000000ff00000000)) ^
//                (T4[(byte)(state_ >> 24)] & uint64_t(0x00000000ff000000)) ^
//                (T5[(byte)(state_ >> 16)] & uint64_t(0x0000000000ff0000)) ^
//                (T6[(byte)(state_ >>  8)] & uint64_t(0x000000000000ff00)) ^
//                (T7[(byte)(state_      )] & uint64_t(0x00000000000000ff)) ^
//                ekeys_[R];
//        return state_;
//    }
//
//    uint64_t forward_encrypt(uint64_t plaintext) {
//
//        plaintext ^= ekeys_[0];
//
//        for(int r{1}; r < R;  ++r) {
//            plaintext = S(plaintext);
//            plaintext = L(plaintext);
//            plaintext ^= ekeys_[r];
//        }
//
//        plaintext = S(plaintext);
//        plaintext ^= ekeys_[R];
//
//        return plaintext;
//    }
//
//    uint64_t forward_decrypt(uint64_t plaintext) {
//
//        plaintext ^= ekeys_[R];
//        plaintext = S(plaintext);
//
//        for(int r{R-1}; r > 0; --r) {
//            plaintext ^= ekeys_[r];
//            plaintext = L(plaintext);
//            plaintext = S(plaintext);
//        }
//
//        plaintext ^= ekeys_[0];
//
//        return plaintext;
//    }
//
//    uint64_t decrypt(uint64_t ciphertext) {
//        ciphertext ^= ekeys_[R];
//        for(int r{1}; r < R;  ++r)
//            ciphertext = T(ciphertext) ^ dkeys_[r];
//
//        ciphertext =
//                (T0[(byte)(ciphertext >> 56)] & uint64_t(0xff00000000000000)) ^
//                (T1[(byte)(ciphertext >> 48)] & uint64_t(0x00ff000000000000)) ^
//                (T2[(byte)(ciphertext >> 40)] & uint64_t(0x0000ff0000000000)) ^
//                (T3[(byte)(ciphertext >> 32)] & uint64_t(0x000000ff00000000)) ^
//                (T4[(byte)(ciphertext >> 24)] & uint64_t(0x00000000ff000000)) ^
//                (T5[(byte)(ciphertext >> 16)] & uint64_t(0x0000000000ff0000)) ^
//                (T6[(byte)(ciphertext >>  8)] & uint64_t(0x000000000000ff00)) ^
//                (T7[(byte)(ciphertext      )] & uint64_t(0x00000000000000ff)) ^
//                ekeys_[0];
//        return ciphertext;
//    }
//
//    uint64_t decrypt() {
//        state_ ^= ekeys_[R];
//        for(int r{1}; r < R;  ++r)
//            state_ = T(state_) ^ dkeys_[r];
//
//        state_ =
//                (T0[(byte)(state_ >> 56)] & uint64_t(0xff00000000000000)) ^
//                (T1[(byte)(state_ >> 48)] & uint64_t(0x00ff000000000000)) ^
//                (T2[(byte)(state_ >> 40)] & uint64_t(0x0000ff0000000000)) ^
//                (T3[(byte)(state_ >> 32)] & uint64_t(0x000000ff00000000)) ^
//                (T4[(byte)(state_ >> 24)] & uint64_t(0x00000000ff000000)) ^
//                (T5[(byte)(state_ >> 16)] & uint64_t(0x0000000000ff0000)) ^
//                (T6[(byte)(state_ >>  8)] & uint64_t(0x000000000000ff00)) ^
//                (T7[(byte)(state_      )] & uint64_t(0x00000000000000ff)) ^
//                ekeys_[0];
//        return state_;
//    }
//
//    uint64_t show() const {
//        return state_;
//    }
//
//    //lsx api
//    static
//    uint8_t Sbox(uint8_t byte) {
//        return sbox[byte];
//    }
//
//    static
//    uint64_t S(uint64_t byte) {
//        uint64_t mask = 0x00000000000000FF;
//        uint8_t tmp[8];
//
//        tmp[0] = (uint8_t)(byte & mask);
//        tmp[1] = (uint8_t)((byte >> 8) & mask);
//        tmp[2] = (uint8_t)((byte >> 16) & mask);
//        tmp[3] = (uint8_t)((byte >> 24) & mask);
//        tmp[4] = (uint8_t)((byte >> 32) & mask);
//        tmp[5] = (uint8_t)((byte >> 40) & mask);
//        tmp[6] = (uint8_t)((byte >> 48) & mask);
//        tmp[7] = (uint8_t)((byte >> 56) & mask);
//
//
//        for(int i{}; i < 8; ++i)
//            tmp[i] = sbox[tmp[i]];
//
//
//        auto* ptr = (uint64_t*)(tmp);
//        return *ptr;
//    }
//
//    static uint64_t L(uint64_t s) {
//        uint8_t state[8];
//        state[0] = (byte)(s >> 56);
//        state[1] = (byte)(s >> 48);
//        state[2] = (byte)(s >> 40);
//        state[3] = (byte)(s >> 32);
//        state[4] = (byte)(s >> 24);
//        state[5] = (byte)(s >> 16);
//        state[6] = (byte)(s >> 8);
//        state[7] = (byte)(s >> 0);
//
//        uint8_t result[8] = {0};
//
//        for (int i{}; i < 8; ++i) {
//            for (int j{}; j < 8; ++j) {
//                result[j] ^= gf_multiply(state[i], H[i][j]);
//            }
//        }
//
//        return ((uint64_t)result[0] << 56)^((uint64_t)result[1] << 48)^((uint64_t)result[2] << 40)^((uint64_t)result[3] << 32)^
//                ((uint64_t)result[4] << 24)^((uint64_t)result[5] << 16)^((uint64_t)result[6] << 8)^((uint64_t)result[7] );
//    }
//
//
//private:
//    void key_shedule(uint64_t k2, uint64_t k1) {
//        for(byte r{}; r <= R; ++r) {
//            ekeys_[r] = T(k1) ^ c[r] ^ k2;
//            k2 = k1;
//            k1 = ekeys_[r];
//        }
//
//        dkeys_[0] = ekeys_[R];
//        for(byte r{1}; r < R; ++r)
//            dkeys_[r] = T0[(byte)T7[(ekeys_[R-r] >> 56) & 0xff]]^T1[(byte)T7[(ekeys_[R-r] >> 48) & 0xff]]^T2[(byte)T7[(ekeys_[R-r] >> 40) & 0xff]]^T3[(byte)T7[(ekeys_[R-r] >> 32) & 0xff]]^
//                        T4[(byte)T7[(ekeys_[R-r] >> 24) & 0xff]]^T5[(byte)T7[(ekeys_[R-r] >> 16) & 0xff]]^T6[(byte)T7[(ekeys_[R-r] >>  8) & 0xff]]^T7[(byte)T7[(ekeys_[R-r] >>  0) & 0xff]];
//        dkeys_[R] = ekeys_[0];
//    }
//public:
//    block state_;
//    block ekeys_[R+1];
//    block dkeys_[R+1];
//};

class khazad_reduced {
    static constexpr uint32_t R = 4;
    static constexpr int poly_ = 0x11D;

    static uint8_t gf_multiply(uint8_t a, uint8_t b)
    {
        uint8_t acc = 0x00;
        for (uint8_t i = 0; i < 8; i++)
        {
            if (b & 0x01)
                acc ^= a;
            uint8_t msb = a & 0x80;
            a <<= 1;
            if (msb)
                a ^= poly_;
            b >>= 1;
        }
        return acc;
    }

public:
    khazad_reduced() = default;

    khazad_reduced(uint64_t k2, uint64_t k1) {
        key_shedule(k2, k1);
    }

    khazad_reduced& operator=(const khazad_reduced& another) {
        if(this == &another)
            return *this;

        for(int i{}; i <= R; ++i)
            ekeys_[i] = another.ekeys_[i];

        return *this;
    }

private:
    const uint64_t c[3] = {
            0xba542f7453d3d24d,
            0x50ac8dbf70529a4c,
            0xead597d133515ba6,
    };

    void key_shedule(uint64_t k2, uint64_t k1) {
        ekeys_[0] = k2;
        ekeys_[1] = k1;

        for(byte r{}; r <= 2; ++r) {
            ekeys_[r+2] = khazad_reduced::T(k1) ^ c[r] ^ k2;
//            ekeys_[r+2] = KHAZAD::L(KHAZAD::S(k1)) ^ c[r] ^ k2;

            k2 = k1;
            k1 = ekeys_[r+2];
        }
    }
public:
    //lsx cipher api
    static
    uint8_t Sbox(uint8_t byte) {
        return sbox[byte];
    }

    static
    uint64_t S(uint64_t state) {
        uint64_t mask = 0x00000000000000FF;
        uint8_t tmp[8];

        tmp[0] = (uint8_t)(state & mask);
        tmp[1] = (uint8_t)((state >> 8) & mask);
        tmp[2] = (uint8_t)((state >> 16) & mask);
        tmp[3] = (uint8_t)((state >> 24) & mask);
        tmp[4] = (uint8_t)((state >> 32) & mask);
        tmp[5] = (uint8_t)((state >> 40) & mask);
        tmp[6] = (uint8_t)((state >> 48) & mask);
        tmp[7] = (uint8_t)((state >> 56) & mask);


        for(int i{}; i < 8; ++i)
            tmp[i] = sbox[tmp[i]];


        auto* ptr = (uint64_t*)(tmp);
        return *ptr;
    }

    static uint64_t L(uint64_t s) {
        uint8_t state[8];
        state[0] = (byte)(s >> 56);
        state[1] = (byte)(s >> 48);
        state[2] = (byte)(s >> 40);
        state[3] = (byte)(s >> 32);
        state[4] = (byte)(s >> 24);
        state[5] = (byte)(s >> 16);
        state[6] = (byte)(s >> 8);
        state[7] = (byte)(s >> 0);

        uint8_t result[8] = {0};

        for (int i{}; i < 8; ++i)
            for (int j{}; j < 8; ++j)
                result[j] ^= gf_multiply(state[i], H[i][j]);

        return ((uint64_t)result[0] << 56)^((uint64_t)result[1] << 48)^((uint64_t)result[2] << 40)^((uint64_t)result[3] << 32)^
               ((uint64_t)result[4] << 24)^((uint64_t)result[5] << 16)^((uint64_t)result[6] << 8)^((uint64_t)result[7] );
    }
private:
    static uint64_t T(uint64_t plaintext) {
        return
                T0[(int) (plaintext >> 56)] ^
                T1[(int) (plaintext >> 48) & 0xff] ^
                T2[(int) (plaintext >> 40) & 0xff] ^
                T3[(int) (plaintext >> 32) & 0xff] ^
                T4[(int) (plaintext >> 24) & 0xff] ^
                T5[(int) (plaintext >> 16) & 0xff] ^
                T6[(int) (plaintext >> 8) & 0xff] ^
                T7[(int) (plaintext) & 0xff];
    }

public:
    uint64_t forward_encrypt(uint64_t plaintext) {

        plaintext ^= ekeys_[0];

        for(int r{1}; r < 4;  ++r) {
            plaintext = khazad_reduced::S(plaintext);
            plaintext = khazad_reduced::L(plaintext);
            plaintext ^= ekeys_[r];
        }

        plaintext = khazad_reduced::S(plaintext);
        plaintext ^= ekeys_[4];

        return plaintext;
    }

    uint64_t encrypt(uint64_t plaintext) {
        plaintext ^= ekeys_[0];

        for(int r{1}; r < R;  ++r) {
            plaintext = khazad_reduced::T(plaintext);
            plaintext ^= ekeys_[r];
        }

        plaintext = khazad_reduced::S(plaintext);
        plaintext ^= ekeys_[R];

        return plaintext;
    }

    uint64_t forward_decrypt(uint64_t plaintext) {

        plaintext ^= ekeys_[R];
        plaintext = khazad_reduced::S(plaintext);

        for(int r{R-1}; r > 0; --r) {
            plaintext ^= ekeys_[r];
            plaintext = khazad_reduced::L(plaintext);
            plaintext = khazad_reduced::S(plaintext);
        }

        plaintext ^= ekeys_[0];

        return plaintext;
    }

    uint64_t decrypt(uint64_t plaintext) {

        plaintext ^= ekeys_[R];
        for(int r{1}; r < R;  ++r)
            plaintext = khazad_reduced::T(plaintext) ^ khazad_reduced::L(ekeys_[4-r]);

        plaintext =
                (T0[(byte)(plaintext >> 56)] & uint64_t(0xff00000000000000)) ^
                (T1[(byte)(plaintext >> 48)] & uint64_t(0x00ff000000000000)) ^
                (T2[(byte)(plaintext >> 40)] & uint64_t(0x0000ff0000000000)) ^
                (T3[(byte)(plaintext >> 32)] & uint64_t(0x000000ff00000000)) ^
                (T4[(byte)(plaintext >> 24)] & uint64_t(0x00000000ff000000)) ^
                (T5[(byte)(plaintext >> 16)] & uint64_t(0x0000000000ff0000)) ^
                (T6[(byte)(plaintext >>  8)] & uint64_t(0x000000000000ff00)) ^
                (T7[(byte)(plaintext      )] & uint64_t(0x00000000000000ff)) ^
                ekeys_[0];
        return plaintext;

    }

public:
    block ekeys_[R+1];
};

#endif //CRYPTOGRAPHY_KHAZAD_HPP