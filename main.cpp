#include <stdio.h>
#include <stdlib.h>

#include "io.h"
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

    output(line_count, lines);

    fclose(text);

    return 0;
}


// quickSort(lines, 0, line_count - 1);
