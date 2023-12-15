/*
** EPITECH PROJECT, 2021
** TASK
** File description:
** D?
*/

int my_str_islower(char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] < 123 && str[i] > 96) {
            i += 1;
        } else {
            return (0);
        }
    }
    return (1);
}
