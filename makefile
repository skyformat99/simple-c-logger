CC=gcc
override CFLAGS+=-Wall -Wextra -std=c11

BUILD_DIR=build/
EXAMPLE_DIR=examples/
INSTALL_LIB_DIR=/usr/local/lib/
INSTALL_INCLUDE_DIR=/usr/local/include/

LOG_HEADER=log.h
LOG_OBJ=log.o
LOG_LIB=log
LOG_LIB_OUT=lib$(LOG_LIB).a

OPTIMIZATION_LEVEL=-O3

all: build

build: clean
	mkdir -p $(BUILD_DIR)
	gcc $(CFLAGS) -c -o $(BUILD_DIR)$(LOG_OBJ) log.c $(OPTIMIZATION_LEVEL) $(DEFINE_USE_PTHREAD)
	ar rcs $(BUILD_DIR)$(LOG_LIB_OUT) $(BUILD_DIR)$(LOG_OBJ)

install: build
	install $(BUILD_DIR)$(LOG_LIB_OUT) $(INSTALL_LIB_DIR)$(LOG_LIB_OUT)
	install $(LOG_HEADER) $(INSTALL_INCLUDE_DIR)$(LOG_HEADER)

examples: build
	$(CC) $(CFLAGS) -o $(BUILD_DIR)example_basic $(EXAMPLE_DIR)example_basic.c -I. -L$(BUILD_DIR) -l$(LOG_LIB)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)example_multithread $(EXAMPLE_DIR)example_multithread.c -I. -L$(BUILD_DIR) -l$(LOG_LIB) -pthread


clean:
	@rm -rf $(BUILD_DIR)
