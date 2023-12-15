/*
** EPITECH PROJECT, 2021
** task08
** File description:
** D06
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0';i += 1) {
        if (str[i] < 123 && str[i] > 96)
            str[i] -= 32;
    }
    return (str);
}
