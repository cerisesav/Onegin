#include <stdio.h>
#include <stdlib.h>

#include "reading.h"
#include "sort_compare.h"

int main()
{
    FILE *text = fopen("text.txt", "rb");

    long text_bytes = size_text(text);

    char *text_a = create_array(text_bytes);

    const size_t count = fread(text_a, sizeof(text_a[0]), text_bytes, text);

    size_t line_count = count_lines(count, text_a);
    char** lines = make_pointers_array(text_a, count, line_count);
    sorter(lines, line_count);

    // quickSort(lines, 0, line_count - 1);

    for (size_t i = 0; i < line_count; i++)
    {
        printf("%s\n", lines[i]);
    }

    free(text_a);
    fclose(text);

    return 0;
}

