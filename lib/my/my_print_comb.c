/*
** EPITECH PROJECT, 2021
** task05
** File description:
** D04
*/

void my_putchar(char c);

int display_comb(char a, char b, char c)
{
    if (c != 58){
        if (a < 55){
            my_putchar(a);
            my_putchar(b);
            my_putchar(c);
            my_putchar(44);
            my_putchar(32);
        } else if (a == 55){
            my_putchar(a);
            my_putchar(b);
            my_putchar(c);
        }
    }
    return (0);
}

int my_print_comb(void)
{
    char a = 48;
    char b = 49;
    char c = 50;

    display_comb(a, b, c);
    while (a != 55) {
        if (c == 57) {
            b += 1;
            c = b + 1;
        } else if (b == 57) {
            a += 1;
            b = a + 1;
            c = a + 2;
        } else {
            c += 1;
        }
        display_comb(a, b, c);
    }
    my_putchar('\n');
    return (0);
}
