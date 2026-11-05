#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <time.h>

#define COUNT 1000

void *thread_function(void *arg) {
    return NULL;
}

double get_time() {
    struct timespec t;

    clock_gettime(CLOCK_MONOTONIC, &t);

    return t.tv_sec + t.tv_nsec / 1000000000.0;
}

int main() {
    double start, end;
    pid_t pid;

    // Create 1000 processes
    start = get_time();

    for (int i = 0; i < COUNT; i++) {
        pid = fork();

        if (pid == 0)
            _exit(0);

        if (pid < 0) {
            perror("fork");
            return 1;
        }

        waitpid(pid, NULL, 0);
    }

    end = get_time();

    printf("1000 processes time: %.6f seconds\n",
           end - start);

    // Create 1000 threads
    pthread_t thread;

    start = get_time();

    for (int i = 0; i < COUNT; i++) {
        if (pthread_create(&thread, NULL,
                           thread_function, NULL) != 0) {
            printf("Thread creation failed\n");
            return 1;
        }

        pthread_join(thread, NULL);
    }

    end = get_time();

    printf("1000 threads time: %.6f seconds\n",
           end - start);

    return 0;
}
