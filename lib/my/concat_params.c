/*
** EPITECH PROJECT, 2021
** task02
** File description:
** D08
*/

#include <stdlib.h>

int my_strlen(char const *str);

int my_putstr(char *str);

char *my_strcat(char *dest, char const *src);

char *choice(int j, int argc)
{
    if (j != argc - 1) {
        return ("\n");
    } else {
        return ("\0");
    }
}

char *concat_params(int argc, char **argv)
{
    char *str;
    int lentt = 0;

    for (int i = 0; i != argc; i += 1) {
        lentt += my_strlen(argv[i]);
    }
    str = malloc(sizeof(char) * lentt + argc);
    for (int j = 0; j != argc; j += 1) {
        str = my_strcat(str, argv[j]);
        str = my_strcat(str, choice(j, argc));
    }
    return (str);
    free(str);
}
