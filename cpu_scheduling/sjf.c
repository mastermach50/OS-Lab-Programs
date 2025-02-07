#include <stdio.h>

typedef struct
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
} Process;

void main()
{
    // Define the processes
    Process procs[] = {
        { 1, 3, 8 }, // Arrival time = 0, Burst time = 8
        { 2, 5, 1 }, // Arrival time = 1, Burst time = 1
        { 3, 1, 3 }, // Arrival time = 2, Burst time = 3
        { 4, 0, 2 }, // Arrival time = 3, Burst time = 2
        { 5, 4, 6 }, // Arrival time = 4, Burst time = 6
    };

    int n = sizeof(procs) / sizeof(Process);
    int current_time = 0;

    // Sort the processes by their arrival time (bubble sort)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (procs[j].bt > procs[j + 1].bt) {
                Process temp = procs[j];
                procs[j] = procs[j + 1];
                procs[j + 1] = temp;
            }
        }
    }

    // Calculate the other values for each process and print them
    printf("PID | Time\n");
    printf("----+-----\n");
    current_time = procs[0].at;
    for (int i = 0; i < n; i++) {
        procs[i].ct = current_time + procs[i].bt;
        current_time = procs[i].ct;
        procs[i].tat = procs[i].ct - procs[i].at;
        procs[i].wt = procs[i].tat - procs[i].bt;
        printf("P%d  | %02d\n", procs[i].pid, procs[i].ct);
    }
    printf("\n");

    // Print the GANTT chart
    printf("PID | AT | BT | CT | TAT | WT\n");
    printf("----+----+----+----+-----+---\n");
    for (int i = 0; i < n; i++) {
        printf("P%d  | %02d | %02d | %02d | %02d  | %02d\n", procs[i].pid,
            procs[i].at, procs[i].bt, procs[i].ct, procs[i].tat, procs[i].wt);
    }
}