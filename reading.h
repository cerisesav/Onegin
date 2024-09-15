#ifndef READING_H
#define READING_H

long size_text(FILE *text);
size_t line_count_f(const size_t count, char* text_a);
char* array_from_file(const int text_bytes);
char** pointer_array(char* text_a, const size_t count, int line_count);

#endif
