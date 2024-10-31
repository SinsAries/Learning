/***************************************
# University of Information Technology
# IT007 Operating System
# Nguyễn Trọng Tất Thành, 23521455
# File: collatz.c
***************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>

void collatz(int n, int *buffer, int *count) {
    buffer[(*count)++] = n;
    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
        buffer[(*count)++] = n;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Cách sử dụng: %s <số nguyên dương>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "Vui lòng nhập một số nguyên dương.\n");
        return 1;
    }

    // Tạo bộ nhớ chia sẻ cho buffer và biến đếm
    int *buffer = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    int *count = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *count = 0;

    if (fork() == 0) {
        // Tiến trình con thực hiện thuật toán Collatz và ghi vào buffer
        collatz(n, buffer, count);
        munmap(buffer, 4096);
        munmap(count, sizeof(int));
        exit(0);
    } else {
        // Tiến trình cha đợi tiến trình con hoàn tất và in ra chuỗi Collatz
        wait(NULL);
        printf("Chuỗi Collatz cho %d: ", n);
        for (int i = 0; i < *count; i++) {
            printf("%d ", buffer[i]);
        }
        printf("\n");

        // Thu hồi bộ nhớ
        munmap(buffer, 4096);
        munmap(count, sizeof(int));
    }

    return 0;
}
