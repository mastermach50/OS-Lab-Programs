#include <stdio.h>

// Define the maximum number of processes and resources
#define P 5 // Number of processes
#define R 3 // Number of resources

// A simple function to display a table
void display(int arr[P][R])
{
    printf("PID R0 R1 R2\n");
    printf("------------\n");
    for (int i = 0; i < P; i++)
    {
        printf("P%02d ", i);
        for (int j = 0; j < R; j++)
        {
            printf("%02d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void BankersAlgorithm(int available[R], int required[P][R], int allotted[P][R])
{

    // Initialize an array to keep track of the finished processes
    int finished[P] = {0};

    // Loop through the list of processes as many times there are processes
    for (int count = 0; count < P; count++){

        for (int i = 0; i < P; i++)
        {

            // If the process is already completed then just skip it
            if (finished[i])
            {
                continue;
            }

            // For each process check if it can be allotted the required amount of resources
            int allottable = 0;

            // printf("needed for P%02d = ", i);
            for (int j = 0; j < R; j++)
            {
                int needed = required[i][j] - allotted[i][j];
                // printf("%02d ", needed);
                // If there are enough resources available to give to the process
                if (needed <= available[j])
                {
                    allottable += 1;
                }
            }
            // printf("\n\n");

            // If the required amount of resources can be allotted then mark it as finished
            // and take back the resources that were allotted to it
            if (allottable == R)
            {
                finished[i] = 1;
                printf("\nP%02d finished\n", i);
                printf("Available resources are:\n");
                for (int j = 0; j < R; j++)
                {
                    available[j] += allotted[i][j];
                    printf("%02d ", available[j]);
                }
                printf("\n");

            }
        }
    }

    // If any of the process are still not finished then there is a deadlock
    for (int i = 0; i < P; i++)
    {
        if (finished[i]!=1) {
            printf("There was a deadlock, P%02d cannot finish\n", i);
        }
    }

}

int main()
{
    int available[R] = {3, 3, 2};

    // Amount of resources required for each process to complete execution
    int required[P][R] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}};

    // Resources currently allocated to each process
    int allotted[P][R] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}};

    printf("Resources Required To Complete Execution\n");
    display(required);
    printf("Resources Currently Allotment\n");
    display(allotted);

    BankersAlgorithm(available, required, allotted);

    return 0;
}