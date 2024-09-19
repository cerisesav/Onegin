#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "io.h"

char* create_array(const int text_bytes)
{
    char* text_a = (char*)calloc(text_bytes, sizeof(char));
    return text_a;
}

char** make_pointers_array(char* text_a, size_t line_count)
{
    char** lines = (char**)calloc(line_count, sizeof(char*));
     assert(lines != nullptr);

    char* token = strtok(text_a, "\n");
    size_t index = 0;
    while (token != nullptr)
    {
        lines[index++] = token;
        token = strtok(nullptr, "\n");
    }

    return lines;
}

size_t count_lines(const long text_bytes, char* text_a)
{
    size_t line_count = 0;

    for (size_t i = 0; i < text_bytes; i++)
    {
        if (text_a[i] == '\n')
        {
            line_count++;
        }
    }

    return line_count;
}

const long return_size_text(FILE *text)
{
    fseek(text, 0, SEEK_END);
    long text_bytes = ftell(text);
    rewind(text);
    return text_bytes;
}

void print_results(size_t line_count, char** lines)
{
    for (size_t i = 0; i < line_count; i++)
        {
            printf("%s\n", lines[i]);
        }
}
