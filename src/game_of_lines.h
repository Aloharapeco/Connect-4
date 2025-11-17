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
    bool vs_computer;
    int board_size;
    int win_length;
} Settings;

void scan_setting(Settings *s);
int scan_move(int board_size);
int ai_move(int board_size, int *arena);
void update_arena(int *arena, int board_size, int column, Cell player);
Cell winner_chicken_dinner(int *arena, int board_size, int win_length);
void print_arena(int *arena, int size);
int *get_cell(int *arena, int size, int x, int y);

void game_of_lines();

#endif