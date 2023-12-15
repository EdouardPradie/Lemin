/*
** EPITECH PROJECT, 2021
** task09
** File description:
** D06
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0';i += 1) {
        if (str[i] < 91 && str[i] > 64)
            str[i] += 32;
    }
    return (str);
}
