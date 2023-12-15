/*
** EPITECH PROJECT, 2021
** task02
** File description:
** D06
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int d = my_strlen(dest);
    int s = my_strlen(src);

    for (int lensrc = 0; lensrc != n; lensrc += 1){
        dest[lensrc] = src[lensrc];
    }
    if (dest[d] < dest[n] && dest[n] < src[s])
        dest[n + 1] = '\0';
    return (dest);
}
