/* example_basic.c */
#include <log.h>

int main(void)
{
    int foo = 0;
    log_info(stdout,    "This is a message created with log_info     foo = %d", foo++);
    log_debug(stdout,   "This is a message created with log_debug    foo = %d", foo++);
    log_warning(stdout, "This is a message created with log_warning  foo = %d", foo++);
    log_error(stdout,   "This is a message created with log_error    foo = %d", foo++);
    log_fatal(stdout,   "This is a message created with log_fatal    foo = %d", foo++);


    set_global_log_config(LOG_ERROR | LOG_FATAL); // Log only error and fatal messages.
    log_info(stdout,    "some info message");
    log_debug(stdout,   "some debug message");
    log_warning(stdout, "some warning message");
    log_error(stdout,   "some error message");
    log_fatal(stdout,   "some fatal message");

    return 0;
}
