#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "sort_compare.h"

static int isalnum_nospace(const char string)
{
    return isalnum(string) || string == ' ';
}

int compare_string(const char* first_string, const char* next_string)
{
    size_t i = 0, j = 0;

    while (first_string[i] != '\0' && next_string[j] != '\0')
    {

        while (first_string[i] != '\0' && !isalnum_nospace(first_string[i]))
        {
            i++;
        }
        while (next_string[j] != '\0' && !isalnum_nospace(next_string[j]))
        {
            j++;
        }

        if (tolower(first_string[i]) != tolower(next_string[j]))
        {
            return ((int)tolower(first_string[i]) - (int)tolower(next_string[j]));
        }

        i++;
        j++;
    }
    return ((int)first_string[i] - (int)next_string[j]);
}

void sorter(char** mass, int line)
{
    bool noSwap = true;
    char* tmp = nullptr;

    for (size_t i = line - 1; i > 0; i--)
    {
        noSwap = true;
        for (size_t j = 0; j < i; j++)
        {
            if (compare_string(mass[j], mass[j + 1]) > 0)
            {
                tmp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = tmp;
                noSwap = false;
            }
        }
        if (noSwap)
            break;
    }
}

