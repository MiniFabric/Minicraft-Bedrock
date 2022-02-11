cmake_minimum_required(VERSION 3.20)
project(MiniCraft)

set(CMAKE_CXX_STANDARD 23)  # required for MSVC

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
	include(FetchContent)
	FetchContent_Declare(
			raylib
			GIT_REPOSITORY https://github.com/raysan5/raylib.git
			GIT_TAG 4.0.0
	)
	FetchContent_GetProperties(raylib)
	if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
		set(FETCHCONTENT_QUIET NO)
		FetchContent_Populate(raylib)
		set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
		set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)
		set(BUILD_TESTING  OFF CACHE BOOL "" FORCE)
		add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
	endif()
endif()

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
	include(FetchContent)
	FetchContent_Declare(
			raylib_cpp
			GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
			GIT_TAG v4.0.4
	)
	FetchContent_GetProperties(raylib_cpp)
	if (NOT raylib_cpp_POPULATED) # Have we downloaded raylib-cpp yet?
		set(FETCHCONTENT_QUIET NO)
		FetchContent_Populate(raylib_cpp)
		add_subdirectory(${raylib_cpp_SOURCE_DIR} ${raylib_cpp_BINARY_DIR})
	endif()
endif()

add_executable( MiniCraft
		src/main.cpp
		src/CApp.cpp
		src/CApp.hpp
		src/input/InputHandler.hpp
		src/input/InputHandler.cpp
		src/input/CKey.cpp
		src/input/CKey.hpp
		src/Const.hpp
		src/core/io/CKey.cpp src/core/io/CKey.hpp src/core/io/InputHandler.cpp src/core/io/InputHandler.hpp src/core/io/Keys.hpp)

target_link_libraries(MiniCraft PUBLIC raylib raylib_cpp)
target_include_directories( MiniCraft PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/cmake-build-debug-wsl-msvc/_deps/raylib-src/include
		${CMAKE_CURRENT_SOURCE_DIR}/cmake-build-debug-wsl-msvc/_deps/raylib_cpp-src/include
)


# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
	target_link_libraries(${PROJECT_NAME} "-framework IOKit")
	target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
	target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
