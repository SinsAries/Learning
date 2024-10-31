/*######################################
# University of Information Technology
# IT007 Operating System
# Nguyễn Trọng Tất Thành, 23521455
# File: test_shm_A.c
######################################*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    const int SIZE = 4096;
    const char *name = "OS";
    int fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, SIZE);
    char *ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    strcpy(ptr, "Hello Process B");

    while (strncmp(ptr, "Hello Process A", 15) != 0) {
        printf("Waiting Process B to update shared memory\n");
        sleep(1);
    }
    printf("Memory updated: %s\n", ptr);

    munmap(ptr, SIZE);
    close(fd);
    return 0;
}
