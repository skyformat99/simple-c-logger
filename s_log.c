#include "s_log.h"

#define MAX_BUFF_SIZE 64

#include <stdarg.h>
#include <stddef.h>
#include <time.h>

#ifdef S_LOG_USE_PTHREAD
#include <pthread.h>
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
#endif // !S_LOG_USE_PTHREAD

static int LOG_CUTOFF_LEVEL = LOG_DEFAULT;
static const char* const prefix_string[] = {
    "   INFO: ",
    "  DEBUG: ",
    "WARNING: ",
    "  ERROR: ",
    "  FATAL: "
};

void s_log_set_global_threshold(int threshold)
{
    LOG_CUTOFF_LEVEL = threshold;
}

static void _log(FILE* stream, const char* logstr, const char* format, va_list args)
{
    char buff[MAX_BUFF_SIZE];
    const time_t currt = time(NULL);

    #ifdef S_LOG_USE_PTHREAD
    pthread_mutex_lock(&mutex);
    #endif // !S_LOG_USE_PTHREAD

    const struct tm* localt = localtime(&currt);
    strftime(buff, MAX_BUFF_SIZE, "%F %T", localt);
    fprintf(stream, "%s %s", buff, logstr);
    vfprintf(stream, format, args);
    fputc('\n', stream);
    fflush(stream);

    #ifdef S_LOG_USE_PTHREAD
    pthread_mutex_unlock(&mutex);
    #endif // !S_LOG_USE_PTHREAD
}

void s_log(int level, FILE* stream, const char* format, ...)
{
    if (level < LOG_CUTOFF_LEVEL)
    {
        return;
    }

    va_list args;
    va_start(args, format);
    if (level >= LOG_DEBUG && level <= LOG_FATAL)
    {
        _log(stream, prefix_string[level], format, args);
    }
    va_end(args);
}
