#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int compare_string(const char* first_string, const char* next_string);

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

    return 0;
}


int compare_string(const char* first_string, const char* next_string)
{
    int i = 0;

    while ((first_string[i] != '\0') && (tolower(first_string[i]) == tolower(next_string[i])))
        i++;

    return ((int)first_string[i] - (int)next_string[i]);
}

