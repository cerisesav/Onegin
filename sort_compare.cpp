#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "sort_compare.h"

static int isalnum_nospace(const char string)
{
    return isalnum(string) || string == ' ';
}

static void swap(void *a, void *b, size_t width)
{
    void *temp = malloc(width);

    memcpy(temp, b, width);
    memcpy(b, a, width);
    memcpy(a, temp, width);

    free(temp);
}

static void skip_chars_straight(size_t* i, size_t* j, const char* first_char, const char* second_char)
{
    while (first_char[*i] != '\0' && !isalnum_nospace(first_char[*i]))
        {
            (*i)++;
        }
    while (second_char[*j] != '\0' && !isalnum_nospace(second_char[*j]))
        {
            (*j)++;
        }
}

static void skip_chars_back(size_t* i, size_t* j, const char* first_char, const char* second_char)
{
    while (*i != -1 && !isalnum_nospace(first_char[*i])) {
        (*i)--;
    }
    while (*j != -1 && !isalnum_nospace(second_char[*j])) {
        (*j)--;
    }
}

int straight_compare_string(const void* first_char, const void* second_char)
{
    const char* frst_char = (const char*)first_char;
    const char* scnd_char = (const char*)second_char;

    size_t i = 0, j = 0;

    while (frst_char[i] != '\0' && scnd_char[j] != '\0')
    {
        skip_chars_straight(&i, &j, frst_char, scnd_char);

        if (tolower(frst_char[i]) != tolower(scnd_char[j]))
        {
            return ((int)tolower(frst_char[i]) - (int)tolower(scnd_char[j]));
        }

        i++;
        j++;
    }
    return 0;
}

void choose_sort_compare(compare compare, sort sort, char** array, int low, int high)
{
    sort(compare, array, low, high);
}

void sort_strings(char** mass, int line_count)
{
    line_count++;

    bool noSwap = true;

    for (size_t i = line_count - 1; i > 0; i--)
    {
        noSwap = true;
        for (size_t j = 0; j < i; j++)
        {
            if (straight_compare_string(mass[j], mass[j + 1]) > 0)
            {
                swap(&mass[j], &mass[j+1], sizeof(char*));
                noSwap = false;
            }
        }
        if (noSwap)
            break;
    }
}

void bubble_sort(int(*compare)(const void*, const void*), char** mass, int low, int line_count)
{
    bool noSwap = true;

    for (size_t i = line_count - 1; i > 0; i--)
    {
        noSwap = true;
        for (size_t j = 0; j < i; j++)
        {
            if (compare(mass[j], mass[j + 1]) > 0)
            {
                swap(&mass[j], &mass[j+1], sizeof(char*));
                noSwap = false;
            }
        }
        if (noSwap)
            break;
    }
}

int back_compare_string(const void* first_char, const void* second_char)
{
    const char* frst_char = (const char*)first_char;
    const char* scnd_char = (const char*)second_char;

    size_t i = strlen(frst_char) - 1;
    size_t j = strlen(scnd_char) - 1;

    while (i != (size_t)-1 && j != (size_t)-1)
    {
        skip_chars_back(&i, &j, frst_char, scnd_char);

        if (tolower(frst_char[i]) != tolower(scnd_char[j]))
        {
            return (int)(tolower(frst_char[i]) - tolower(scnd_char[j]));
        }

        i--;
        j--;
    }
    return (int)(i - j);
}

static int partition(int(*compare)(const void*, const void*), char** array, int low, int high)
{
  char* pivot = array[high];

  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (compare(array[j], pivot) <= 0) {

      i++;
      swap(&array[i], &array[j], 2);
    }
  }

  swap(&array[i + 1], &array[high], 2);

  return (i + 1);
}

void quick_sort(int(*compare)(const void*, const void*), char** array, int low, int high)
{
    if (low < high)
    {
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(compare, array, low, high);

        // recursive call on the left of pivot
        quick_sort(compare, array, low, pi - 1);

        // recursive call on the right of pivot
        quick_sort(compare, array, pi + 1, high);
    }
}

