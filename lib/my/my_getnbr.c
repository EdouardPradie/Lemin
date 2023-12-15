/*
** EPITECH PROJECT, 2021
** task05
** File description:
** 5
*/

int my_putstr(char const *str);

char *first_number(int a, char const *str)
{
    char *src;
    int k = 0;
    int j = a;

    if (str[j] >= '0' && str[j] <= '9') {
        while (str[j] >= '0' && str[j] <= '9') {
            src[k] = str[j];
            j += 1;
            k += 1;
        }
        src[k] = '\0';
        return (src);
    }
}

int my_getnbr(char const *str)
{
    int result = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        result = result * 10;
        result += (str[i] - 48);
    }
    return result;
}
