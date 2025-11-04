
/**
 * Filename: pmod.c
 * Assignment: Lab9
 * Course: CPE 2600 112
 */


#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

int main(void) {
    errno = 0;
    int old_nice = nice(0);  // Get current nice value
    if (old_nice == -1 && errno != 0) {
        perror("nice");
        return 1;
    }

    // Increase niceness (reduce priority) by 10
    errno = 0;
    int new_nice = nice(10);
    if (new_nice == -1 && errno != 0) {
        perror("nice");
        return 1;
    }

    printf("Changed nice value from %d to %d\n", old_nice, new_nice);

    // Sleep for 1,837,272,638 nanoseconds
    struct timespec req = {1, 837272638};  // 1 second + 837,272,638 ns
    nanosleep(&req, NULL);

    printf("Goodbye from process %d!\n", getpid());
return 0;
}
