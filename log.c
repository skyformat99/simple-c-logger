#include "log.h"

#define STR_INFO    "   INFO: "
#define STR_DEBUG   "  DEBUG: "
#define STR_WARNING "WARNING: "
#define STR_ERROR   "  ERROR: "
#define STR_FATAL   "  FATAL: "
#define MAX_BUFF_SIZE 64

#include <stdarg.h>
#include <stddef.h>
#include <time.h>

#ifdef LOG_USE_PTHREAD
#include <pthread.h>
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
#endif // !LOG_USE_PTHREAD

static int config = LOG_INFO | LOG_DEBUG | LOG_WARNING | LOG_ERROR | LOG_FATAL;
void set_global_log_config(int c)
{
    config = c;
}
static void _log(FILE* stream, const char* logstr, const char* format, va_list args)
{
    char buff[MAX_BUFF_SIZE];
    const time_t currt = time(NULL);

    #ifdef LOG_USE_PTHREAD
    pthread_mutex_lock(&mutex);
    #endif // !LOG_USE_PTHREAD

    const struct tm* localt = localtime(&currt);
    strftime(buff, MAX_BUFF_SIZE, "%F %T", localt);
    fprintf(stream, "%s %s", buff, logstr);
    vfprintf(stream, format, args);
    fputc('\n', stream);
    fflush(stream);

    #ifdef LOG_USE_PTHREAD
    pthread_mutex_unlock(&mutex);
    #endif // !LOG_USE_PTHREAD
}

void log_info(FILE* stream, const char* format, ...)
{
    if (!(config & LOG_INFO)) return;
    va_list args;
    va_start(args, format);
    _log(stream, STR_INFO, format, args);
    va_end(args);
}

void log_debug(FILE* stream, const char* format, ...)
{
    if (!(config & LOG_DEBUG)) return;
    va_list args;
    va_start(args, format);
    _log(stream, STR_DEBUG, format, args);
    va_end(args);
}

void log_warning(FILE* stream, const char* format, ...)
{
    if (!(config & LOG_WARNING)) return;
    va_list args;
    va_start(args, format);
    _log(stream, STR_WARNING, format, args);
    va_end(args);
}

void log_error(FILE* stream, const char* format, ...)
{
    if (!(config & LOG_ERROR)) return;
    va_list args;
    va_start(args, format);
    _log(stream, STR_ERROR, format, args);
    va_end(args);
}

void log_fatal(FILE* stream, const char* format, ...)
{
    if (!(config & LOG_FATAL)) return;
    va_list args;
    va_start(args, format);
    _log(stream, STR_FATAL, format, args);
    va_end(args);
}
