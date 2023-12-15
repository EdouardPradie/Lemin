/*
** EPITECH PROJECT, 2022
** lem_in.c
** File description:
** C source file for lem-in
*/

#include "lem_in.h"
#include "my.h"
#include "room.h"

int add_nb_ant(char **array)
{
    int result = 0;

    for (int i = 0; array[0][i] != '\0'; i += 1) {
        if (array[0][i] >= '0' && array[0][i] <= '9') {
            result = result * 10;
            result += (array[0][i] - 48);
        } else {
            return -1;
        }
    }
    return result;
}

room_t *add_room(char **array)
{
    room_t *head = NULL;
    room_t *node = NULL;

    for (int i = 1; !array[i] || is_a_conection(array[i]) == 1; i += 1) {
        if (my_strcmp(array[i], "##") == 0) {
            node = create_node_named(array, i);
            if (!node)
                return NULL;
            head = add_node_to_list(head, node);
            i += 1;
        } else if (is_a_room(array[i]) == 0){
            node = create_node(array, i);
            head = add_node_to_list(head, node);
        } else if (array[i][0] == '#') {
            i = i;
        } else {
            return NULL;
        }
    }
    return head;
}

char **add_tunnel(char **array)
{
    char **result = malloc(sizeof(char *) * (nb_tunnel(array) + 1));
    int idx = 0;
    int i = 0;

    while (is_a_conection(array[idx]) == 1) {
        idx += 1;
    }
    while (array[idx] != NULL) {
        if (is_a_conection(array[idx]) == 0) {
            result[i] = malloc(sizeof(char) * (my_strlen(array[idx]) + 1));
            result[i] = my_strcpy(result[i], array[idx]);
            i += 1;
        } else if (array[idx][0] == '#') {
            i = i;
        } else {
            return NULL;
        }
        idx += 1;
    }
    result[i] = NULL;
    return result;
}

lem_in_t *get_param(char **array)
{
    lem_in_t *result = malloc(sizeof(lem_in_t));

    result->nb_ant = add_nb_ant(array);
    if (result->nb_ant == -1) {
        free(result);
        return NULL;
    }
    my_printf("#number_of_ant\n%d\n", result->nb_ant);
    result->room = add_room(array);
    my_putstr("#rooms\n");
    if (result->room == NULL) {
        free(result);
        return NULL;
    }
    print_room(result->room);
    result->tunnel = add_tunnel(array);
    my_putstr("#tunnels\n");
    if (result->tunnel == NULL) {
        free(result);
        return NULL;
    }
    my_show_word_array(result->tunnel);
    return result;
}

int lem_in(char *file_content)
{
    char **result = NULL;
    lem_in_t *src = NULL;

    result = my_str_to_word_array_pos(file_content, '\n');
    if (result != NULL) {
        src = get_param(result);
        if (!src) {
            free(result);
            return 84;
        }
        return get_module(src);
    }
    return 84;
}
