#ifndef GAME_OF_LINES_H
#define GAME_OF_LINES_H

#include <stdbool.h>

// Define function prototypes, (and new datatypes if you need it).
typedef enum {
    EMPTY = 0,
    PLAYER1 = 1,
    PLAYER2 = 2

} Cell;

typedef struct {
    int vs_computer;
    int board_size;
    int win_length;
} Settings;

int* get_cell(int* arena, int size, int x, int y);
void scan_settings(Settings *s);
int scan_move(int board_size);
int ai_move(int board_size, int *arena);
void update_arena(int *arena, int size, int column, Cell player);
void print_arena(int *arena, int size);
Cell winner(int *arena, int size, int needed);
void game_of_lines(int opponent_is_ai, int size_of_arena, int size_of_win_line);

#endif