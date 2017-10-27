#ifndef _SIMPLE_C_LOGGER_
#define _SIMPLE_C_LOGGER_

#include <stdio.h>

#define LOG_INFO    0
#define LOG_DEBUG   1
#define LOG_WARNING 2
#define LOG_ERROR   3
#define LOG_FATAL   4

void set_global_log_config(int config);
void llog(int level, FILE* stream, const char* format, ...);

#endif // !_SIMPLE_C_LOGGER
