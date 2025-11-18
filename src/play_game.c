#include <stdio.h>
#include <stdlib.h>
#include "game_of_lines.h"


void game_of_lines(int opponent_is_ai, int size_of_arena, int size_of_win_line);

int main(void) {
    int opponent_is_ai;
    int size_of_arena;
    int size_of_win_line;

    // Prompt user for settings
    printf("Play against AI? (1 = yes, 0 = no): ");
    scanf("%d", &opponent_is_ai);

    printf("Enter arena size (e.g., 5 = 5x5): ");
    scanf("%d", &size_of_arena);

    printf("Enter winning line length: ");
    scanf("%d", &size_of_win_line);

    // Run the game
    game_of_lines(opponent_is_ai, size_of_arena, size_of_win_line);
    return 0;
}

void game_of_lines(int opponent_is_ai, int size_of_arena, int size_of_win_line) {
    // Create an arena (e.g. use HINT 1)

    int whose_turn = 0;  // Who should perform the next move: Player 0 or Player/Computer 1?
    int the_winner;
    do {
        // scan_move(...);
        //     or
        // ai_move(...);

        // update_arena(...);

        // print_arena(...);

        // the_winner = winner(...);

    } while (the_winner == -1);

    // Print who won (the_winner).

}

