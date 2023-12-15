/*
** EPITECH PROJECT, 2021
** task04
** File description:
** D05
*/

int my_compute_power_rec(int nb, int p)
{
    int res;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    res = nb * my_compute_power_rec(nb, p - 1);
    return (res);
}
