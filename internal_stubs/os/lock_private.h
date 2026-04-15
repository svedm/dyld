#ifndef _OS_LOCK_PRIVATE_H_
#define _OS_LOCK_PRIVATE_H_
#include <os/base.h>
#include <os/lock.h>
#include <stdint.h>
#include <stdbool.h>
static inline bool os_thread_self_restrict_tpro_is_writable(void) { return true; }
static inline void os_thread_self_restrict_tpro_to_rw(void) {}
static inline void os_thread_self_restrict_tpro_to_ro(void) {}
#define os_compiler_barrier() __asm__ __volatile__("" ::: "memory")
typedef uint32_t os_unfair_lock_options_t;
#define OS_UNFAIR_LOCK_NONE 0
#define OS_UNFAIR_LOCK_DATA_SYNCHRONIZATION (1 << 16)
static inline void os_unfair_lock_lock_with_options(os_unfair_lock_t lock, os_unfair_lock_options_t options) {
    (void)options; os_unfair_lock_lock(lock);
}
typedef struct os_unfair_recursive_lock_s {
    os_unfair_lock ourl_lock; uint32_t ourl_count;
} os_unfair_recursive_lock, *os_unfair_recursive_lock_t;
#define OS_UNFAIR_RECURSIVE_LOCK_INIT { OS_UNFAIR_LOCK_INIT, 0 }
static inline void os_unfair_recursive_lock_lock(os_unfair_recursive_lock_t lock) { os_unfair_lock_lock(&lock->ourl_lock); }
static inline void os_unfair_recursive_lock_unlock(os_unfair_recursive_lock_t lock) { os_unfair_lock_unlock(&lock->ourl_lock); }
#endif
