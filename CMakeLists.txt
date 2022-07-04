cmake_minimum_required(VERSION 3.0.0)
project(bbc6minute VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

add_executable(bbc6minute src/main.cpp)
target_include_directories(bbc6minute PUBLIC src/header/)