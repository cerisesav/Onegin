#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int compare_string(const char* first_string, const char* next_string);
void sorter(char* mass[], int line);
int size_text(FILE *text);

int main()
{
    FILE *text = fopen("text.txt", "rb");
    const int text_bytes = size_text(text);

    int *ptr = NULL;

    char* text_a = (char*)calloc(text_bytes + 1, sizeof(char));
    const size_t count = fread(text_a, sizeof(text_a[0]), text_bytes, text);

    int line_count = 0;
    for (int i = 0; i < count; i++)
    {
        if (text_a[i] == '\n')
        {
            line_count++;
        }
    }

    char** lines = (char**)calloc(line_count + 1, sizeof(char*));

    lines[0] = text_a;

    int j = 1;
    for (int i = 0; i < count; i++)
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

    sorter(lines, line_count);

    for (int i = 0; i < line_count; i++) {
        printf("%s\n", lines[i]);
    }

    fclose(text);
    free(text_a);
    free(ptr);

    return 0;
}

int size_text(FILE *text)
{
    fseek(text, 0, SEEK_END);
    int lSize = ftell(text);
    rewind(text);
    return lSize;
}

int compare_string(const char* first_string, const char* next_string)
{
    int i = 0, j = 0;

    while (first_string[i] != '\0' && next_string[j] != '\0')
    {

        while (first_string[i] != '\0' && !isalnum(first_string[i]))
        {
            i++;
        }
        while (next_string[j] != '\0' && !isalnum(next_string[j]))
        {
            j++;
        }

        if (tolower(first_string[i]) != tolower(next_string[j]))
        {
            return ((int)tolower(first_string[i]) - (int)tolower(next_string[j]));
        }

        i++;
        j++;
    }

    return ((int)first_string[i] - (int)next_string[j]);
}

void sorter(char* mass[], int line)
{
    bool noSwap;
    char* tmp;

    for (int i = line - 1; i > 0; i--)
    {
        noSwap = true;
        for (int j = 0; j < i; j++)
        {
            if (compare_string(mass[j], mass[j + 1]) > 0)
            {
                tmp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = tmp;
                noSwap = false;
            }
        }
        if (noSwap)
            break;
    }
}
