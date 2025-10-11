cmake_minimum_required(VERSION 3.20)

project(myApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(myExe 
  src/main.cpp
  src/Math.cpp
)

find_package(spdlog REQUIRED)
target_link_libraries(myExe PRIVATE spdlog::spdlog)

include_directories(${CMAKE_SOURCE_DIR}/include)
