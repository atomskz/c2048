#include <stdlib.h>
#include <memory.h>
#include <c2048/board.h>
#include <c2048/assert.h>
#include <c2048/utils.h>

static void cell_swap(cell_t *cell_a, cell_t *cell_b)
{
    cell_t temp;

    C2048_ASSERT(cell_a != NULL && cell_b != NULL);

    temp = *cell_a;
    *cell_a = *cell_b;
    *cell_b = temp;
}

static score_t cell_merge(cell_t *cell_a, cell_t *cell_b)
{
    score_t new_score;

    C2048_ASSERT(cell_a != NULL && cell_b != NULL);

    new_score = *cell_a + *cell_b;
    *cell_a = new_score;
    *cell_b = 0;

    return new_score;
}

static move_result_t board_move_left(board_t *b)
{
    cell_t *cell;
    grid_size_t i;
    grid_size_t row;
    grid_size_t col;
    move_result_t r;

    C2048_ASSERT(b != NULL && b->grid != NULL);

    r.changed = false;
    r.score = 0;

    for (row  = 0; row < b->size; row++) {
        for (col = 0; col < b->size - 1; col++) {
            
            cell = &b->grid[row][col];
            
            if (*cell == EMPTY_cELL) {
                for (i = col + 1; i < b->size; i++) {
                    if (b->grid[row][i] != EMPTY_cELL) {
                        break;
                    }
                }

                if (i == b->size) {
                    break;
                }

                cell_swap(cell, &b->grid[row][i]);
                r.changed = true;
            }

            for (i = col + 1; i < b->size; i++) {
                if (b->grid[row][i] == EMPTY_cELL) {
                    continue;
                }

                if (*cell != b->grid[row][i]) {
                    break;
                }
                
                r.score += cell_merge(cell, &b->grid[row][i]);
                r.changed = true;
                break;
            }
        }
    }

    return r;
}

static move_result_t board_move_right(board_t *b)
{
    cell_t *cell;
    grid_size_t i;
    grid_size_t row;
    grid_size_t col;
    move_result_t r;

    C2048_ASSERT(b != NULL && b->grid != NULL);

    r.changed = false;
    r.score = 0;

    for (row = 0; row < b->size; row++) {
        for (col = b->size; col-- > 1; ) {

            cell = &b->grid[row][col];

            if (*cell == EMPTY_cELL) {

                for (i = col; i >= 0; i--) {
                    if (b->grid[row][i] != EMPTY_cELL) {
                        break;
                    }
                }

                if (i == (grid_size_t)-1) {
                    break;
                }

                cell_swap(cell, &b->grid[row][i]);
                r.changed = true;
            }

            for (i = col - 1; i >= 0; i--) {
                if (b->grid[row][i] == EMPTY_cELL) {
                    continue;
                }

                if (*cell != b->grid[row][i]) {
                    break;
                }

                r.score += cell_merge(cell, &b->grid[row][i]);
                r.changed = true;
                break;
            }
        }
    }

    return r;
}

static move_result_t board_move_top(board_t *b)
{
    cell_t *cell;
    grid_size_t i;
    grid_size_t row;
    grid_size_t col;
    move_result_t r;

    C2048_ASSERT(b != NULL && b->grid != NULL);

    r.changed = false;
    r.score = 0;

    for (col = 0; col < b->size; col++) {
        for (row = 0; row < b->size - 1; row++) {

            cell = &b->grid[row][col];

            if (*cell == EMPTY_cELL) {

                for (i = row + 1; i < b->size; i++) {
                    if (b->grid[i][col] != EMPTY_cELL) {
                        break;
                    }
                }

                if (i == b->size) {
                    break;
                }

                cell_swap(cell, &b->grid[i][col]);
                r.changed = true;
            }

            for (i = row + 1; i < b->size; i++) {
                if (b->grid[i][col] == EMPTY_cELL) {
                    continue;
                }

                if (*cell != b->grid[i][col]) {
                    break;
                }

                r.score += cell_merge(cell, &b->grid[i][col]);
                r.changed = true;
                break;
            }
        }
    }

    return r;
}

static move_result_t board_move_bottom(board_t *b)
{
    cell_t *cell;
    grid_size_t i;
    grid_size_t row;
    grid_size_t col;
    move_result_t r;

    C2048_ASSERT(b != NULL && b->grid != NULL);

    r.changed = false;
    r.score = 0;

    for (col = 0; col < b->size; col++) {
        for (row = b->size; row-- > 1; ) {

            cell = &b->grid[row][col];

            if (*cell == EMPTY_cELL) {

                for (i = row; i >= 0; i--) {
                    if (b->grid[i][col] != EMPTY_cELL) {
                        break;
                    }
                }

                if (i == (grid_size_t)-1) {
                    break;
                }

                cell_swap(cell, &b->grid[i][col]);
                r.changed = true;
            }

            for (i = row - 1; i >= 0; i--) {
                if (b->grid[i][col] == EMPTY_cELL) {
                    continue;
                }

                if (*cell != b->grid[i][col]) {
                    break;
                }

                r.score += cell_merge(cell, &b->grid[i][col]);
                r.changed = true;
                break;
            }
        }
    }

    return r;
}

static void board_grid_deinit(grid_t *grid, grid_size_t size)
{
    grid_size_t row;

    C2048_ASSERT(grid != NULL);

    for (row = 0; row < size; row++) {
        if ((*grid)[row] != NULL) {
            free((*grid)[row]);
        }
    }

    free(*grid);
    *grid = NULL;
}

static status_t board_grid_init(grid_t *grid, grid_size_t size)
{
    grid_size_t row;

    C2048_ASSERT(grid != NULL);

    *grid = (cell_t **)calloc(size, sizeof(cell_t *));
    if (*grid == NULL) {
        return ERR(C2048_STATUS_MEMORY_ALLOC);
    }

    for (row = 0; row < size; row++) {
        (*grid)[row] = (cell_t *)calloc(size, sizeof(cell_t));
        if ((*grid)[row] == NULL) {
            board_grid_deinit(grid, size);
            return ERR(C2048_STATUS_MEMORY_ALLOC);
        }
    }

    return C2048_STATUS_OK;
}

status_t board_init(board_t *b, grid_size_t grid_size)
{
    status_t status;

    C2048_ASSERT(b != NULL);

    if (grid_size < MIN_GRID_SIZE) {
        return ERR(C2048_STATUS_GRID_TOO_SMALL);
    }

    if (grid_size > MAX_GRID_SIZE) {
        return ERR(C2048_STATUS_GRID_TOO_BIG);
    }

    status = board_grid_init(&b->grid, grid_size);
    if (IS_ERR(status)) {
        return status;
    }

    b->size = grid_size;

    return C2048_STATUS_OK;
}

void board_deinit(board_t *b)
{
    C2048_ASSERT(b != NULL && b->grid != NULL);

    board_grid_deinit(&b->grid, b->size);
    memset(b, 0, sizeof(*b));
}

move_result_t board_move(board_t *b, board_move_dir_t dir)
{
    C2048_ASSERT(b != NULL);

    switch (dir)
    {
        case MOVE_LEFT:   return board_move_left(b);
        case MOVE_RIGHT:  return board_move_right(b);
        case MOVE_TOP:    return board_move_top(b);
        case MOVE_BOTTOM: return board_move_bottom(b);
    }

    C2048_PANIC("dir invalid parameter");
    return (move_result_t){0, false};
}

uint32_t board_count_empty(board_t *b)
{
    uint32_t count_empty;
    grid_size_t row;
    grid_size_t col;

    C2048_ASSERT(b != NULL && b->grid != NULL);

    count_empty = 0;

    for (row = 0; row < b->size; row++) {
        for (col = 0; col < b->size; col++) {
            if (b->grid[row][col] == EMPTY_cELL) {
                count_empty++;
            }
        }
    }

    return count_empty;
}

bool board_spawn_tile(board_t *b)
{
    uint32_t count_empty;
    int32_t target;
    cell_t value;
    grid_size_t row;
    grid_size_t col;

    C2048_ASSERT(b != NULL && b->grid != NULL);

    count_empty = board_count_empty(b);
    if (count_empty == 0) {
        return false;
    }

    /* Choose the k-th empty cell (0-based) and its value up front:
       exactly two RNG draws, independent of how full the board is. */
    target = utils_random_int(0, (int32_t)count_empty - 1);
    value  = (utils_random_int(0, 9) == 0) ? 4 : 2;   /* 4 -> 10%, 2 -> 90% */

    for (row = 0; row < b->size; row++) {
        for (col = 0; col < b->size; col++) {
            if (b->grid[row][col] != EMPTY_cELL) {
                continue;
            }
            if (target == 0) {
                b->grid[row][col] = value;
                return true;
            }
            target--;
        }
    }

    C2048_PANIC("empty count inconsistent with grid");
    return false;
}
