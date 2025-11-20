#include <stdio.h>
#include <stdlib.h>
#include "game_of_lines.h"


int main(void) {
    int opponent_is_ai, size_of_arena, size_of_win_line;
    Settings settings;
    scan_settings(&settings);
    game_of_lines(
    settings.opponent_is_ai,
    settings.size_of_arena,
    settings.size_of_win_line
    );
    return 0;
}
