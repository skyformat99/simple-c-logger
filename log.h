#ifndef _SIMPLE_C_LOGGER_
#define _SIMPLE_C_LOGGER_

#include <stdio.h>

#define LOG_DEBUG   0
#define LOG_INFO    1
#define LOG_WARNING 2
#define LOG_ERROR   3
#define LOG_FATAL   4

#define LOG_DEFAULT LOG_DEBUG

// Calls to s_log with log level less than threshold will not be printed.
// Default threshold is LOG_DEBUG.
void set_global_log_threshold(int threshold);

// Log a message at the specified log level to the provided output stream using
// printf style formatting.
void flogf(int level, FILE* stream, const char* format, ...);

#endif // !_SIMPLE_C_LOGGER
