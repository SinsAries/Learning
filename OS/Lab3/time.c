/***************************************
# University of Information Technology
# IT007 Operating System
# Nguyễn Trọng Tất Thành, 23521455
# File: time.c
***************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    struct timeval start, end;
    pid_t pid;

    // Lấy mốc thời gian trước khi fork
    gettimeofday(&start, NULL);

    pid = fork();

    if (pid == 0) {
        // Tiến trình con thực thi lệnh shell
        execvp(argv[1], &argv[1]);
        perror("execvp failed");
        return 1;
    } else if (pid > 0) {
        // Tiến trình cha đợi tiến trình con kết thúc
        wait(NULL);
        // Lấy mốc thời gian sau khi tiến trình con kết thúc
        gettimeofday(&end, NULL);

        // Tính toán thời gian thực thi
        double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
        printf("Thời gian thực thi: %f giây\n", elapsed_time);
    } else {
        // Xử lý lỗi fork
        perror("fork failed");
        return 1;
    }

    return 0;
}
