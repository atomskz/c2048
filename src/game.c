#include <stdlib.h>
#include <memory.h>
#include <c2048/game.h>
#include <c2048/assert.h>

/* Set up game state before the main loop runs. */
status_t game_init(game_state_t *g, grid_size_t grid_size)
{
    status_t status;

    C2048_ASSERT(g != NULL);

    memset(g, 0, sizeof(*g));

    status = board_init(&g->board, grid_size);
    if (IS_ERR(status)) {
        return status;
    }

    board_spawn_tile(&g->board);
    board_spawn_tile(&g->board);

    return C2048_STATUS_OK;
}

void game_deinit(game_state_t *g)
{
    C2048_ASSERT(g != NULL);

    board_deinit(&g->board);
    memset(g, 0, sizeof(*g));
}

/* Run the game. Returns a process exit code. */
exit_code_t game_run(game_state_t *g)
{
    return (exit_code_t)0;
}
