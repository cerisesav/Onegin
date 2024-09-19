#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "io.h"
#include "sort_compare.h"


int main()
{
    READ(text, "text.txt", "rb");

    struct String string_data;

    string_data.text_bytes = return_size_text(text);

    string_data.text_a = create_array(string_data.text_bytes);

    if (fread(string_data.text_a, sizeof(char), string_data.text_bytes, text) != string_data.text_bytes)
    {
        puts("fread != size of text");
    }

    string_data.line_count = count_lines(string_data.text_bytes, string_data.text_a);
    string_data.lines = make_pointers_array(string_data.text_a, string_data.line_count);

    sort_strings(string_data.lines, string_data.line_count);
    print_results(string_data.line_count, string_data.lines);


    free(string_data.text_a);
    free(string_data.lines);
    fclose(text);

    return 0;

}


// quickSort(lines, 0, line_count - 1);
