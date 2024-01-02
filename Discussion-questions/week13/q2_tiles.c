#include "/home/shankar/Shiva/cs1010/include/common.h"
#include "/home/shankar/Shiva/cs1010/include/cs1010.h"

struct tiles_t
{
    int length;
    int width;
    float cost;
};

float difference(struct tiles_t *pointer, int size)
{
    // output the difference in cost between the cheapest tile and the most expensive tile
    float cheapest_tile = 0;
    float expensive_tile = 0;
    for (int i = 0; i < size; i += 1)
    {
        int area = pointer[i].length * pointer[i].width;
        float money = pointer[i].cost * area;
        if (i == 0)
        {
            cheapest_tile = money;
            expensive_tile = money;
        }
        else
        {
            if (money < cheapest_tile)
            {
                cheapest_tile = money;
            }
            if (money > expensive_tile)
            {
                expensive_tile = money;
            }
        }
    }
    return expensive_tile - cheapest_tile;
}

int main(int argc, char const *argv[])
{
    char line[50];
    int size;
    int length, width;
    float cost;

    // Read the first line to get the number of lines
    fgets(line, sizeof(line), stdin);

    sscanf(line, "%d", &size);
    printf("Number of lines: %d\n", size);
    struct tiles_t tiles[size];

    // Read the subsequent lines
    for (int i = 0; i < size; i++)
    {
        fgets(line, sizeof(line), stdin);
        int num1, num2;
        float num3;

        // Use sscanf to parse each line
        if (sscanf(line, "%d %d %f", &num1, &num2, &num3) == 3)
        {
            printf("Read values: %d, %d, %.2f\n", num1, num2, num3);
            tiles[i].length = num1;
            tiles[i].width = num2;
            tiles[i].cost = num3;
        }
        else
        {
            printf("Invalid input format in line %d.\n", i + 2); // i + 2 to account for the first line
            return 1;
        }
    }

    // Print the values
    for (int i = 0; i < size; i++)
    {
        printf("Length: %d, Width: %d, Cost: %.2f\n", tiles[i].length, tiles[i].width, tiles[i].cost);
    }

    float result = difference(tiles, size);
    printf("Difference: %.2f\n", result);

    return 0;
}
