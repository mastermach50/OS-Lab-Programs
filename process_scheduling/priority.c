#include <stdio.h>

// Define a struct for the process
typedef struct
{
    int pid;
    int prio;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int completed;
} Process;

// Sort the processes based on arrival time (using bubble sort)
void sortProcesses(Process *procs, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (procs[j].at > procs[j + 1].at)
            {
                Process temp = procs[j];
                procs[j] = procs[j + 1];
                procs[j + 1] = temp;
            }
        }
    }
}

// A function to print the gantt chart (optional)
void printGanttChart(int gantt[100][2], int gn)
{
    // Print the pids first
    printf("\n\n|");
    for (int i = 0; i < gn; i++)
    {
        printf("  P%02d  |", gantt[i][0]);
    }
    printf("\n");

    // Print the timings in the next line
    printf("00");
    for (int i = 0; i < gn; i++)
    {
        printf("      %02d", gantt[i][1]);
    }
    printf("\n");
}

// Use the priority process scheduling algorithm
// Print the processes as they are completed
void fcfs(Process *procs, int n)
{
    // Keep track of the current time, starting from the time of arrival of the first process
    int time = procs[0].at;

    // Keep track of execution of processes using the gantt chart
    int gantt[100][2], gn = 0;

    printf("PID | PRIO | AT | BT | CT | TAT | WT\n");
    printf("------------------------------------\n");

    for (int i = 0; i < n; i++)
    {

        int max_prio = -1;
        Process *max_prio_proc;

        // Find the process with the highest priority that is
        // not completed yet and has already arrived
        for (int j = 0; j < n; j++)
        {
            if (procs[j].at <= time && !procs[j].completed && procs[j].prio > max_prio) {
                max_prio = procs[j].prio;
                max_prio_proc = &procs[j];
            }
        }

        time += max_prio_proc->bt;
        max_prio_proc->completed = 1;

        // The unfilled values for each process can be filled out in one go
        max_prio_proc->ct = time;
        max_prio_proc->tat = max_prio_proc->ct - max_prio_proc->at;
        max_prio_proc->wt = max_prio_proc->tat - max_prio_proc->bt;

        // Add the process to the gantt chart
        gantt[gn][0] = max_prio_proc->pid;
        gantt[gn][1] = max_prio_proc->ct;
        gn++;

        // Print out the processes immediately after they are executed
        printf("P%02d |  %02d  | %02d | %02d | %02d |  %02d | %02d\n", max_prio_proc->pid, max_prio_proc->prio, max_prio_proc->at, max_prio_proc->bt, max_prio_proc->ct, max_prio_proc->tat, max_prio_proc->wt);

    }
    // Call the function to print the gantt chart
    printGanttChart(gantt, gn);
}

void main()
{
    // The number of processes
    int n = 5;

    // Fill out the array of processes with the pid, prio, at and bt of each process
    Process procs[] = {
        {1, 4, 2, 6, 0, 0, 0, 0},
        {2, 2, 5, 2, 0, 0, 0, 0},
        {3, 3, 1, 8, 0, 0, 0, 0},
        {4, 5, 0, 3, 0, 0, 0, 0},
        {5, 1, 4, 4, 0, 0, 0, 0},
    };

    sortProcesses(procs, n);
    fcfs(procs, n);
}