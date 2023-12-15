/*
** EPITECH PROJECT, 2021
** my_put_nbr_base
** File description:
** base diff
*/

void my_putchar(char c);

int my_put_nbr_base(unsigned int nb, int base, char *str)
{
    if (nb >= base) {
        my_put_nbr_base((nb / base), base, str);
        my_putchar(str[(nb % base)]);
    } else {
        my_putchar(str[nb]);
    }
    return (0);
}
