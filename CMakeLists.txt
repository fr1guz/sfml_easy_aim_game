cmake_minimum_required(VERSION 3.23)
project(project_aim)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(project_aim main.cpp Game/Game.cpp Game/Game.h Circle/Circle.h Circle/Circle.cpp)

target_link_libraries(project_aim sfml-graphics sfml-audio)