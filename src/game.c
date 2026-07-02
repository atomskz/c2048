#include "game.h"

#include "board.h"
#include "render.h"

void game_init(void)
{
    board_init();
    /* TODO: reset score and any other game state. */
}

int game_run(void)
{
    render_draw();
    /* TODO: implement the main game loop (input -> move -> spawn -> redraw). */
    return 0;
}
