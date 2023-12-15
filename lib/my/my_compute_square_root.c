/*
** EPITECH PROJECT, 2021
** task04
** File description:
** D05
*/

int my_compute_square_root(int nb)
{
    int n = 1;

    if (nb <= 0)
        return (0);
    if (nb == 1)
        return (1);
    while (n < nb){
        if (nb == n * n){
            return (n);
        } else {
            n += 1;
        }
    }
    return (0);
}
