
/**
 * Filename: pinfo.c
 * Assignment: Lab9
 * Course: CPE 2600 112
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sched.h>
#include <sys/resource.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    if (argc > 2) {
        fprintf(stderr, "Usage: %s [pid]\n", argv[0]);
        return 1;
    }

    pid = (argc == 2) ? atoi(argv[1]) : getpid();

    // Get priority
    errno = 0;
    int priority = getpriority(PRIO_PROCESS, pid);
    if (errno != 0) {
        perror("getpriority");
        return 1;
    }

    // Get scheduler
    int sched = sched_getscheduler(pid);
    if (sched == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    // Decode scheduler type
    const char *sched_name;
    switch (sched) {
        case SCHED_OTHER: sched_name = "SCHED_OTHER"; break;
        case SCHED_BATCH: sched_name = "SCHED_BATCH"; break;
        case SCHED_IDLE:  sched_name = "SCHED_IDLE";  break;
        case SCHED_FIFO:  sched_name = "SCHED_FIFO";  break;
        case SCHED_RR:    sched_name = "SCHED_RR";    break;
        default: sched_name = "UNKNOWN"; break;
    }

    printf("Process ID:        %d\n", pid);
    printf("Priority (nice):   %d\n", priority);
    printf("Scheduling policy: %s\n", sched_name);

return 0;
}
