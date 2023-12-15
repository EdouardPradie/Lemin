/*
** EPITECH PROJECT, 2021
** task02
** File description:
** D05
*/

void my_putchar(char c);

int my_print_revalpha(void)
{
    int nb = 122;

    while (nb >= 97){
        my_putchar(nb);
        nb--;
    }
    return (0);
    my_putchar('\n');
}
