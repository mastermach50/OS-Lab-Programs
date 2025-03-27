#include <stdio.h>

void worstFit(int blockSize[], int bn, int processSize[], int pn)
{

    // This array is used to check which block a given process is allotted in
    // int allotted[100] = {-1};

    // Loop through each process and find a position for it
    for (int i = 0; i < pn; i++)
    {
        // Check each block to see if it can be allocated there
        int first_idx = -1;
        for (int j = 0; j < bn; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                first_idx = j;
                break;
            }
        }

        // Do this if the process was not allotted
        if (first_idx == -1)
        {
            printf("The process %d (%d) is sent to waiting\n", i + 1, processSize[i]);
            continue;
        }

        // The block size is reduced as a process is allotted to it
        blockSize[first_idx] -= processSize[i];

        // Mark that process i was allotted to the block first_idx
        // allotted[i] = first_idx;

        printf("The process %d (%d) was allotted to the block %d\n", i + 1, processSize[i], first_idx + 1);
    }
}

void main()
{
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int bn = sizeof(blockSize) / sizeof(blockSize[0]);
    int pn = sizeof(processSize) / sizeof(processSize[0]);

    worstFit(blockSize, bn, processSize, pn);
}