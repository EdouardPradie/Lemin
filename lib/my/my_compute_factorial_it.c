/*
** EPITECH PROJECT, 2021
** task06
** File description:
** D05
*/

int my_compute_factorial_it(int nb)
{
    int n = nb - 1;

    if (nb > 12)
        return (0);
    if (nb < 0){
        nb = 0;
    } else {
        if (nb == 0){
            nb = 1;
        }
        while (n > 0){
            nb = nb * n;
            n--;
        }
    }
    return (nb);
}
