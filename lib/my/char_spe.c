/*
** EPITECH PROJECT, 2021
** char_spe
** File description:
** special_character
*/

#include "../../include/my.h"

int error_input(int begin, int i, char const *str)
{
    if (str[i] != 'c' && str[i] != 's' && str[i] != 'b' && str[i] != 'o'
    && str[i] != 'x' && str[i] != 'X' && str[i] != 'i' && str[i] != 'u'
    && str[i] != 'd' && str[i] != '-' && str[i] != 'S' && str[i] != ' '
    && str[i] != '+') {
        my_putchar('%');
        while (begin != i + 1) {
            my_putchar(str[begin]);
            begin += 1;
        }
    }
    return 0;
}

int put_cross(int idx, char *str, int i)
{
    if (str[i -1] == '+' && idx > 0)
        my_putchar('+');
    return 0;
}

int char_spe(char const *str, int i)
{
    int begin = i;

    for (int idx = 0; str[i] != 'c' || str[i] != 'S'
    || str[i] != 's' || str[i] != 'b' || str[i] != 'o' || str[i] != 'x'
    || str[i] != 'X' || str[i] != 'i' || str[i] != 'u' || str[i] != 'd'
    ; idx += 1) {
        if (str[i] == '-' || str[i] == ' ' || str[i] == '+') {
            i += 1;
        } else {
            error_input(begin, i, str);
            return i;
        }
    }
    return i;
}
