/* example_basic.c */
#include <log.h>

int main(void)
{
    int foo = 0;
    llog(LOG_INFO,    stdout, "This is a message created with log_info     foo = %d", foo++);
    llog(LOG_DEBUG,   stdout, "This is a message created with log_debug    foo = %d", foo++);
    llog(LOG_WARNING, stdout, "This is a message created with log_warning  foo = %d", foo++);
    llog(LOG_ERROR,   stdout, "This is a message created with log_error    foo = %d", foo++);
    llog(LOG_FATAL,   stdout, "This is a message created with log_fatal    foo = %d", foo++);

    set_global_log_threshold(LOG_ERROR); // Log only error and fatal messages.
    llog(LOG_INFO, stdout,    "some info message");
    llog(LOG_DEBUG, stdout,   "some debug message");
    llog(LOG_WARNING, stdout, "some warning message");
    llog(LOG_ERROR, stdout,   "some error message");
    llog(LOG_FATAL, stdout,   "some fatal message");

    return 0;
}
