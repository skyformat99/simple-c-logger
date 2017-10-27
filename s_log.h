#ifndef _SIMPLE_C_LOGGER_
#define _SIMPLE_C_LOGGER_

#include <stdio.h>

#define LOG_DEBUG   (1 << 0)
#define LOG_INFO    (1 << 1)
#define LOG_WARNING (1 << 2)
#define LOG_ERROR   (1 << 3)
#define LOG_FATAL   (1 << 4)

// Calls to s_log with log level less than threshold will not be printed.
// Default threshold is LOG_DEBUG.
void s_log_set_global_threshold(int threshold);

// Log a message at the specified log level to the provided output stream using
// printf style formatting.
void s_log(int level, FILE* stream, const char* format, ...);

#endif // !_SIMPLE_C_LOGGER
