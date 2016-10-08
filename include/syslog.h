#ifndef __SYSLOG_H
#define __SYSLOG_H

extern void log_output(int line, const char* file, const char* level, const char* msg, ...);

#define TRACE(fmt, ...) log_output(__LINE__, __FILE__, "TRACE", fmt, __VA_ARGS__)
#define DEBUG(fmt, ...) log_output(__LINE__, __FILE__, "DEBUG", fmt, __VA_ARGS__)

#endif
