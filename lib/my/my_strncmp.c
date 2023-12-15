/*
** EPITECH PROJECT, 2021
** task07
** File description:
** D06
*/

int my_strlen(char const *str);

int comp(int v, int n)
{
    if (v > n)
        v = n;
    return (v);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int a = my_strlen(s1) + 1;
    int b = my_strlen(s2) + 1;
    int r;

    comp(a, n);
    comp(b, n);
    for (int i = 0; i != a && i != b; i += 1) {
        if (s1[i] != s2[i]) {
            r += s1[i] - s2[i];
            return (r);
        }
    }
    return (0);
}
