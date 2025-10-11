cmake_minimum_required(VERSION 3.20)

project(MyProject LANGUAGES C CXX)

# --- Common settings ---
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --- Platform-specific logic ---
if (WIN32)
    message(STATUS "Configuring for Windows...")

    # --- vcpkg integration ---
    set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
    set(VCPKG_TARGET_TRIPLET "x64-windows" CACHE STRING "Vcpkg triplet")

    # --- optional explicit vcpkg paths ---
    set(spdlog_DIR "C:/vcpkg/installed/x64-windows/share/spdlog")
    set(fmt_DIR "C:/vcpkg/installed/x64-windows/share/fmt")
    set(SDL2_DIR "C:/vcpkg/installed/x64-windows/share/sdl2")

    # --- dependencies ---
    find_package(spdlog CONFIG REQUIRED)
    find_package(SDL2 CONFIG REQUIRED)

    # --- source ---
    add_executable(MyApp src/main.cpp)

    # --- link everything ---
    target_link_libraries(MyApp PRIVATE
        spdlog::spdlog
        SDL2::SDL2
        SDL2::SDL2main
    )

else() # Linux / Unix-like systems
    message(STATUS "Configuring for Linux...")

    add_executable(myExe
        src/main.cpp
        src/Math.cpp
    )

    add_library(glad src/glad.c)
    target_include_directories(glad PUBLIC include)

    find_package(spdlog REQUIRED)
    find_package(SDL2 REQUIRED)
    find_package(OpenGL REQUIRED)

    target_link_libraries(myExe PRIVATE
        spdlog::spdlog
        glad
        SDL2::SDL2
        OpenGL::GL
    )

    include_directories(${CMAKE_SOURCE_DIR}/include)

endif()
