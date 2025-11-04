/**
 * Filename: finfo.c
 * Assignment: Lab9
 * Course: CPE 2600 112
 */

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }

    struct stat sb;

    if (lstat(argv[1], &sb) == -1) {
        perror("lstat");
        return 1;
    }

    printf("File: %s\n", argv[1]);

    if (S_ISREG(sb.st_mode))
        printf("Type: Regular file\n");
    else if (S_ISDIR(sb.st_mode))
        printf("Type: Directory\n");
    else if (S_ISLNK(sb.st_mode))
        printf("Type: Symbolic link\n");
    else if (S_ISCHR(sb.st_mode))
        printf("Type: Character device\n");
    else if (S_ISBLK(sb.st_mode))
        printf("Type: Block device\n");
    else if (S_ISFIFO(sb.st_mode))
        printf("Type: FIFO/pipe\n");
    else if (S_ISSOCK(sb.st_mode))
        printf("Type: Socket\n");
    else
        printf("Type: Unknown\n");

return 0;
}