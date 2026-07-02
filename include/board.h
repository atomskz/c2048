#ifndef C2048_BOARD_H
#define C2048_BOARD_H

/*
 * Game board module.
 *
 * Owns the grid state and the operations that mutate it (initialization,
 * tile movement, merging, spawning). Currently a stub.
 */

/* Prepare a fresh, empty board. */
void board_init(void);

#endif /* C2048_BOARD_H */
