#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

    for (size_t i = line - 1; i > 0; i--)
    {
        noSwap = true;
        for (size_t j = 0; j < i; j++)
        {
            if (back_compare_string(mass[j], mass[j + 1]) > 0)
            {
                swap(&mass[j], &mass[j+1], sizeof(char*));
                noSwap = false;
            }
        }
        if (noSwap)
            break;
    }
}

int back_compare_string(const char* first_string, const char* next_string)
{
    size_t i = sizeof(*first_string) / sizeof(first_string[0]), j = sizeof(*next_string) / sizeof(next_string[0]);

    while (first_string[i] != '\0' && next_string[j] != '\0')
    {

        while (first_string[i] != '\0' && !isalnum_nospace(first_string[i]))
        {
            i--;
        }
        while (next_string[j] != '\0' && !isalnum_nospace(next_string[j]))
        {
            j--;
        }

        if (tolower(first_string[i]) != tolower(next_string[j]))
        {
            return ((int)tolower(first_string[i]) - (int)tolower(next_string[j]));
        }

        i--;
        j--;
    }
    return ((int)first_string[i] - (int)next_string[j]);
}

void swap(void *a, void *b, size_t width)
{
    void *temp = malloc(width);
    memcpy(temp, b, width);
    memcpy(b, a, width);
    memcpy(a, temp, width);
    free(temp);
}









// FORGET ABOUT THIS SHIT

// function to find the partition position
static int partition(char** array, int low, int high) {

  // select the rightmost element as pivot
  char* pivot = array[high];

  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (compare_string(array[j], pivot) <= 0) {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      swap(&array[i], &array[j], 2);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high], 2);

  // return the partition point
  return (i + 1);
}

void quickSort(char** array, int low, int high)
{
    if (low < high)
    {
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

