# Simple C Logger

Dead simple logging library based off of a
[similar library](https://github.com/rxi/log.c) by rxi.
Designed to be as minimal and easy-to-use as possible.

## Use

The library comes with two functions, one to set the global level of logging and
one to log a message at the provided log level to the provided output stream
using printf style formatting.

```C
// Calls to s_log with log level less than threshold will not be printed.
// Default threshold is LOG_DEBUG.
void s_log_set_global_threshold(int threshold);

// Log a message at the specified log level to the provided output stream using
// printf style formatting.
void s_log(int level, FILE* stream, const char* format, ...);
```

The five logging levels are (from lowest to highest log level):
1. `LOG_DEBUG`
2. `LOG_INFO`
3. `LOG_WARNING`
4. `LOG_ERROR`
5. `LOG_FATAL`

You can include the `s_log.h` and `s_log.c` files in a project directly or install
the library locally with `make install`. Installing locally will add `s_log.h` to
your local include path and add `libs_log.a` to your local lib path so that the
library can be linked-to with `-ls_log`.

Logging is thread safe <sup>citation needed</sup> if `S_LOG_USE_PTHREAD` is
defined when compiling the library. To build or install the library using
pthread mutex locks run `make build CFLAGS=-DS_LOG_USE_PTHREAD` or
`make install CFLAGS=-DS_LOG_USE_PTHREAD`. When built in this manner
you must link your final executable to the pthread library with `-lpthread`.

## Example

```C
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
```
```sh
$ make examples CFLAGS=-DS_LOG_USE_PTHREAD
mkdir -p build/
gcc -DS_LOG_USE_PTHREAD -Wall -Wextra -std=c11 -c -o build/s_log.o s_log.c -O3 
ar rcs build/libs_log.a build/s_log.o
gcc -DS_LOG_USE_PTHREAD -Wall -Wextra -std=c11 -o build/example_basic examples/example_basic.c -I. -Lbuild/ -ls_log
gcc -DS_LOG_USE_PTHREAD -Wall -Wextra -std=c11 -o build/example_multithread examples/example_multithread.c -I. -Lbuild/ -ls_log -pthread
$ ./build/example_basic
2017-10-27 19:12:14    INFO: This is a message created with LOG_INFO     foo = 0
2017-10-27 19:12:14 WARNING: This is a message created with LOG_WARNING  foo = 2
2017-10-27 19:12:14   ERROR: This is a message created with LOG_ERROR    foo = 3
2017-10-27 19:12:14   FATAL: This is a message created with LOG_FATAL    foo = 4
2017-10-27 19:12:14   ERROR: some error message
2017-10-27 19:12:14   FATAL: some fatal message
```

## License
The Unlicense
