#include "utils.h"

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
