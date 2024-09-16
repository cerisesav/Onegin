#ifndef READING_H
#define READING_H

long size_text(FILE *text);
size_t count_lines(const size_t count, char* text_a);
char* create_array(const int text_bytes);
char** make_pointers_array(char* text_a, const size_t count, int line_count);

#endif
