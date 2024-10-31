    /*######################################
    # University of Information Technology
    # IT007 Operating System
    # Nguyễn Trọng Tất Thành, 23521455
    # File: test_shm_B.c
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
        int fd = shm_open(name, O_RDWR, 0666);
        char *ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

        printf("Read shared memory: %s\n", ptr);
        strcpy(ptr, "Hello Process A");
        printf("Shared memory updated: %s\n", ptr);

        munmap(ptr, SIZE);
        close(fd);
        shm_unlink(name);
        return 0;
    }
