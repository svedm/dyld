#ifndef BSD_KDEBUG_PRIVATE_H
#define BSD_KDEBUG_PRIVATE_H
#include <stdint.h>
#include <stdbool.h>
#include <sys/cdefs.h>
__BEGIN_DECLS
extern int kdebug_trace(uint32_t debugid, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4);
extern bool kdebug_is_enabled(uint32_t debugid);
extern uint64_t kdebug_trace_string(uint32_t debugid, uint64_t str_id, const char *str);
extern bool kdebug_using_continuous_time(void);
__END_DECLS
#ifndef DBG_DYLD
#define DBG_DYLD 31
#endif
#define DBG_DYLD_UUID 5
#define DBG_DYLD_UUID_MAP_A 0
#ifndef KDBG_CODE
#define KDBG_CODE(Class, SubClass, Code) (((Class & 0xff) << 24) | ((SubClass & 0xff) << 16) | ((Code & 0x3fff) << 2))
#endif
#ifndef KDBG_EVENTID
#define KDBG_EVENTID KDBG_CODE
#endif
#define DBG_FUNC_START 1
#define DBG_FUNC_END   2
#define DBG_FUNC_NONE  0
#endif
