#include <c2048/assert.h>

#include <stdio.h>
#include <stdlib.h>

_Noreturn void c2048_assert_fail(const char *cond, const char *msg,
                                 const char *file, int line, const char *func)
{
    if (cond != NULL) {
        fprintf(stderr, "c2048: assertion failed: %s", cond);
    } else {
        fprintf(stderr, "c2048: panic");
    }

    if (msg != NULL) {
        fprintf(stderr, " -- %s", msg);
    }

    fprintf(stderr, "\n  at %s:%d (%s)\n", file, line, func);

    abort();
}
