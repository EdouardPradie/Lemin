/*
** EPITECH PROJECT, 2021
** task
** File description:
** D?
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] < 0 || str[i] > 127)
            return (1);
    }
    return (0);
}
