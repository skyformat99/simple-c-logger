#include "log.h"

#define MAX_BUFF_SIZE 64

#include <stdarg.h>
#include <stddef.h>
#include <time.h>

#ifdef LOG_USE_PTHREAD
#include <pthread.h>
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
#endif // !LOG_USE_PTHREAD

static int LOG_CUTOFF_LEVEL = LOG_INFO;
static const char* const prefix_string[] = {
    "   INFO: ",
    "  DEBUG: ",
    "WARNING: ",
    "  ERROR: ",
    "  FATAL: "
};

// This could be made an atomic_t instead to guarentee thread safety, but it
// would be really unlikely to be needed...
void set_global_log_config(int c)
{
    LOG_CUTOFF_LEVEL = c;
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

void llog(int level, FILE* stream, const char* format, ...)
{
    if (level < LOG_CUTOFF_LEVEL) {
        return;
    }
    va_list args;
    va_start(args, format);
    if (level >= LOG_INFO && level <= LOG_FATAL) {
        _log(stream, prefix_string[level], format, args);
    }
    va_end(args);
}
