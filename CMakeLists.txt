cmake_minimum_required(VERSION 3.24)
project(Cryptography C CXX)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(Cryptography main.cpp
        KHAZAD.hpp TTables.hpp sbox.hpp Experiment.hpp difference.hpp randomizer.hpp Experiment.cpp randomizer.cpp)
