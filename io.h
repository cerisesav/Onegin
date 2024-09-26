#ifndef IO_H
#define IO_H

const long return_size_text(FILE *text);
size_t count_lines(struct Text* text);
char* create_array(const int text_bytes);
char** make_pointers_array(char* text_a, size_t line_count);
void print_results(struct Lines* line);
void close_text(struct Text* text, struct Lines* line);

struct Lines
{
    size_t line_count;
    char** lines;
};

struct Text
{
    FILE* file;
    char* text_a;
    long text_bytes;
};

#endif
