/***************************************
# University of Information Technology
# IT007 Operating System
# Nguyễn Trọng Tất Thành, 23521455
# File: example_signal.c
***************************************/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// Hàm xử lý tín hiệu
void signal_handler(int sig) {
    printf("Received signal: %d\n", sig);
}

int main() {
    // Đăng ký hàm xử lý tín hiệu SIGINT
    signal(SIGINT, signal_handler);

    // Vòng lặp vô hạn, đợi tín hiệu
    while (1) {
        printf("Waiting for signal...\n");
        sleep(1);
    }

    return 0;
}
