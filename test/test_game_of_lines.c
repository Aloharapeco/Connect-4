#include "game_of_lines.h"
#include <assert.h>
#include <stdio.h>

void test_update_arena() {
    int size = 5;
    int *arena = malloc(sizeof(int) * size * size);

    for (int i = 0; i < size * size; i++) arena[i] = EMPTY;

    update_arena(arena, size, 2, PLAYER1);
    update_arena(arena, size, 2, PLAYER2);

    assert(*get_cell(arena, size, 2, 4) == PLAYER1);
    assert(*get_cell(arena, size, 2, 3) == PLAYER2);

    free(arena);
    printf("update_arena passed\n");
}

void test_winner_horizontal() {
    int size = 5;
    int *arena = calloc(size * size, sizeof(int));

    // make horizontal line
    *get_cell(arena, size, 0, 4) = PLAYER1;
    *get_cell(arena, size, 1, 4) = PLAYER1;
    *get_cell(arena, size, 2, 4) = PLAYER1;
    *get_cell(arena, size, 3, 4) = PLAYER1;

    assert(winner(arena, size, 4) == PLAYER1);

    free(arena);
    printf("winner horizontal passed\n");
}

void test_winner_diagonal() {
    int size = 5;
    int *arena = calloc(size * size, sizeof(int));

    *get_cell(arena, size, 0, 4) = PLAYER2;
    *get_cell(arena, size, 1, 3) = PLAYER2;
    *get_cell(arena, size, 2, 2) = PLAYER2;
    *get_cell(arena, size, 3, 1) = PLAYER2;

    assert(winner(arena, size, 4) == PLAYER2);

    free(arena);
    printf("winner diagonal passed\n");
}

int main() {
    test_update_arena();
    test_winner_horizontal();
    test_winner_diagonal();
    printf("All tests passed.\n");
    return 0;
}