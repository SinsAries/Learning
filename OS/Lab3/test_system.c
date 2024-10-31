/***************************************
# University of Information Technology
# IT007 Operating System
#
# <Your name>, <Your Student ID>
# File: test_system.c
***************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
    printf("PARENTS | PID = %ld | PPID = %ld\n", (long)getpid(), (long)getppid());

    if (argc > 2)
        printf("PARENTS | There are %d arguments\n", argc - 1);

    // Sử dụng system() để thực thi lệnh
    system("./count.sh 10");

    // In danh sách tham số
    printf("PARENTS | List of arguments: \n");
    for (int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    exit(0);
}
