/* example_basic.c */
#include <s_log.h>

int main(void)
{
    int foo = 0;
    s_log(LOG_INFO,    stdout, "This is a message created with LOG_INFO     foo = %d", foo++);
    s_log(LOG_DEBUG,   stdout, "This is a message created with LOG_DEBUG    foo = %d", foo++);
    s_log(LOG_WARNING, stdout, "This is a message created with LOG_WARNING  foo = %d", foo++);
    s_log(LOG_ERROR,   stdout, "This is a message created with LOG_ERROR    foo = %d", foo++);
    s_log(LOG_FATAL,   stdout, "This is a message created with LOG_FATAL    foo = %d", foo++);

    s_log_set_global_threshold(LOG_ERROR); // Log only error and fatal messages.
    s_log(LOG_INFO, stdout,    "some info message");
    s_log(LOG_DEBUG, stdout,   "some debug message");
    s_log(LOG_WARNING, stdout, "some warning message");
    s_log(LOG_ERROR, stdout,   "some error message");
    s_log(LOG_FATAL, stdout,   "some fatal message");

    return 0;
}
