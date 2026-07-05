#ifndef C2048_GAME_H
#define C2048_GAME_H

#include <c2048/board.h>
#include <c2048/status.h>

/*
 * Game module.
 *
 * Drives the high-level flow: setup, the main turn loop, and teardown.
 * Currently a stub.
 */

#define DEFAULT_GRID_SIZE (4)

typedef int32_t exit_code_t;

typedef struct game_state
{
    score_t total_score;
    board_t board;
} game_state_t;

/* Set up game state before the main loop runs. */
status_t game_init(game_state_t *g, grid_size_t grid_size);

/* deinit */
void game_deinit(game_state_t *g);

/* Run the game. Returns a process exit code. */
exit_code_t game_run(game_state_t *g);

#endif /* C2048_GAME_H */
