cmake_minimum_required(VERSION 3.23)

project(CrazyPandaChessEngine VERSION 0.1 LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(CrazyPandaChessEngine)

target_sources(CrazyPandaChessEngine PRIVATE
    src/main.cpp src/board.cpp
)
