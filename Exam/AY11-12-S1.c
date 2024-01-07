#include "/home/shankar/Shiva/cs1010/include/common.h"
#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[10];
    int age;
} person;

void func1(person *, char[], int);
void func2(person[]);
void func3(person);

unsigned int compute_score(char *word)
{
    int len = strlen(word);
    int score = 0;
    char *one = "AEILNORSTU";
    char *two = "DG";
    char *three = "BCMP";
    char *four = "FHVWY";
    char *five = "K";
    char *eight = "JX";
    char *ten = "QZ";

    for (int i = 0; i < len; i += 1)
    {
        printf("%c\n", word[i]);
        if (strchr(one, word[i]) != NULL)
            score += 1;
        else if (strchr(two, word[i]) != NULL)
            score += 2;
        else if (strchr(three, word[i]) != NULL)
            score += 3;
        else if (strchr(four, word[i]) != NULL)
            score += 4;
        else if (strchr(five, word[i]) != NULL)
            score += 5;
        else if (strchr(eight, word[i]) != NULL)
            score += 8;
        else if (strchr(ten, word[i]) != NULL)
            score += 10;
    }

    return score;
}

int get_min_index(int arr[], int size)
{
    // Recursive solution
    if (size == 1)
        return 0;
    int min_index = get_min_index(arr, size - 1);
    if (arr[min_index] < arr[size - 1])
        return min_index;
    else
        return size - 1;
}

void iSolitude(void)
{
    int return_array[6] = {0};
    int friendArr[6][6] = {{1, 0, 1, 0, 0, 0}, {0, 1, 0, 0, 0, 1}, {1, 0, 1, 1, 0, 0}, {0, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1}, {0, 1, 0, 0, 1, 1}};

    struct node
    {
        int user;
        int friend;
        int value;
    };

    struct node arr[36];
    int count = 0;

    for (int i = 0; i < 6; i += 1)
    {
        for (int j = 0; j < 6; j += 1)
        {
            if (i >= j)
            {
                arr[count].user = i;
                arr[count].friend = j;
                arr[count].value = friendArr[i][j];
                count += 1;
            }
        }
    }

    printf("%d\n", count);

    int humans = 0;
    for (int humans = 0; humans < 6; humans += 1)
    {
        for (int i = 0; i < count; i += 1)
        {
            printf("%d %d %d\n", arr[i].user, arr[i].friend, arr[i].value);
            if (arr[i].user == humans || arr[i].friend == humans)
            {
                if (arr[i].value == 1)
                    return_array[humans] += 1;
            }
        }
    }

    for (int i = 0; i < 6; i += 1)
    {
        printf("%d ", return_array[i]);
    }

    // Find the minimum value in the array
    int min = return_array[0];
    int min_index = 0;
    for (int i = 0; i < 6; i += 1)
    {
        if (return_array[i] < min)
        {
            min = return_array[i];
            min_index = i;
        }
    }

    printf("\n%d\n", min_index);

    for (int i = 0; i < 6; i += 1)
    {
        if (return_array[i] == min)
            printf("%d ", i);
    }

    // Compute friend of friend
}

int main(void)
{
    // person data[] = {{"Zhou", 25}, {"Tamil", 22}, {"Potter", 33}};
    // func1(&data[0], "Ismail", 15);
    // printf("%s %d\n", data[0].name, data[0].age);
    // func2(data);
    // printf("%s %d\n", data[1].name, data[1].age);
    // func3(data[2]);
    // printf("%s %d\n", data[2].name, data[2].age);

    // printf("%d \n", get_min_index((int[]){3, 2, 1, 4, 5}, 5));

    iSolitude();

    return 0;
}
void func1(person *ptr, char name[10], int age)
{
    strcpy(ptr->name, name);
    ptr->age = age;
}
void func2(person per[])
{
    int i;
    for (i = 0; i < 3; i++)
        per[i].age++;
}
void func3(person per)
{
    strcpy(per.name, "Ace");
    per.age--;
}
