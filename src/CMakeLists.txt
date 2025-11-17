cmake_minimum_required(VERSION 3.16)
project(Connect_4 C)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# -------------------------
# Main game library
# -------------------------
# Create a library from game_of_lines.c and game_of_lines.h
add_library(game_of_lines
        src/game_of_lines.c
        src/game_of_lines.h
)

# -------------------------
# Main executable
# -------------------------
add_executable(play_game
        src/play_game.c
)

# Link the library to the main executable
target_link_libraries(play_game PRIVATE game_of_lines)

# -------------------------
# Tests
# -------------------------
enable_testing()

# Add test executable
add_executable(test_game_of_lines
        test/test_game_of_lines.c
)

# Link the library to the test executable
target_link_libraries(test_game_of_lines PRIVATE game_of_lines)

# Register the test with CTest
add_test(NAME test_game_of_lines COMMAND test_game_of_lines)
