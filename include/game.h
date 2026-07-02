#ifndef C2048_GAME_H
#define C2048_GAME_H

/*
 * Game module.
 *
 * Drives the high-level flow: setup, the main turn loop, and teardown.
 * Currently a stub.
 */

/* Set up game state before the main loop runs. */
void game_init(void);

/* Run the game. Returns a process exit code. */
int game_run(void);

#endif /* C2048_GAME_H */
