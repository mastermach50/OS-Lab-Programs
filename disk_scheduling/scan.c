#include <stdio.h>

#define TOTAL_TRACKS 200

int calculateSeekTime(int *requests, int n)
{
    int total_seek_time = 0;
    int head_pos = 53;
    int direction = 1;

    int completed = 0;

    while (head_pos >= 0 && head_pos <= TOTAL_TRACKS - 1)
    {
        for (int j = 0; j < n; j++)
        {
            if (requests[j] == head_pos)
            {
                requests[j] = -1;
                completed++;
            }
        }

        if (completed == n)
        {
            break;
        }

        if (head_pos == TOTAL_TRACKS - 1)
        {
            direction = -1;
        }
        total_seek_time++;
        head_pos += direction;
    }

    return total_seek_time;
}

void main()
{
    int requests[] = {98, 183, 41, 122, 14, 124, 65, 67};
    int n = sizeof(requests) / sizeof(requests[0]);

    int total_seek_time = calculateSeekTime(requests, n);
    printf("Total Seek Time: %d", total_seek_time);
}