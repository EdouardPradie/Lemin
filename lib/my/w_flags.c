/*
** EPITECH PROJECT, 2021
** w_flag
** File description:
** what_is_the_flag
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"
#include "my.h"

int w_flag4(char *flag, va_list ap, int i)
{
    switch (flag[i]) {
        case 'S':
            char *S = va_arg(ap, char *);
            my_putstr_nptr(S);
            break;
        case '%':
            my_putchar('%');
            break;
    }
    return 0;
}

int w_flag3(char *flag, va_list ap, int i)
{
    switch (flag[i]) {
        case 'x':
            int x = va_arg(ap, int);
            my_put_nbr_base(x, 16, "0123456789abcdef");
            break;
        case 'X':
            int X = va_arg(ap, int);
            my_put_nbr_base(X, 16, "0123456789ABCDEF");
            break;
        case 'b':
            int b = va_arg(ap, int);
            my_put_nbr_base(b, 2, "01");
            break;
    }
    w_flag4(flag, ap, i);
    return 0;
}

int w_flag2(char *flag, va_list ap, int a)
{
    switch (flag[a]) {
        case 'i':
            int i = va_arg(ap, int);
            put_cross(i, flag, a);
            my_put_nbr(i);
            break;
        case 'o':
            int o = va_arg(ap, int);
            my_put_nbr_base(o, 8, "01234567");
            break;
        case 'u':
            int u = va_arg(ap, int);
            my_put_nbr_base(u, 10, "0123456789");
            break;
    }
    w_flag3(flag, ap, a);
    return 0;
}

int w_flag(char *flag, va_list ap, int i)
{
    switch (flag[i]) {
        case 'c':
            char c = (char) va_arg(ap, int);
            my_putchar(c);
            break;
        case 'd':
            int d = va_arg(ap, int);
            put_cross(d, flag, i);
            my_put_nbr(d);
            break;
        case 's':
            char *s = va_arg(ap, char *);
            my_putstr(s);
            break;
    }
    w_flag2(flag, ap, i);
    return 0;
}
