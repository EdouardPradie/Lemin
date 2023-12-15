/*
** EPITECH PROJECT, 2021
** task06
** File description:
** D05
*/

int my_is_prime(int nb)
{
    int n = 2;

    if (nb < 2)
        return (0);
    while (n != nb) {
        if ((nb % n) == 0){
            return (0);
        } else {
            n += 1;
        }
    }
    return (1);
}
