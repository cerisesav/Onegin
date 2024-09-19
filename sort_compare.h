#ifndef SORT_COMPARE_H
#define SORT_COMPARE_H

int compare_string(const char* first_string, const char* next_string);

void sort_strings(char** mass, int line);
void quickSort(char** array, int low, int high);
void swap(void *a, void *b, size_t width);
int back_compare_string(const char* first_string, const char* next_string);
void skip_chars_straight(size_t i, size_t j, const char* first_char, const char* second_char);
void skip_chars_back(size_t i, size_t j, const char* first_char, const char* second_char);


#endif
