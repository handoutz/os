#ifndef __SYSLOG_H
#define __SYSLOG_H
#include <system.h>
#ifdef __cplusplus
extern "C" {
#endif

extern void log_output(int line, const char *file, const char *level, const char *msg, ...);
extern void log_service(CSTRING svc, CSTRING fmt, ...);
#ifdef __cplusplus
};
#endif

#define TRACE(fmt, ...) log_output(__LINE__, __FILE__, "TRACE", fmt, __VA_ARGS__)
#define DEBUG(fmt, ...) log_output(__LINE__, __FILE__, "DEBUG", fmt, __VA_ARGS__)

#endif
