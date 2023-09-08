#include <stdio.h>

// Structure to represent a process
struct Process {
    int id;         // Process ID
    int priority;   // Priority of the process
    int burstTime;  // Burst time of the process
};

// Function to perform Priority Scheduling
void priorityScheduling(struct Process processes[], int n) {
    int waitingTime[n], turnaroundTime[n];
    
    // Initialize waiting time and turnaround time arrays
    waitingTime[0] = 0;
    turnaroundTime[0] = processes[0].burstTime;
    
    // Calculate waiting time and turnaround time for each process
    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + processes[i - 1].burstTime;
        turnaroundTime[i] = waitingTime[i] + processes[i].burstTime;
    }
    
    // Calculate average waiting time and average turnaround time
    double avgWaitingTime = 0, avgTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        avgWaitingTime += waitingTime[i];
        avgTurnaroundTime += turnaroundTime[i];
    }
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;
    
    // Display the scheduling results
    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].priority,
               processes[i].burstTime, waitingTime[i], turnaroundTime[i]);
    }
    
    printf("\nAverage Waiting Time: %.2lf", avgWaitingTime);
    printf("\nAverage Turnaround Time: %.2lf\n", avgTurnaroundTime);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process processes[n];
    
    // Input process details (id, priority, burst time)
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter priority for Process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }
    
    // Perform Priority Scheduling
    priorityScheduling(processes, n);
    
    return 0;
}
