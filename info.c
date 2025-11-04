/**
 * Filename: info.c
 * Assignment: Lab9
 * Course: CPE 2600 112
 */

 #include <time.h>
 #include <stdio.h>
 #include <sys/utsname.h>
 #include <sys/sysinfo.h>
 #include <unistd.h>


 int main(int argc, char* argv[]){
    struct timespec current_time;
    struct utsname info;
    struct sysinfo sys_info;

    char hostname[256];
     int online = get_nprocs();

    if (sysinfo(&sys_info) != 0) {
        perror("sysinfo");
        return 1;
    }


    clock_gettime(CLOCK_REALTIME, &current_time);
    if (uname(&info) == -1) {
      perror("uname");
      return 1;
    }
    
    if (gethostname(hostname, sizeof(hostname)) == 0){
    }
    else{
      perror("gethostname");
    }

    unsigned long long total_bytes = (unsigned long long) sys_info.totalram * sys_info.mem_unit;
    unsigned long long free_bytes  = (unsigned long long) sys_info.freeram  * sys_info.mem_unit;
    long long ns_in_day = ((current_time.tv_sec % 86400) * 1000000000LL) + current_time.tv_nsec;



    printf("Time of day: %lld nanoseconds\n", ns_in_day);
    printf("System network name: %s\n", info.nodename);
    printf("System name: %s\n", info.sysname);
    printf("System release: %s\n", info.release);
    printf("System version: %s\n", info.version);
    printf("Machine hardware: %s\n", info.machine);
    printf("Number of CPUs: %d\n", online);
    printf("Total RAM available: %llu\n", total_bytes);
    printf("Total free RAM available: %llu\n", free_bytes);

    return 0;
 }