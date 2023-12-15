/*
** EPITECH PROJECT, 2021
** task03
** File description:
** D05
*/
#include <stdio.h>

int my_compute_power_it(int nb, int p)
{
    int n = nb;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    while (p != 1) {
        nb = nb * n;
        p--;
    }
    return (nb);
}
