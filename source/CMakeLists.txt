cmake_minimum_required(VERSION 3.20)

project(myApp LANGUAGES CXX)

add_executable(myExe main.cpp Math.cpp)

find_package(spdlog REQUIRED)
target_link_libraries(myExe PRIVATE spdlog::spdlog)
