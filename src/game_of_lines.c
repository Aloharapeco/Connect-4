#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "game_of_lines.h"
// Implement functions defined in game_of_lines.h

int *get_cell(int *arena, int size, int x, int y) {
    return arena + (y * size + x);
}

void scan_settings(int *opponent_is_ai, int *size_of_arena, int *size_of_win_line, Settings *s) {
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

int comp_move(int board_size, int *arena){
int col;
do {
col = rand() % board_size;
if (*get_cell(arena, board_size, col, 0) = EMPTY)
    return col;
    } while (1);
}
void update_arena(int *arena, int size, int column, Cell player) {
    for (int y = size - 1; y >= 0; --y) {
        int *cell = get_cell(arena, size, column, y);
        if (*cell == EMPTY) {
            *cell = player;
            return;
        }
    }
}

void print_arena(int *arena, int size) {
    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            printf("%d ", *get_cell(arena, size, x, y));
        }
        printf("\n");
    }
    printf("\n");
}