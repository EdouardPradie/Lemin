/*
** EPITECH PROJECT, 2021
** task02
** File description:
** D07
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int d = my_strlen(dest);
    int i = 0;
    char *str = malloc(sizeof(char) * (d + my_strlen(src) + 1));

    for (int j = 0; dest[j] != '\0'; j += 1) {
        str[j] = dest[j];
    }
    while (src[i] != '\0'){
        str[d + i] = src[i];
        i += 1;
    }
    str[d + i] = '\0';
    return (str);
}
