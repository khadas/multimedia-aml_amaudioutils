#ifndef IpcBuffer_c_
#define IpcBuffer_c_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void *IpcBuffer_create(const char *name, size_t size);

extern void IpcBuffer_destroy(void *cb);

extern void IpcBuffer_write(void *cb, const unsigned char *buf, int size);

extern uint8_t *IpcBuffer_get_ptr(const char *name);

extern uint64_t IpcBuffer_get_wr_pos(const char *name);

#ifdef __cplusplus
}
#endif

#endif /* IpcBuffer_c_ */

