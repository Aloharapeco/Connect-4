#include <stdio.h>
#include <stdlib.h>
#include "game_of_lines.h"


int main(void) {
    Settings s;

    // Ask the user for settings
    scan_settings(&s);

    // Start the game
    game_of_lines(s.vs_computer, s.board_size, s.win_length);

    return 0;
}


