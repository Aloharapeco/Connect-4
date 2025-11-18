#include <stdio.h>
#include <stdlib.h>
#include "game_of_lines.h"

int main(void) {
    int opponent_is_ai;
    int size_of_arena;
    int size_of_win_line;

    // Scan settings from user
    scan_settings(&opponent_is_ai, &size_of_arena, &size_of_win_line);

    // Run the game using the scanned parameters
    game_of_lines(opponent_is_ai, size_of_arena, size_of_win_line);

    return 0;
}
