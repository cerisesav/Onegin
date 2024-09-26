#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "io.h"
#include "sort_compare.h"


int main()
{

    struct Lines lines_data = {};
    struct Lines *ptr_line;
    ptr_line = &lines_data;

    struct Text text_data = {};
    struct Text *ptr_text;
    ptr_text = &text_data;

    ptr_text->file = fopen("text.txt", "rb");

    ptr_text->text_bytes = return_size_text(ptr_text->file);

    ptr_text->text_a = create_array(ptr_text->text_bytes);

    if (fread(ptr_text->text_a, sizeof(char), ptr_text->text_bytes, ptr_text->file) != ptr_text->text_bytes)
    {
        puts("fread != size of text");
    }

    ptr_line->line_count = count_lines(ptr_text);
    ptr_line->lines = make_pointers_array(ptr_text->text_a, ptr_line->line_count);

    choose_sort_compare(straight_compare_string, quick_sort, ptr_line->lines, 0, ptr_line->line_count-1);

    print_results(ptr_line);
    close_text(ptr_text, ptr_line);

    return 0;

}


