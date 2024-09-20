#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "io.h"
#include "sort_compare.h"


int main()
{
    READ(text, "text.txt", "rb");

    struct String string_data = {};
    struct String *ptr_string;
    ptr_string = &string_data;

    ptr_string->text_bytes = return_size_text(text);

    ptr_string->text_a = create_array(ptr_string->text_bytes);

    if (fread(ptr_string->text_a, sizeof(char), ptr_string->text_bytes, text) != ptr_string->text_bytes)
    {
        puts("fread != size of text");
    }

    ptr_string->line_count = count_lines(ptr_string->text_bytes, ptr_string->text_a);
    ptr_string->lines = make_pointers_array(ptr_string->text_a, ptr_string->line_count);

    quick_sort(ptr_string->lines, 0, ptr_string->line_count-1);
    print_results(ptr_string->line_count, ptr_string->lines);


    free(ptr_string->text_a);
    free(ptr_string->lines);
    fclose(text);

    return 0;

}


// quickSort(lines, 0, line_count - 1);
