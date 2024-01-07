#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

// Define a struct for the queue
typedef struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
} Queue;

// Define the struct element before declaring the queue array
struct element
{
    int visited;
    int row;
    int col;
};

// Function to create a new queue
Queue *createQueue(unsigned capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to add an item to the queue
void enqueue(Queue *queue, int item)
{
    if (queue->size == queue->capacity)
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Function to remove an item from the queue
int dequeue(Queue *queue)
{
    if (queue->size == 0)
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to check if a given cell (row, col) can be included in BFS
bool isSafe(int row, int col, bool visited[][4], int map[][4])
{
    // row number is in range, column number is in range and value is 1
    // and not yet visited
    return (row >= 0) && (row < 4) && (col >= 0) && (col < 4) && (map[row][col] && !visited[row][col]);
}

int main(int argc, char const *argv[])
{
    Queue *queue = createQueue(5);

    return 0;
}
