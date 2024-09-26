#ifndef SORT_COMPARE_H
#define SORT_COMPARE_H

typedef int (*compare)(const void*, const void*);

typedef void (*sort)(compare compare, char** array, int low, int high);

int straight_compare_string(const void* first_char, const void* second_char);

void sort_strings(char** mass, int line);

void choose_sort_compare(compare compare, sort sort, char** array, int low, int high);

void quick_sort(int(*compare)(const void*, const void*), char** array, int low, int high);

int back_compare_string(const void* first_char, const void* second_char);

void bubble_sort(int(*)(const void*, const void*), char** mass, int low, int line_count);

#endif
