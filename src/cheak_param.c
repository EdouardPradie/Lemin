/*
** EPITECH PROJECT, 2022
** cheak_param.c
** File description:
** C source file for lem-in
*/

#include "lem_in.h"
#include "my.h"
#include "room.h"

int is_a_conection(char *str)
{
    int eq = 0;
    int error = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '-')
            eq += 1;
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
            error = 1;
    }
    if (eq == 1 && error == 0) {
        return 0;
    }
    return 1;
}

int is_a_room(char *str)
{
    int space = 0;
    int error = 0;

    for (int i = 0; str[i] != '\0' && str[i] != '#'; i += 1) {
        if (str[i] == ' ')
            space += 1;
        if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
            error = 1;
    }
    if ((space == 2 || space == 3) && error == 0) {
        return 0;
    }
    return 1;
}

int nb_tunnel(char **array)
{
    int result = 0;

    for (int i = 0; array[i] != NULL; i += 1) {
        if (is_a_conection(array[i]) == 0) {
            result += 1;
        }
    }
    return result;
}
