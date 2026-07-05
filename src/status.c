#include <stdio.h>
#include <c2048/status.h>

#ifdef NDEBUG
status_t err_return(status_t s)
{
    return s;
}
#else
status_t err_return_at(status_t s, const char *file, int line)
{
    if (s != C2048_STATUS_OK) {
        fprintf(stderr, "c2048: error %d at %s:%d\n", (int)s, file, line);
    }
    return s;
}
#endif
