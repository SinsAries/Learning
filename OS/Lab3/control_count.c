/***************************************
# University of Information Technology
# IT007 Operating System
# Nguyễn Trọng Tất Thành, 23521455
# File: control_count.c
***************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_signal(int signal) {
    printf("count.sh has stopped\n");
    exit(0);
}

int main() {
    printf("Welcome to IT007, I am 23521455!\n");

    // Thiết lập xử lý tín hiệu để dừng chương trình khi nhấn Ctrl+C
    signal(SIGINT, handle_signal);

    // Tạo tiến trình con và thực thi count.sh
    if (fork() == 0) {
        execl("./count.sh", "count.sh", "120", NULL);
    }

    // Vòng lặp chờ tín hiệu Ctrl+C
    while (1) { }

    return 0;
}
