cmake_minimum_required(VERSION 3.24)
project(Cryptography C CXX)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/src)

target_link_libraries(Cryptography lib)

target_include_directories(Cryptography PUBLIC ${PROJECT_SOURCE_DIR}/lib/include)