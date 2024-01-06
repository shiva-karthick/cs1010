#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isValidChecksum(char regNo[])
{
    // dont modify the input
    char *regNoCopy = regNo;
    // printf("%c\n", regNoCopy[1]);

    // before we go into this, check if the second char does not contain a vowel
    if (regNoCopy[1] == 'A' || regNoCopy[1] == 'E' || regNoCopy[1] == 'I' || regNoCopy[1] == 'O' || regNoCopy[1] == 'U')
    {
        printf("Invalid car type\n");
        return 0;
    }

    switch (regNoCopy[1])
    {
    case 'H':
        printf("Car is a taxi\n");
        break;
    case 'Z':
        printf("Car is a rental car\n");
        break;
    case 'G':
        printf("Car is a goods vehicle\n");
        break;
    default:
        printf("Car is a private car\n");
        break;
    }

    return 1;
}

char genChecksum(char regNo[])
{
    int sum = 0;
    int len = strlen(regNo);
    int length_of_digits = strlen(regNo) - 4;
    int fixed_start = 2;
    int remainder = 0;

    printf("length of middle digits = %d\n", length_of_digits);
    if (isValidChecksum(regNo))
    {
        // Convert the first 2 letters to numbers
        sum += (regNo[1] - 'A' + 1) * 9;
        printf("%d \n", sum);
        sum += (regNo[2] - 'A' + 1) * 4;

        for (int i = 0; i < length_of_digits; i += 1)
        {
            sum += (regNo[len - 2 - i] - '0') * (fixed_start + i);
        }

        printf("sum = %d\n", sum);
        remainder = sum % 19;
        printf("remainder = %d\n", remainder);

        switch (remainder)
        {
        case 1:
            if (regNo[len - 1] == 'Z')
            {
                return 'Z';
            }
            break;
        case 0:
            if (regNo[len - 1] == 'A')
            {
                return 'A';
            }
            break;
        case 2:
            if (regNo[len - 1] == 'Y')
            {
                return 'Y';
            }
            break;
        case 3:
            if (regNo[len - 1] == 'X')
            {
                return 'X';
            }
            break;
        case 4:
            if (regNo[len - 1] == 'U')
            {
                return 'U';
            }
            break;
        case 5:
            if (regNo[len - 1] == 'T')
            {
                return 'T';
            }
            break;
        case 6:
            if (regNo[len - 1] == 'S')
            {
                return 'S';
            }
            break;
        case 7:
            if (regNo[len - 1] == 'R')
            {
                return 'R';
            }
            break;
        case 8:
            if (regNo[len - 1] == 'P')
            {
                return 'P';
            }
            break;
        case 9:
            if (regNo[len - 1] == 'M')
            {
                return 'M';
            }
            break;
        case 10:
            if (regNo[len - 1] == 'L')
            {
                return 'L';
            }
            break;
        case 11:
            if (regNo[len - 1] == 'K')
            {
                return 'K';
            }
            break;
        case 12:
            if (regNo[len - 1] == 'J')
            {
                return 'J';
            }
            break;
        case 13:
            if (regNo[len - 1] == 'H')
            {
                return 'H';
            }
            break;
        case 14:
            if (regNo[len - 1] == 'G')
            {
                return 'G';
            }
            break;
        case 15:
            if (regNo[len - 1] == 'E')
            {
                return 'E';
            }
            break;
        case 16:
            if (regNo[len - 1] == 'D')
            {
                return 'D';
            }
            break;
        case 17:
            if (regNo[len - 1] == 'C')
            {
                return 'C';
            }
            break;
        case 18:
            if (regNo[len - 1] == 'B')
            {
                return 'B';
            }
            break;
        default:
            printf("Invalid registration number\n");
            return '\0';
            break;
        }
    }
    printf("Invalid registration number\n");
    return '\0';
}

int main(int argc, char const *argv[])
{
    char *sample1 = "SHA123X";
    char *sample2 = "SDU388Z";
    char *sample3 = "SEA12B";
    char *sample4 = "SCG6100H";
    printf("%d\n", isValidChecksum(sample4));
    printf("%c \n", genChecksum(sample4));
    return 0;
}
