/*
** EPITECH PROJECT, 2021
** task04
** File description:
** D04
*/

int my_strlen(char const *str);

void swap(char *a, char *b)
{
    char c = *a;

    *a = *b;
    *b = c;
}

char *my_evil_str(char *str)
{
    int  i = my_strlen(str) - 1;
    int  j = 0;

    while (i > j) {
        swap(&str[j], &str[i]);
        i--;
        j++;
    }
    return (str);
}
