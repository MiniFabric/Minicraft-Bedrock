cmake_minimum_required(VERSION 3.20)
project(MiniCraft)

set(CMAKE_CXX_STANDARD 20)

find_package( SDL2 REQUIRED )
include_directories( MiniCraft ${SDL2_INCLUDE_DIRS} )

add_executable(MiniCraft src/main.cpp src/CApp.cpp src/CApp.hpp src/InputHandler.hpp src/InputHandler.cpp src/CKey.cpp src/CKey.hpp)
target_link_libraries(MiniCraft SDL2)