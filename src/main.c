#include <stdio.h>
#include <c2048/game.h>

int main(void)
{
    game_state_t game;
    exit_code_t exit_code;
    status_t status;

    printf("c2048 project initialized.\n");

    status = game_init(&game, DEFAULT_GRID_SIZE);
    if (IS_ERR(status)) {
        return -1;
    }

    exit_code = game_run(&game);
    game_deinit(&game);
    
    return exit_code;
}
