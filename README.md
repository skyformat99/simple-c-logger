# Simple C Logger

Dead simple logging library based off of a [similar library](https://github.com/rxi/log.c) by rxi.

## Use

The library comes with five functions, all of which take an output `FILE*` as
their first argument and a `printf`-style format string with parameters as
following arguments. The functions are identical in all ways except for the
string used for their "log-level".

```C
void log_info   (FILE* stream, const char* format, ...);
void log_debug  (FILE* stream, const char* format, ...);
void log_warning(FILE* stream, const char* format, ...);
void log_error  (FILE* stream, const char* format, ...);
void log_fatal  (FILE* stream, const char* format, ...);
```

You can include the `log.h` and `log.c` files in a project directly or install
the library locally with `make install`. Installing locally will add `log.h` to
your local include path and add `liblog.a` to your local lib path so that the
library can be linked to with `-llog`.

## Example

```C
/* example.c */
#include <log.h>

int main(void)
{
    int foo = 0;
    log_info(stdout,    "This is a message created with log_info     foo = %d", foo++);
    log_debug(stdout,   "This is a message created with log_debug    foo = %d", foo++);
    log_warning(stdout, "This is a message created with log_warning  foo = %d", foo++);
    log_error(stdout,   "This is a message created with log_error    foo = %d", foo++);
    log_fatal(stdout,   "This is a message created with log_fatal    foo = %d", foo++);
    return 0;
}
```
```sh
$ make example 
mkdir -p build/
gcc -Wall -Wextra -std=c11 -c -o build/log.o log.c -O3
ar rcs build/liblog.a build/log.o
gcc -Wall -Wextra -std=c11 -o build/example example.c -I. -Lbuild/ -llog
$ ./build/example 
2017-10-25 17:45:27    INFO: This is a message created with log_info     foo = 0
2017-10-25 17:45:27   DEBUG: This is a message created with log_debug    foo = 1
2017-10-25 17:45:27 WARNING: This is a message created with log_warning  foo = 2
2017-10-25 17:45:27   ERROR: This is a message created with log_error    foo = 3
2017-10-25 17:45:27   FATAL: This is a message created with log_fatal    foo = 4
```

## License
The Unlicense
