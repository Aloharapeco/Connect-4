#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "game_of_lines.h"
// Implement functions defined in game_of_lines.h

int *get_cell(int *arena, int size, int x, int y) {
    return arena + (y * size + x);
}

void scan_settings(Settings *s) {
    printf("Play against computer? (press 1 for yes or 0 for no)");
    scanf("%d", (int*)&s->vs_computer);

    printf("Enter a board size (Example 5x5)");
    scanf("%d", &s->board_size);

    printf("Enter Victory Line Length");
    scanf("%d", &s->win_length);
}

int scan_move(int board_size) {
    int col;
    printf("Your turn choose column please (0 to %d)", board_size - 1);
    scanf("%d", &col);
    return col;
}