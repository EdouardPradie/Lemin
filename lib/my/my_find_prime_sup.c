/*
** EPITECH PROJECT, 2021
** task07
** File description:
** D05
*/

int my_is_prime(int n);

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb) == 1){
        return (nb);
    } else {
        my_find_prime_sup(nb + 1);
    }
}
