/***************************************
# University of Information Technology
# IT007 Operating System
# Nguyễn Trọng Tất Thành, 23521455
# File: producer_consumer.c
***************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <time.h>

#define SIZE 10

int main() {
    const char *name = "buffer";
    int fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, SIZE * sizeof(int));
    int *buffer = mmap(0, SIZE * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    // Cờ dừng để báo cho Producer dừng khi Consumer kết thúc
    int *stop_flag = mmap(0, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *stop_flag = 0;

    if (fork() == 0) {
        // Tiến trình con (Consumer)
        int sum = 0, index = 0;
        while (sum <= 100) {
            if (buffer[index] != 0) {
                sum += buffer[index];
                printf("Consumer: Đọc %d từ bộ đệm, Tổng hiện tại = %d\n", buffer[index], sum);
                buffer[index] = 0;
                index = (index + 1) % SIZE;
                sleep(1);
            }
        }
        printf("Consumer: Tổng vượt quá 100. Dừng lại.\n");
        *stop_flag = 1;  // Đặt cờ dừng
        munmap(buffer, SIZE * sizeof(int));
        munmap(stop_flag, sizeof(int));
        close(fd);
        shm_unlink(name);
        exit(0);
    } else {
        // Tiến trình cha (Producer)
        srand(time(NULL));
        int index = 0;
        while (*stop_flag == 0) {  // Dừng khi cờ stop_flag được bật
            if (buffer[index] == 0) {
                int num = rand() % 11 + 10;
                buffer[index] = num;
                printf("Producer: Ghi %d vào bộ đệm\n", num);
                index = (index + 1) % SIZE;
                sleep(1);
            }
        }
        wait(NULL);
        munmap(buffer, SIZE * sizeof(int));
        munmap(stop_flag, sizeof(int));
        close(fd);
        shm_unlink(name);
    }

    return 0;
}
