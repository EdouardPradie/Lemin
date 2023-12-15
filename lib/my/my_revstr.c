/*
** EPITECH PROJECT, 2021
** task03
** File description:
** D06
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int  i = my_strlen(str) - 1;
    int  j = 0;
    int k;

    while (i > j) {
        k = str[j];
        str[j] = str[i];
        str[i] = k;
        i -= 1;
        j += 1;
    }
    return (str);
}
