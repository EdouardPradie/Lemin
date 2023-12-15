/*
** EPITECH PROJECT, 2021
** task06
** File description:
** D06
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    if (!s1 || !s2)
        return 1;
    int a = my_strlen(s1);
    int b = my_strlen(s2);

    if (s1 == 0 || s2 == 0)
        return 1;
    for (int i = 0; i < a && i < b; i += 1) {
        if (s1[i] != s2[i]) {
            return (1);
        }
    }
    return 0;
}
