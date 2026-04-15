#ifndef _PTHREAD_TSD_PRIVATE_H_
#define _PTHREAD_TSD_PRIVATE_H_
#include <pthread.h>
typedef pthread_key_t dyld_thread_key_t;
static inline void *_pthread_getspecific_direct(unsigned long slot) { return NULL; }
static inline void _pthread_setspecific_direct(unsigned long slot, void *val) { (void)slot; (void)val; }
#define __TSD_THREAD_SELF 0
#define __TSD_ERRNO 1
static inline int pthread_key_init_np(int key, void (*destructor)(void *)) { return 0; }
#endif
