#ifndef SORT_COMPARE_H
#define SORT_COMPARE_H

int compare_string(const char* first_string, const char* next_string);
void sorter(char** mass, int line);
void quickSort(char** array, int low, int high);
void swap(void *a, void *b, size_t width);

#endif
