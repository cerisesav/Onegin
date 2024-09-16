#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "reading.h"

char* create_array(const int text_bytes)
{
    char* text_a = (char*)calloc(text_bytes, sizeof(char));
    return text_a;
}

char** make_pointers_array(char* text_a, const size_t count, int line_count)
{
    char** lines = (char**)calloc(line_count + 1, sizeof(char*));

    char* token = strtok(text_a, "\n");
    size_t index = 0;
    while (token != NULL)
    {
        lines[index++] = token;
        token = strtok(NULL, "\n");
    }

    return lines;
}

size_t count_lines(const size_t count, char* text_a)
{
    size_t line_count = 0;

    for (size_t i = 0; i < count; i++)
    {
        if (text_a[i] == '\n')
        {
            line_count++;
        }
    }
    return line_count;
}

long size_text(FILE *text)
{
    fseek(text, 0, SEEK_END);
    long lSize = ftell(text);
    rewind(text);
    return lSize;
}

