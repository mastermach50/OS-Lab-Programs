#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> // for sleep()
#include <stdlib.h> // for rand()

#define BUFFER_SIZE 5
#define NUM_PRODUCERS 3
#define NUM_CONSUMERS 2
#define MAX_ITEM 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t mutex, empty, full;

// A function for the producer
void *producer(void *arg)
{
    int item;
    for (int i = 0; i < MAX_ITEM; i++)
    {
        // Generate an item
        item = rand() % 100;

        // Wait for empty and mutex
        sem_wait(&empty);
        sem_wait(&mutex);

        // CRITICAL SECTION
        buffer[in] = item;
        printf("Produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;

        // Signal mutex and full
        sem_post(&mutex);
        sem_post(&full);

        // Sleep for some time
        sleep(1);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg)
{
    int item;
    for (int i = 0; i < MAX_ITEM; i++)
    {
        // Wait for full and mutex
        sem_wait(&full);
        sem_wait(&mutex);

        // CRITICAL SECTION
        item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        // Signal mutex and empty
        sem_post(&mutex);
        sem_post(&empty);

        // Sleep for some time
        sleep(2);
    }
    pthread_exit(NULL);
}

int main()
{
    // Initialize the semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    // Initialize two arrays of threads
    pthread_t producer_threads[NUM_PRODUCERS], consumer_threads[NUM_CONSUMERS];

    // Create producer threads
    for (int i = 0; i < NUM_PRODUCERS; i++)
    {
        pthread_create(&producer_threads[i], NULL, producer, NULL);
    }

    // Create consumer threads
    for (int i = 0; i < NUM_CONSUMERS; i++)
    {
        pthread_create(&consumer_threads[i], NULL, consumer, NULL);
    }

    // Join producer threads
    for (int i = 0; i < NUM_PRODUCERS; i++)
    {
        pthread_join(producer_threads[i], NULL);
    }

    // Join consumer threads
    for (int i = 0; i < NUM_CONSUMERS; i++)
    {
        pthread_join(consumer_threads[i], NULL);
    }

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
}