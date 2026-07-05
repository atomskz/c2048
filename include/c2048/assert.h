#ifndef C2048_ASSERT_H
#define C2048_ASSERT_H

/*
 * Assertion helpers for programmer-error invariants (things that must never
 * happen if the code is correct). These are distinct from status_t, which
 * reports recoverable runtime failures.
 *
 *   C2048_ASSERT(cond)          checked only when NDEBUG is not defined
 *   C2048_ASSERT_MSG(cond, msg) same, with an extra explanatory message
 *   C2048_PANIC(msg)            unconditional abort (kept even under NDEBUG)
 *
 * All failures funnel through c2048_assert_fail(), a single choke point that
 * is easy to breakpoint or redirect.
 */

#include <stddef.h>

/* Reports the failure and never returns. */
_Noreturn void c2048_assert_fail(const char *cond, const char *msg,
                                 const char *file, int line, const char *func);

#ifdef NDEBUG

#define C2048_ASSERT(cond)          ((void)0)
#define C2048_ASSERT_MSG(cond, msg) ((void)0)

#else

#define C2048_ASSERT(cond)                                                  \
    ((cond) ? (void)0                                                       \
            : c2048_assert_fail(#cond, NULL, __FILE__, __LINE__, __func__))

#define C2048_ASSERT_MSG(cond, msg)                                         \
    ((cond) ? (void)0                                                       \
            : c2048_assert_fail(#cond, (msg), __FILE__, __LINE__, __func__))

#endif /* NDEBUG */

/* Always active, even in release builds: use for irrecoverable invariants. */
#define C2048_PANIC(msg) \
    c2048_assert_fail(NULL, (msg), __FILE__, __LINE__, __func__)

#endif /* C2048_ASSERT_H */
