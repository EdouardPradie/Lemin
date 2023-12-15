/*
** EPITECH PROJECT, 2021
** task01
** File description:
** D05
*/

void my_putchar(char c);

int my_print_alpha(void)
{
    int nb = 97;

    while (nb <= 122){
        my_putchar(nb);
        nb++;
    }
    return (0);
    my_putchar('\n');
}
