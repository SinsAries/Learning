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

int main()
{
    int iNumberOfProcess = 0;
    std::cout << "Please input number of processes: ";
    std::cin >> iNumberOfProcess;
    
    PCB Input[iNumberOfProcess];
    PCB ReadyQueue[iNumberOfProcess];
    PCB TerminatedArray[iNumberOfProcess];
    int iRemain = iNumberOfProcess, iReady = 0, iTerminated = 0;

    inputProcess(iNumberOfProcess, Input);
    quickSort(Input, 0, iNumberOfProcess - 1, SORT_BY_ARRIVAL);

    int currentTime = 0;

    while (iTerminated < iNumberOfProcess)
    {
        // Lọc các tiến trình có thời gian đến nhỏ hơn hoặc bằng currentTime
        while (iRemain > 0 && Input[0].iArrival <= currentTime) {
            pushProcess(&iReady, ReadyQueue, Input[0]);
            removeProcess(&iRemain, 0, Input);
        }

        // Sắp xếp ReadyQueue theo Burst Time để chọn tiến trình có thời gian ngắn nhất
        if (iReady > 0)
        {
            quickSort(ReadyQueue, 0, iReady - 1, SORT_BY_BURST);

            ReadyQueue[0].iStart = currentTime;
            ReadyQueue[0].iFinish = ReadyQueue[0].iStart + ReadyQueue[0].iBurst;
            ReadyQueue[0].iResponse = ReadyQueue[0].iStart - ReadyQueue[0].iArrival;
            ReadyQueue[0].iWaiting = ReadyQueue[0].iResponse;
            ReadyQueue[0].iTaT = ReadyQueue[0].iFinish - ReadyQueue[0].iArrival;
            currentTime = ReadyQueue[0].iFinish;

            pushProcess(&iTerminated, TerminatedArray, ReadyQueue[0]);
            removeProcess(&iReady, 0, ReadyQueue);
        }
        else 
        {
            currentTime++; // Tăng thời gian nếu không có tiến trình nào sẵn sàng
        }
    }

    std::cout << "\n===== SJF Scheduling =====\n";
    exportGanttChart(iTerminated, TerminatedArray);
    
    quickSort(TerminatedArray, 0, iTerminated - 1, SORT_BY_PID);

    calculateAWT(iTerminated, TerminatedArray);
    calculateATaT(iTerminated, TerminatedArray);

    quickSort(TerminatedArray, 0, iTerminated - 1, SORT_BY_PID);
    printProcess(iTerminated, TerminatedArray);

    return 0;
}
