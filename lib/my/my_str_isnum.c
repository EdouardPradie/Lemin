/*
** EPITECH PROJECT, 2021
** TASk
** File description:
** D?
*/

int my_str_isnum(char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] <= '9' && str[i] >= '0') {
            i += 1;
        } else {
            return 0;
        }
    }
    return 1;
}
