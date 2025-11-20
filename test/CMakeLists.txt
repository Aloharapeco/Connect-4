cmake_minimum_required(VERSION 3.20)
project(Connect_4 C)

set(CMAKE_C_STANDARD 11)

add_executable(play_game
        ../src/play_game.c
        ../src/game_of_lines.c
)
