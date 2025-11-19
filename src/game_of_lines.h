#ifndef GAME_OF_LINES_H
#define GAME_OF_LINES_H

#include <stdbool.h>

typedef enum {
    EMPTY = 0,
    PLAYER1 = 1,
    PLAYER2 = 2
} Cell;

typedef struct {
    int opponent_is_ai;
    int size_of_arena;
    int size_of_win_line;
} Settings;

int* get_cell(int* arena, int size, int x, int y);
void scan_settings(Settings *s);
int scan_move(int board_size);
int comp_move(int board_size, int *arena);
void update_arena(int *arena, int size, int column, Cell player);
void print_arena(int *arena, int size);
int winner_chicken(int *arena, int size, int needed);
void game_of_lines(int opponent_is_ai, int size_of_arena, int size_of_win_line);

#endif
