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

void getPeaksValleys(int map[][4], int peaksandvalleys[][4],
                     int rows, int columns, int *nopeaks, int *novalleys)
{
    // Print the read matrix
    printf("Matrix:\n");
    for (int i = 0; i < rows; i += 1)
    {
        for (int j = 0; j < columns; j += 1)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    for (int i = 1; i < rows - 1; i += 1)
    {
        for (int j = 1; j < columns - 1; j += 1)
        {
            // printf("map[%d][%d] = %d\n", i, j, map[i][j]);

            // valleys
            if ((map[i][j] < map[i - 1][j - 1]) && (map[i][j] < map[i - 1][j]) &&
                (map[i][j] < map[i - 1][j + 1]) && (map[i][j] < map[i][j - 1]) &&
                (map[i][j] < map[i][j + 1]) && (map[i][j] < map[i + 1][j - 1]) &&
                (map[i][j] < map[i + 1][j]) && (map[i][j] < map[i + 1][j + 1]))
            {
                peaksandvalleys[i][j] = 2;
                *novalleys += 1;
            }
            // peaks
            if ((map[i][j] > map[i - 1][j - 1]) && (map[i][j] > map[i - 1][j]) &&
                (map[i][j] > map[i - 1][j + 1]) && (map[i][j] > map[i][j - 1]) &&
                (map[i][j] > map[i][j + 1]) && (map[i][j] > map[i + 1][j - 1]) &&
                (map[i][j] > map[i + 1][j]) && (map[i][j] > map[i + 1][j + 1]))
            {
                peaksandvalleys[i][j] = 1;
                *nopeaks += 1;
            }
        }
    }
}

void getHikeTrail(int map[][4], int **hike, int row, int col)
{
    // Declare a 2D array to keep track of visited cells.
    // Initially all cells are unvisited
    bool visited[row][col];
    memset(visited, false, sizeof(visited));

    // Create a queue for BFS
    Queue *queue = createQueue(row * col);

    // Mark the source cell as visited and enqueue it
    visited[0][0] = true;
    struct element e = {1, 0, 0};
    enqueue(queue, e.row);
    enqueue(queue, e.col);

    // 'row' and 'col' arrays are used to get row and column
    // numbers of 4 neighbours of a given cell
    int row1[] = {-1, 0, 0, 1};
    int col1[] = {0, -1, 1, 0};

    // Do a BFS starting from source cell
    while (queue->size != 0)
    {
        // Dequeue a cell from queue
        int row2 = dequeue(queue);
        printf("row2 = %d\n", row2);
        int col2 = dequeue(queue);
        printf("col2 = %d\n", col2);

        // Get all adjacent vertices of the dequeued cell
        // If a adjacent has not been visited, then mark it
        // visited and enqueue it
        for (int i = 0; i < 4; i++)
        {
            int row3 = row2 + row1[i];
            int col3 = col2 + col1[i];
            if (isSafe(row3, col3, visited, map))
            {
                // mark cell as visited and enqueue it
                visited[row3][col3] = true;
                struct element e = {1, row3, col3};
                enqueue(queue, e.row);
                enqueue(queue, e.col);
                hike[row3][col3] = 1;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int nopeaks = 0, novalleys = 0;
    int rows, columns;
    char buffer[1000];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        sscanf(buffer, "%d %d", &rows, &columns);
    }

    printf("Number of rows: %d\n", rows);
    printf("Number of columns: %d\n", columns);

    // Declare a 2D array based on the number of rows and columns
    int matrix[rows][columns];
    int peaksandvalleys[rows][columns];

    // initalize peaksandvalleys to 0
    for (int i = 0; i < rows; i += 1)
    {
        for (int j = 0; j < columns; j += 1)
        {
            peaksandvalleys[i][j] = 0;
        }
    }

    // Read the subsequent lines
    char *ptr;
    for (int i = 0; i < rows; i += 1)
    {
        fgets(buffer, sizeof(buffer), stdin);
        int num;
        int j = 0;
        // Use strtok to parse each line
        ptr = strtok(buffer, " ");
        while (ptr != NULL)
        {
            sscanf(ptr, "%d", &num);
            matrix[i][j] = num;
            j += 1;
            // Move the pointer to the next number
            ptr = strtok(NULL, " ");
        }
    }

    // Print the read matrix
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    getPeaksValleys(matrix, peaksandvalleys, rows, columns, &nopeaks, &novalleys);

    printf("Number of peaks: %d\n", nopeaks);
    printf("Number of valleys: %d\n", novalleys);

    // Print the peaks and valleys
    printf("Peaks and valleys:\n");
    for (int i = 0; i < rows; i += 1)
    {
        for (int j = 0; j < columns; j += 1)
        {
            printf("%d ", peaksandvalleys[i][j]);
        }
        printf("\n");
    }

    int **hike;
    hike = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++)
        hike[i] = calloc(columns, sizeof(int));

    getHikeTrail(matrix, hike, rows, columns);

    printf("Hike trail:\n");
    for (int i = 0; i < rows; i += 1)
    {
        for (int j = 0; j < columns; j += 1)
        {
            printf("%d ", hike[i][j]);
        }
        printf("\n");
    }

    // free the allocated memory
    for (int i = 0; i < rows; i++)
        free(hike[i]);
    free(hike);

    return EXIT_SUCCESS;
}
