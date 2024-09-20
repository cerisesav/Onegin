#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "sort_compare.h"

static int isalnum_nospace(const char string)
{
    return isalnum(string) || string == ' ';
}

int compare_string(const char* first_char, const char* second_char)
{
    size_t i = 0, j = 0;

    while (first_char[i] != '\0' && second_char[j] != '\0')
    {
        skip_chars_straight(i, j, first_char, second_char);

        if (tolower(first_char[i]) != tolower(second_char[j]))
        {
            return ((int)tolower(first_char[i]) - (int)tolower(second_char[j]));
        }

        i++;
        j++;
    }
    return 0;
}

void skip_chars_straight(size_t i, size_t j, const char* first_char, const char* second_char)
{
    while (first_char[i] != '\0' && !isalnum_nospace(first_char[i]))
        {
            i++;
        }
    while (second_char[j] != '\0' && !isalnum_nospace(second_char[j]))
        {
            j++;
        }
}

void sort_strings(char** mass, int line_count) // передавать функцию сортер по указателю
{
    bool noSwap = true;

    for (size_t i = line_count - 1; i > 0; i--)
    {
        noSwap = true;
        for (size_t j = 0; j < i; j++)
        {
            if (compare_string(mass[j], mass[j + 1]) > 0)
            {
                swap(&mass[j], &mass[j+1], sizeof(char*));
                noSwap = false;
            }
        }
        if (noSwap)
            break;
    }
}

int back_compare_string(const char* first_char, const char* second_char)
{
    size_t i = sizeof(*first_char) / sizeof(first_char[0]), j = sizeof(*second_char) / sizeof(second_char[0]);

    while (first_char[i] != '\0' && second_char[j] != '\0')
    {

        skip_chars_back(i, j, first_char, second_char);

        if (tolower(first_char[i]) != tolower(second_char[j]))
        {
            return ((int)tolower(first_char[i]) - (int)tolower(second_char[j]));
        }

        i--;
        j--;
    }
    return 0;
}

void skip_chars_back(size_t i, size_t j, const char* first_char, const char* second_char)
{
    while (first_char[i] != '\0' && !isalnum_nospace(first_char[i]))
        {
            i--;
        }
    while (second_char[j] != '\0' && !isalnum_nospace(second_char[j]))
        {
            j--;
        }
}

void swap(void *a, void *b, size_t width)
{
    void *temp = malloc(width);

    memcpy(temp, b, width);
    memcpy(b, a, width);
    memcpy(a, temp, width);

    free(temp);
}

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

void quick_sort(char** array, int low, int high)
{
    if (low < high)
    {
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quick_sort(array, low, pi - 1);

        // recursive call on the right of pivot
        quick_sort(array, pi + 1, high);
    }
}

