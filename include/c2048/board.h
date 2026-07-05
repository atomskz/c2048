#ifndef C2048_BOARD_H
#define C2048_BOARD_H

#include <stdint.h>
#include <stdbool.h>
#include <c2048/status.h>

#define MIN_GRID_SIZE (3)
#define MAX_GRID_SIZE (8)
#define EMPTY_cELL (0)
/*
 * Game board module.
 *
 * Owns the grid state and the operations that mutate it (initialization,
 * tile movement, merging, spawning). Currently a stub.
 */

typedef int32_t grid_size_t;
typedef uint32_t cell_t;
typedef cell_t **grid_t;
typedef size_t score_t;

typedef struct board
{
    grid_size_t size;
    grid_t grid;
} board_t;

typedef struct move_result {
    score_t score;
    bool changed;
} move_result_t;

typedef enum board_move_dir
{
    MOVE_LEFT,
    MOVE_RIGHT,
    MOVE_TOP,
    MOVE_BOTTOM
} board_move_dir_t;

/* Prepare board. */
status_t board_init(board_t *b, grid_size_t grid_size);

void board_deinit(board_t *b);

move_result_t board_move(board_t *b, board_move_dir_t dir);

uint32_t board_count_empty(board_t *b);

bool board_spawn_tile(board_t *b);

#endif /* C2048_BOARD_H */
