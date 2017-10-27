/* example_multithread.c */
#include <log.h>
#include <pthread.h>

#define NTHREADS 5

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
void* log_nums(void* arg)
{
    for (int i = 0; i < 1000; ++i)
        llog(LOG_INFO, stdout, "%d", i);
    return NULL;
}
#pragma GCC diagnostic pop

int main(void)
{
    pthread_t threads[NTHREADS];
    for (int i = 0; i < NTHREADS; ++i)
        pthread_create(&threads[i], NULL, log_nums, NULL);
    for (int i = 0; i < NTHREADS; ++i)
        pthread_join(threads[0], NULL);
    return 0;
}
