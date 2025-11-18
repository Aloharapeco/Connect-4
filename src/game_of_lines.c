#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "game_of_lines.h"

int *get_cell(int *arena, int size, int x, int y) {
    return arena + (y * size + x);
}

void scan_settings(Settings *s) {
    printf("Play against computer? 1 = (yes, 0 = no): ");
    scanf("%d", &s->vs_computer);

    printf("Enter board size (example: 5 = 5x5): ");
    scanf("%d", &s->board_size);

    printf("Enter required win length: ");
    scanf("%d", &s->win_length);
}

int scan_move(int board_size) {
    int col;
    printf("Choose column (0 to %d): ", board_size - 1);
    scanf("%d", &col);
    return col;
}

int comp_move(int board_size, int *arena){
    int col;
    while (1) {
        col = rand() % board_size;
        if (*get_cell(arena, board_size, col, 0) == EMPTY)
            return col;
    }
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

static bool check_dir(int *arena, int size, int x, int y, int dx, int dy, int needed)
{
    int start = *get_cell(arena, size, x, y);
    if (start == EMPTY)
        return false;

    for (int i = 1; i < needed; i++)
    {
        int nx = x + dx * i;
        int ny = y + dy * i;

        if (nx < 0 || ny < 0 || nx >= size || ny >= size)
            return false;

        if (*get_cell(arena, size, nx, ny) != start)
            return false;
    }

    return true;
}

int winner_chicken(int *arena, int size, int needed)
{
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            int cell = *get_cell(arena, size, x, y);
            if (cell == EMPTY) continue;

            if (check_dir(arena, size, x, y, 1, 0, needed)) return cell;
            if (check_dir(arena, size, x, y, 0, 1, needed)) return cell;
            if (check_dir(arena, size, x, y, 1, 1, needed)) return cell;
            if (check_dir(arena, size, x, y, -1, 1, needed)) return cell;
        }
    }
    return -1;
}

void game_of_lines(int opponent_is_ai, int size_of_arena, int size_of_win_line) {
    srand(time(NULL));

    int size = size_of_arena;
    int win_length = size_of_win_line;

    int *arena = malloc(sizeof(int) * size * size);

    for (int i = 0; i < size * size; i++)
        arena[i] = EMPTY;

    int whose_turn = 0;
    int the_winner = -1;

    do {
        print_arena(arena, size);
        printf("Player %d's turn.\n", whose_turn);

        int col;
        if (opponent_is_ai == 1 && whose_turn == 1)
            col = comp_move(size, arena);
        else
            col = scan_move(size);

        if (col < 0 || col >= size) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        if (*get_cell(arena, size, col, 0) != EMPTY) {
            printf("Column is full! Try again.\n");
            continue;
        }

        update_arena(arena, size, col, whose_turn);
        whose_turn = 1 - whose_turn;

        the_winner = winner_chicken(arena, size, win_length);

    } while (the_winner == -1);

    print_arena(arena, size);
    printf("Winner Winner Chicken Dinner! Player %d wins!\n", the_winner);

    free(arena);
}
