/*
** EPITECH PROJECT, 2021
** TASK
** File description:
** D?
*/

#include <stdlib.h>

void my_putchar(char c);

int my_putstr(char const *str);

int my_put_nbr(int nb)
{
    if (nb == -2147483648){
        my_putstr("-2147483648");
        return (0);
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + 48);
    } else {
        my_putchar(nb + 48);
    }
    return (0);
}
