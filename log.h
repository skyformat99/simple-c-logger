#ifndef _SIMPLE_C_LOGGER_
#define _SIMPLE_C_LOGGER_

#include <stdio.h>

#define LOG_INFO    0b00001
#define LOG_DEBUG   0b00010
#define LOG_WARNING 0b00100
#define LOG_ERROR   0b01000
#define LOG_FATAL   0b10000
void set_global_log_config(int config);

void log_info   (FILE* stream, const char* format, ...);
void log_debug  (FILE* stream, const char* format, ...);
void log_warning(FILE* stream, const char* format, ...);
void log_error  (FILE* stream, const char* format, ...);
void log_fatal  (FILE* stream, const char* format, ...);

#endif // !_SIMPLE_C_LOGGER
