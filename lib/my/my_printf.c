/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf
*/

#include <stdio.h>
#include <stdarg.h>

int w_flag(char *str, va_list ap, int i);

int char_spe(char const *str, int i);

void my_putchar(char c);

int my_printf(char *str, ...)
{
    va_list ap;
    va_start(ap, str);

    for (int i = 0; str[i] != '\0'; i += 1)
        if (str[i] == '%'){
            i += 1;
            i = char_spe(str, i);
            w_flag(str, ap, i);
        } else {
            my_putchar(str[i]);
        }
    va_end(ap);
    return 0;
}
