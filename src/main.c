#include <stdio.h>

#include "game.h"

int main(void)
{
    printf("c2048 project initialized.\n");

    game_init();
    return game_run();
}
