#include <stdio.h>

// Structure to represent a process
struct Process {
    int pid;            // Process ID
    int arrival_time;   // Arrival time
    int burst_time;     // Burst time
};

// Function to calculate turnaround time and waiting time for each process
void findWaitingTimeTurnaroundTime(struct Process proc[], int n, int wt[], int tat[]) {
    wt[0] = 0;  // Waiting time for the first process is 0

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + proc[i - 1].burst_time;

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + proc[i].burst_time - proc[i].arrival_time;
}

// Function to calculate average turnaround time and waiting time
void findAverageTime(struct Process proc[], int n) {
    int wt[n], tat[n];
    double total_wt = 0, total_tat = 0;

    // Calculate waiting time and turnaround time
    findWaitingTimeTurnaroundTime(proc, n, wt, tat);

    // Print processes along with details
    printf("Processes  Arrival time  Burst time  Waiting time  Turnaround time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("   %d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].arrival_time, proc[i].burst_time, wt[i], tat[i]);
    }

    // Print average waiting time and average turnaround time
    printf("\nAverage waiting time = %.2f\n", total_wt / n);
    printf("Average turnaround time = %.2f\n", total_tat / n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    // Input arrival time and burst time of each process
    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &proc[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &proc[i].burst_time);
        proc[i].pid = i + 1;  // Assigning process ID
    }

    // Find average waiting time and average turnaround time
    findAverageTime(proc, n);

    return 0;
}
