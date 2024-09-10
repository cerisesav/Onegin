#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int compare_string(const char* first_string, const char* next_string);
void sorter(char* mass[], int line);

int main()
{
    const int line = 15;
    const int len = 100;

    char text_a[line][len] = {};
    char *ptr[line] = {};

    FILE *text = fopen("text.txt", "r");

    int i = 0;

    while (i < line && fgets(text_a[i], len, text))
    {
        ptr[i] = text_a[i];
        i++;
    }

    fclose(text);

    // int result = compare_string(text_a[13], text_a[14]);
    // printf("%d", result);

    sorter(ptr, i);

     for (int j = 0; j < i; j++)
    {
        printf("%s\n", ptr[j]);
    }

    return 0;
}


int compare_string(const char* first_string, const char* next_string)
{
    int i = 0;

    while ((first_string[i] != '\0') && (tolower(first_string[i]) == tolower(next_string[i])))
        i++;

    return ((int)first_string[i] - (int)next_string[i]);
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
