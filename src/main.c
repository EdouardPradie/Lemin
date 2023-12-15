/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** C source file for lem-in
*/

#include "lem_in.h"

int main(int ac, char *const *av, char *const *env)
{
    char *file_content = malloc(4096);
    size_t s = -1;

    if (env && ac == 1 && av != NULL) {
        s = read(STDIN_FILENO, file_content, 4096);
        if (s == -1 || s == 0)
            return 84;
        return lem_in(file_content);
    }
    return 84;
}
