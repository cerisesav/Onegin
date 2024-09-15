#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "reading.h"

char* array_from_file(const int text_bytes)
{
    char* text_a = (char*)calloc(text_bytes, sizeof(char));
    return text_a;
}

char** pointer_array(char* text_a, const size_t count, int line_count)
{
    char** lines = (char**)calloc(line_count, sizeof(char*));
    lines[0] = text_a;

    size_t j = 1;
    for (size_t i = 0; i < count; i++)
    {
        if (text_a[i] == '\n')
        {
            text_a[i] = '\0';
            if (i + 1 < count)
            {
                lines[j++] = &text_a[i + 1];
            }
        }
    }
    return lines;
}

size_t line_count_f(const size_t count, char* text_a)
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

