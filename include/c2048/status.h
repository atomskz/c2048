#ifndef C2048_STATUS_H
#define C2048_STATUS_H

#include  <stdbool.h>

typedef enum status
{
    C2048_STATUS_OK = 0,
    C2048_STATUS_INVALID_PARAMETER,
    C2048_STATUS_GRID_TOO_SMALL,
    C2048_STATUS_GRID_TOO_BIG,
    C2048_STATUS_MEMORY_ALLOC,
}status_t;

#define IS_ERR(code) ((code != C2048_STATUS_OK))

#ifdef NDEBUG

#define ERR(code) err_return((code))
status_t err_return(status_t s);

#else

#define ERR(code) err_return_at((code), __FILE__, __LINE__)
status_t err_return_at(status_t s, const char *file, int line);

#endif /* NDEBUG */

#endif /* C2048_STATUS_H */
