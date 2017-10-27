# Simple C Logger

Dead simple logging library based off of a
[similar library](https://github.com/rxi/log.c) by rxi.
Designed to be as minimal and easy-to-use as possible.

## Use

The library comes with two functions, one to set the global level of logging and
one to log a message at a provided log level to given output stream using printf
style formatting.

```C
// Calls to llog with log level less than threshold will not be printed.
// Default threshold is LOG_DEBUG.
void set_global_log_threshold(int threshold);

// Log a message at the specified log level to the provided output stream using
// printf style formatting.
void llog(int level, FILE* stream, const char* format, ...);
```

The five logging levels are (in order of log level):
1. `LOG_DEBUG`
2. `LOG_INFO`
3. `LOG_WARNING`
4. `LOG_ERROR`
5. `LOG_FATAL`

You can include the `log.h` and `log.c` files in a project directly or install
the library locally with `make install`. Installing locally will add `log.h` to
your local include path and add `liblog.a` to your local lib path so that the
library can be linked-to with `-llog`.

Logging is thread safe <sup>citation needed</sup> if `LOG_USE_PTHREAD` is
defined when compiling the library. To build or install the library using
pthread mutex locks run `make build CFLAGS=-DLOG_USE_PTHREAD` or
`make install CFLAGS=-DLOG_USE_PTHREAD`. When built in this manner
you must link your final executable to the pthread library with `-lpthread`.

## Example

```C
/* example_basic.c */
#include <log.h>

int main(void)
{
    int foo = 0;
    llog(LOG_INFO,    stdout, "This is a message created with log_info     foo = %d", foo++);
    llog(LOG_DEBUG,   stdout,   "This is a message created with log_debug    foo = %d", foo++);
    llog(LOG_WARNING, stdout, "This is a message created with log_warning  foo = %d", foo++);
    llog(LOG_ERROR,   stdout,   "This is a message created with log_error    foo = %d", foo++);
    llog(LOG_FATAL,   stdout,   "This is a message created with log_fatal    foo = %d", foo++);

    set_global_log_threshold(LOG_ERROR); // Log only error and fatal messages.
    llog(LOG_INFO, stdout,    "some info message");
    llog(LOG_DEBUG, stdout,   "some debug message");
    llog(LOG_WARNING, stdout, "some warning message");
    llog(LOG_ERROR, stdout,   "some error message");
    llog(LOG_FATAL, stdout,   "some fatal message");

    return 0;
}
```
```sh
$ make build examples
mkdir -p build/
gcc -Wall -Wextra -std=c11 -c -o build/log.o log.c -O3 
ar rcs build/liblog.a build/log.o
gcc -Wall -Wextra -std=c11 -o build/example_basic examples/example_basic.c -I. -Lbuild/ -llog
gcc -Wall -Wextra -std=c11 -o build/example_multithread examples/example_multithread.c -I. -Lbuild/ -llog -pthread
$ ./build/example_basic 
2017-10-27 18:44:34    INFO: This is a message created with log_info     foo = 0
2017-10-27 18:44:34 WARNING: This is a message created with log_warning  foo = 2
2017-10-27 18:44:34   ERROR: This is a message created with log_error    foo = 3
2017-10-27 18:44:34   FATAL: This is a message created with log_fatal    foo = 4
2017-10-27 18:44:34   ERROR: some error message
2017-10-27 18:44:34   FATAL: some fatal message
```

## License
The Unlicense
