/*
** EPITECH PROJECT, 2021
** TASK
** File description:
** D?
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        if (str[i] < 91 && str[i] > 64) {
            i += 1;
        } else {
            return (0);
        }
    }
    return (1);
}
