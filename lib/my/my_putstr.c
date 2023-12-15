/*
** EPITECH PROJECT, 2021
** taskO2
** File description:
** all
*/

#include "../../include/my.h"

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
    return (0);
}

int put_zero(char c)
{
    int i = c;

    if (i < 10) {
        my_putchar('0');
    }
    if (i < 100) {
        my_putchar('0');
    }
    return 0;
}

int my_putstr_nptr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar(92);
            put_zero(str[i]);
            my_put_nbr_base(str[i], 8, "01234567");
            i += 1;
        } else {
            my_putchar(str[i]);
            i += 1;
        }
    }
    return (0);
}
