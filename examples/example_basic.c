/* example_basic.c */
#include <log.h>

int main(void)
{
    int foo = 0;
    flogf(LOG_INFO,    stdout, "This is a message created with LOG_INFO     foo = %d", foo++);
    flogf(LOG_DEBUG,   stdout, "This is a message created with LOG_DEBUG    foo = %d", foo++);
    flogf(LOG_WARNING, stdout, "This is a message created with LOG_WARNING  foo = %d", foo++);
    flogf(LOG_ERROR,   stdout, "This is a message created with LOG_ERROR    foo = %d", foo++);
    flogf(LOG_FATAL,   stdout, "This is a message created with LOG_FATAL    foo = %d", foo++);

    set_global_log_threshold(LOG_ERROR); // Log only error and fatal messages.
    flogf(LOG_INFO, stdout,    "some info message");
    flogf(LOG_DEBUG, stdout,   "some debug message");
    flogf(LOG_WARNING, stdout, "some warning message");
    flogf(LOG_ERROR, stdout,   "some error message");
    flogf(LOG_FATAL, stdout,   "some fatal message");

    return 0;
}
