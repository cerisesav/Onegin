#ifndef IO_H
#define IO_H

const long return_size_text(FILE *text);
size_t count_lines(const long text_bytes, char* text_a);
char* create_array(const int text_bytes);
char** make_pointers_array(char* text_a, size_t line_count);
void print_results(size_t line_count, char** lines);


#define READ(a, b, c) FILE *a = fopen(b, c);

struct String
{
    long text_bytes;
    char* text_a;
    size_t line_count;
    char** lines;
};

#endif
