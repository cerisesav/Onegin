#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "reading.h"
#include "sort_compare.h"

int main()
{
    FILE *text = fopen("text.txt", "rb");

    const int text_bytes = size_text(text);

    char *text_a = array_from_file(text_bytes);

    const size_t count = fread(text_a, sizeof(text_a[0]), text_bytes, text);

    size_t line_count = line_count_f(count, text_a);
    char** lines = pointer_array(text_a, count, line_count);
    sorter(lines, line_count);

    for (size_t i = 0; i < line_count; i++)
    {
        printf("%s\n", lines[i]);
    }

    free(text_a);
    fclose(text);

    return 0;
}

