/*######################################
# University of Information Technology
# IT007 Operating System
# Nguyễn Trọng Tất Thành, 23521455
# File: count_with_signal.c
######################################*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("count.sh has stopped\n");
    exit(1);
}

int main() {
    signal(SIGINT, handle_sigint);
    system("./count.sh 120");
    return 0;
}
