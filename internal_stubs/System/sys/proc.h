#include "../../../vendor/xnu/bsd/sys/proc.h"
#include <mach/mach.h>
__BEGIN_DECLS
extern kern_return_t task_read_for_pid(mach_port_t host, int pid, mach_port_t *task);
__END_DECLS
