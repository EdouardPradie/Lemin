/*
** EPITECH PROJECT, 2021
** task010
** File description:
** D06
*/

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str)
{
    str = my_strlowcase(str);

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] < 123 && str[i] > 96 && \
        (str[i] == str[0] || str[i - 1] == ' ' \
        || str[i - 1] == '+' || str[i - 1] == '-')) {
            str[i] -= 32;
        }
    }
    return (str);
}
