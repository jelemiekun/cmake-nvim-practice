cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(myApp LANGUAGES C CXX)

add_executable(myExe
  src/main.cpp
  src/Math.cpp
)

add_library(glad src/glad.c)
target_include_directories(glad PUBLIC include)

find_package(spdlog REQUIRED)
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(myExe PRIVATE spdlog::spdlog glad SDL2::SDL2 OpenGL::GL)

include_directories(${CMAKE_SOURCE_DIR}/include)
