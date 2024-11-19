#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <climits> // Thư viện để sử dụng INT_MAX
#include <vector>  // Thư viện để sử dụng vector cho Gantt Chart

#define SORT_BY_ARRIVAL 0
#define SORT_BY_PID 1
#define SORT_BY_BURST 2
#define SORT_BY_START 3

typedef struct 
{
    int iPID;
    int iArrival;
    int iBurst;
    int iRemainingBurst; // Thời gian burst còn lại
    int iStart;
    int iFinish;
    int iWaiting;
    int iResponse;
    int iTaT;
} PCB;

typedef struct {
    int iPID;
    int iStartTime;
    int iEndTime;
} GanttEntry;

void inputProcess(int n, PCB P[]) 
{
    for (int i = 0; i < n; i++) 
    {
        std::cout << "Enter Arrival Time for P[" << i << "]: ";
        std::cin >> P[i].iArrival;

        std::cout << "Enter Burst Time for P[" << i << "]: ";
        std::cin >> P[i].iBurst;
        
        P[i].iPID = i;
        P[i].iRemainingBurst = P[i].iBurst; // Khởi tạo thời gian burst còn lại bằng thời gian burst ban đầu
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

void exportGanttChart(const std::vector<GanttEntry>& ganttChart) 
{
    std::cout << "Gantt Chart\n|";
    for (const auto& entry : ganttChart) 
    {
        std::cout << " P[" << entry.iPID << "] (" << entry.iStartTime << "-" << entry.iEndTime << ") |";
    }
    std::cout << "\n";
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
    PCB TerminatedArray[iNumberOfProcess];
    int iRemain = iNumberOfProcess, iTerminated = 0;

    inputProcess(iNumberOfProcess, Input);
    quickSort(Input, 0, iNumberOfProcess - 1, SORT_BY_ARRIVAL);

    int currentTime = 0;
    int completed = 0; // Số lượng tiến trình đã hoàn thành

    std::vector<GanttEntry> ganttChart; // Lưu trữ biểu đồ Gantt

    while (completed < iNumberOfProcess)
    {
        int minRemainingBurst = INT_MAX;
        int shortestIndex = -1;

        // Tìm tiến trình có thời gian burst còn lại ngắn nhất trong các tiến trình đã đến
        for (int i = 0; i < iNumberOfProcess; i++)
        {
            if (Input[i].iArrival <= currentTime && Input[i].iRemainingBurst > 0 && Input[i].iRemainingBurst < minRemainingBurst)
            {
                minRemainingBurst = Input[i].iRemainingBurst;
                shortestIndex = i;
            }
        }

        if (shortestIndex == -1)
        {
            currentTime++;
            continue;
        }

        // Nếu tiến trình được chọn chưa bắt đầu, thiết lập thời gian bắt đầu
        if (Input[shortestIndex].iRemainingBurst == Input[shortestIndex].iBurst)
        {
            Input[shortestIndex].iStart = currentTime;
            Input[shortestIndex].iResponse = currentTime - Input[shortestIndex].iArrival;
        }

        // Ghi lại lần chạy của tiến trình vào Gantt Chart
        if (!ganttChart.empty() && ganttChart.back().iPID == Input[shortestIndex].iPID)
        {
            ganttChart.back().iEndTime = currentTime + 1;
        }
        else
        {
            ganttChart.push_back({Input[shortestIndex].iPID, currentTime, currentTime + 1});
        }

        // Giảm thời gian burst còn lại của tiến trình
        Input[shortestIndex].iRemainingBurst--;

        // Nếu tiến trình hoàn tất
        if (Input[shortestIndex].iRemainingBurst == 0)
        {
            Input[shortestIndex].iFinish = currentTime;
            Input[shortestIndex].iTaT = Input[shortestIndex].iFinish - Input[shortestIndex].iArrival;
            Input[shortestIndex].iWaiting = Input[shortestIndex].iTaT - Input[shortestIndex].iBurst;

            TerminatedArray[iTerminated++] = Input[shortestIndex];
            completed++;
        }

        currentTime++;
    }

    std::cout << "\n===== SRTF Scheduling =====\n";
    exportGanttChart(ganttChart);
    
    quickSort(TerminatedArray, 0, iTerminated - 1, SORT_BY_PID);

    calculateAWT(iTerminated, TerminatedArray);
    calculateATaT(iTerminated, TerminatedArray);

    quickSort(TerminatedArray, 0, iTerminated - 1, SORT_BY_PID);
    printProcess(iTerminated, TerminatedArray);

    return 0;
}
