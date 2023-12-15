/*
** EPITECH PROJECT, 2021
** task03
** File description:
** D07
*/

#include <stdlib.h>

int my_strlen(char *str);

char *my_strncat(char *dest, char const *src, int n)
{
    int d = my_strlen(dest);
    int i = 0;

    while (i != n){
        dest[d + i] = src[i];
        i += 1;
    }
    dest[d + i] = '\0';
    return (dest);
}
