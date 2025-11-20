#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "game_of_lines.h"

// ---------------------------------------------
// Helper: get pointer to arena[x][y]
// ---------------------------------------------
int *get_cell(int *arena, int size, int x, int y) {
    return arena + (y * size + x);
}

// ---------------------------------------------
// Ask: computer opponent? board size? win length?
// ---------------------------------------------
void scan_settings(Settings *s) {
    printf("Play against computer? (1 = yes, 0 = no): ");
    scanf("%d", &s->opponent_is_ai);

    printf("Enter board size (e.g., 7): ");
    scanf("%d", &s->size_of_arena);

    printf("Enter required line length to win: ");
    scanf("%d", &s->size_of_win_line);
}

// ---------------------------------------------
// Ask human for next move
// ---------------------------------------------
int scan_move(int board_size) {
    int col;
    printf("Choose column (0 to %d): ", board_size - 1);
    scanf("%d", &col);
    return col;
}

// ---------------------------------------------
// AI picks a random non-full column
// ---------------------------------------------
int ai_move(int board_size, int *arena) {
    int col;
    do {
        col = rand() % board_size;
        if (*get_cell(arena, board_size, col, 0) == EMPTY)
            return col;
    } while (1);
}

// ---------------------------------------------
// Drop piece into column like Connect-4
// ---------------------------------------------
void update_arena(int *arena, int size, int column, Cell player) {
    for (int y = size - 1; y >= 0; --y) {
        int *cell = get_cell(arena, size, column, y);
        if (*cell == EMPTY) {
            *cell = player;
            return;
        }
    }
}

// ---------------------------------------------
// Print arena
// ---------------------------------------------
void print_arena(int *arena, int size) {
    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            printf("%d ", *get_cell(arena, size, x, y));
        }
        printf("\n");
    }
    printf("\n");
}

// ---------------------------------------------
// Winner check helper: check line in direction dx,dy
// ---------------------------------------------
static bool check_dir(int *arena, int size, int x, int y, int dx, int dy, int needed) {
    Cell start = *get_cell(arena, size, x, y);
    if (start == EMPTY) return false;

    for (int i = 1; i < needed; ++i) {
        int nx = x + dx * i;
        int ny = y + dy * i;
        if (nx < 0 || ny < 0 || nx >= size || ny >= size)
            return false;
        if (*get_cell(arena, size, nx, ny) != start)
            return false;
    }
    return true;
}

// ---------------------------------------------
// Winner: check all cells & directions
// ---------------------------------------------
Cell winner(int *arena, int size, int needed) {
    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            if (check_dir(arena, size, x, y, 1, 0, needed)) return *get_cell(arena, size, x, y);
            if (check_dir(arena, size, x, y, 0, 1, needed)) return *get_cell(arena, size, x, y);
            if (check_dir(arena, size, x, y, 1, 1, needed)) return *get_cell(arena, size, x, y);
            if (check_dir(arena, size, x, y, -1, 1, needed)) return *get_cell(arena, size, x, y);
        }
    }
    return EMPTY;
}

// ---------------------------------------------
// Game loop
// ---------------------------------------------
void game_of_lines(int opponent_is_ai, int size_of_arena, int size_of_win_line) {
    srand(time(NULL));

    int *arena = malloc(sizeof(int) * size_of_arena * size_of_arena);
    for (int i = 0; i < size_of_arena * size_of_arena; i++)
        arena[i] = EMPTY;

    Cell current = PLAYER1;
    Cell win;

    while ((win = winner(arena, size_of_arena, size_of_win_line)) == EMPTY) {
        print_arena(arena, size_of_arena);
        printf("Player %d's turn.\n", current);

        int col;
        if (current == PLAYER2 && opponent_is_ai)
            col = ai_move(size_of_arena, arena);
        else
            col = scan_move(size_of_arena);

        if (col < 0 || col >= size_of_arena) {
            printf("Invalid move!\n");
            continue;
        }

        if (*get_cell(arena, size_of_arena, col, 0) != EMPTY) {
            printf("Column full!\n");
            continue;
        }

        update_arena(arena, size_of_arena, col, current);
        current = (current == PLAYER1 ? PLAYER2 : PLAYER1);
    }

    print_arena(arena, size_of_arena);
    printf("Player %d wins!\n", win);
    free(arena);
}
