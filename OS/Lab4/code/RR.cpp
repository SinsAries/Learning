#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

#define SORT_BY_ARRIVAL 0
#define SORT_BY_PID 1
#define SORT_BY_BURST 2
#define SORT_BY_START 3

typedef struct 
{
    int iPID;
    int iArrival;
    int iBurst;
    int iStart;
    int iFinish;
    int iWaiting;
    int iResponse;
    int iTaT;
    int iRemainingBurst; // Thêm thuộc tính để lưu thời gian burst còn lại
} PCB;

void inputProcess(int n, PCB P[]) 
{
    for (int i = 0; i < n; i++) 
    {
        std::cout << "Enter Arrival Time for P[" << i << "]: ";
        std::cin >> P[i].iArrival;

        std::cout << "Enter Burst Time for P[" << i << "]: ";
        std::cin >> P[i].iBurst;

        P[i].iPID = i;
        P[i].iRemainingBurst = P[i].iBurst; // Khởi tạo thời gian burst còn lại bằng burst time
    }
}

void printProcess(int n, PCB P[]) 
{
    std::cout << std::setw(5) << "PID" 
              << std::setw(10) << "Arrival" 
              << std::setw(10) << "Burst" 
              << std::setw(10) << "Start" 
              << std::setw(10) << "Finish" 
              << std::setw(10) << "Waiting" 
              << std::setw(10) << "Response" 
              << std::setw(10) << "TaT" << std::endl;

    for (int i = 0; i < n; i++) 
    {
        std::cout << std::setw(5) << P[i].iPID 
                  << std::setw(10) << P[i].iArrival 
                  << std::setw(10) << P[i].iBurst 
                  << std::setw(10) << P[i].iStart 
                  << std::setw(10) << P[i].iFinish 
                  << std::setw(10) << P[i].iWaiting 
                  << std::setw(10) << P[i].iResponse 
                  << std::setw(10) << P[i].iTaT << std::endl;
    }
}

void exportGanttChart(int n, PCB P[]) 
{
    std::cout << "Gantt Chart\n|";
    for (int i = 0; i < n; i++) 
    {
        std::cout << " P[" << P[i].iPID << "] (" << P[i].iStart << "-" << P[i].iFinish << ") |";
    }
    std::cout << "\n";
}

void pushProcess(int *n, PCB P[], PCB Q) 
{
    P[*n] = Q;
    (*n)++;
}

void removeProcess(int *n, int index, PCB P[])
{
    for (int i = index; i < *n - 1; i++) 
    {
        P[i] = P[i + 1];
    }
    (*n)--;
}

void swapProcess(PCB *P, PCB *Q) 
{
    PCB temp = *P;
    *P = *Q;
    *Q = temp;
}

int partition(PCB P[], int low, int high, int iCriteria)
{
    int pivot = (iCriteria == SORT_BY_BURST) ? P[high].iBurst : P[high].iArrival;
    int i = low - 1;

    for (int j = low; j < high; j++) 
    {
        bool condition = (iCriteria == SORT_BY_ARRIVAL && P[j].iArrival < pivot) ||
                         (iCriteria == SORT_BY_PID && P[j].iPID < pivot) ||
                         (iCriteria == SORT_BY_BURST && P[j].iBurst < pivot) ||
                         (iCriteria == SORT_BY_START && P[j].iStart < pivot);

        if (condition) 
        {
            i++;
            swapProcess(&P[i], &P[j]);
        }
    }
    swapProcess(&P[i + 1], &P[high]);
    return i + 1;
}

void quickSort(PCB P[], int low, int high, int iCriteria)
{
    if (low < high) 
    {
        int pi = partition(P, low, high, iCriteria);
        quickSort(P, low, pi - 1, iCriteria);
        quickSort(P, pi + 1, high, iCriteria);
    }
}

void calculateAWT(int n, PCB P[]) 
{
    int iTotalWaiting = 0;
    for (int i = 0; i < n; i++) 
    {
        iTotalWaiting += P[i].iWaiting;
    }
    std::cout << "Average Waiting Time: " << (double)iTotalWaiting / n << "\n";
}

void calculateATaT(int n, PCB P[])
{
    int iTotalTaT = 0;
    for (int i = 0; i < n; i++) 
    {
        iTotalTaT += P[i].iTaT;
    }
    std::cout << "Average Turnaround Time: " << (double)iTotalTaT / n << "\n";
}

void roundRobinScheduling(int n, PCB P[], int timeQuantum)
{
    int currentTime = 0;
    int iRemain = n, iTerminated = 0;
    PCB TerminatedArray[n];
    int firstExecution[n]; // Để lưu lần đầu tiên mỗi tiến trình được thực thi
    
    for (int i = 0; i < n; i++) {
        firstExecution[i] = -1;
    }

    while (iRemain > 0) 
    {
        bool isIdle = true; // Kiểm tra có tiến trình nào chạy không

        for (int i = 0; i < n; i++) 
        {
            if (P[i].iArrival <= currentTime && P[i].iRemainingBurst > 0) 
            {
                isIdle = false;

                if (firstExecution[i] == -1) {
                    firstExecution[i] = currentTime;
                }

                P[i].iStart = (P[i].iRemainingBurst == P[i].iBurst) ? currentTime : P[i].iStart;

                int timeSlice = (P[i].iRemainingBurst > timeQuantum) ? timeQuantum : P[i].iRemainingBurst;
                P[i].iRemainingBurst -= timeSlice;
                currentTime += timeSlice;

                if (P[i].iRemainingBurst == 0) 
                {
                    P[i].iFinish = currentTime;
                    P[i].iResponse = firstExecution[i] - P[i].iArrival;
                    P[i].iWaiting = P[i].iFinish - P[i].iArrival - P[i].iBurst;
                    P[i].iTaT = P[i].iFinish - P[i].iArrival;
                    TerminatedArray[iTerminated++] = P[i];
                    iRemain--;
                }
            }
        }

        if (isIdle) 
        {
            currentTime++;
        }
    }

    quickSort(TerminatedArray, 0, n - 1, SORT_BY_PID);
    exportGanttChart(n, TerminatedArray);
    calculateAWT(n, TerminatedArray);
    calculateATaT(n, TerminatedArray);
    printProcess(n, TerminatedArray);
}

int main()
{
    int iNumberOfProcess = 0;
    int timeQuantum;
    std::cout << "Please input number of processes: ";
    std::cin >> iNumberOfProcess;

    std::cout << "Please input time quantum: ";
    std::cin >> timeQuantum;

    PCB Input[iNumberOfProcess];
    inputProcess(iNumberOfProcess, Input);
    quickSort(Input, 0, iNumberOfProcess - 1, SORT_BY_ARRIVAL);

    std::cout << "\n===== Round Robin Scheduling =====\n";
    roundRobinScheduling(iNumberOfProcess, Input, timeQuantum);

    return 0;
}
