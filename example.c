#include "log.h"

int main(void)
{
    int foo = 0;
    log_info(stdout, "This is an info message. \t\tfoo = %d", foo++);
    log_debug(stdout, "This is a debug message. \t\tfoo = %d", foo++);
    log_warning(stdout, "This is a warning message. \tfoo = %d", foo++);
    log_error(stdout, "This is an error message. \t\tfoo = %d", foo++);
    log_fatal(stdout, "This is a fatal error message. \tfoo = %d", foo++);
    return 0;
}
