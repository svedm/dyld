#ifndef _LIBC_PRIVATE_H_
#define _LIBC_PRIVATE_H_
#include <stdlib.h>
__BEGIN_DECLS
extern void abort_report_np(const char *fmt, ...) __dead2 __printflike(1, 2);
__END_DECLS
#endif
