#ifndef C2048_UTILS_H
#define C2048_UTILS_H

#include <stdint.h>

/*
 * Utility module.
 *
 * Small helpers shared across modules that do not belong to any single one.
 */

/* Clamp `value` into the inclusive range [min, max]. */
int utils_clamp(int value, int min, int max);

int32_t utils_random_int(int32_t min, int32_t max);

#endif /* C2048_UTILS_H */
