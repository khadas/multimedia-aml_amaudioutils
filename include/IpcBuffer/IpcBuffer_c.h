#ifndef IpcBuffer_c_
#define IpcBuffer_c_

#ifdef __cplusplus
extern "C" {
#endif

extern void *IpcBuffer_create(const char *name, size_t size);

extern void IpcBuffer_destroy(void *cb);

extern void IpcBuffer_write(void *cb, const unsigned char *buf, int size);

#ifdef __cplusplus
}
#endif

#endif /* IpcBuffer_c_ */

