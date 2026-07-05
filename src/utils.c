#include <stddef.h>
#include <stdlib.h>
#include <c2048/utils.h>
#include <c2048/board.h>

int32_t utils_random_int(int32_t min, int32_t max)
{
    return min + rand() % (max - min + 1);
}

int utils_clamp(int value, int min, int max)
{
    if (value < min) {
        return min;
    }
    if (value > max) {
        return max;
    }
    return value;
}
