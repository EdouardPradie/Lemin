/*
** EPITECH PROJECT, 2021
** task03
** File description:
** D05
*/

void my_putchar(char c);

int my_print_digits(void)
{
    int nb = 48;

    while (nb <= 57){
        my_putchar(nb);
        nb++;
    }
    return (0);
    my_putchar('\n');
}
