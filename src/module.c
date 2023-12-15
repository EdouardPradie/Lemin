/*
** EPITECH PROJECT, 2021
** module
** File description:
** lemin
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "my.h"
#include "lem_in.h"
#include "room.h"

connexion_t *add_module_to_list(connexion_t *head, connexion_t *node)
{
    connexion_t *tmp = head;

    if (!head) {
        head = node;
    } else {
        while (tmp->next){
            tmp = tmp->next;
        }
        tmp->next = node;
        node->next = NULL;
    }
    return head;
}

int print_module(connexion_t *head)
{
    connexion_t *tmp = head;
    connexion_t *tmp_con = NULL;

    while (tmp) {
        my_put_nbr(tmp->name);
        tmp_con = tmp->connexion;
        write(1, " ", 1);
        while (tmp_con) {
            write(1, " ", 1);
            my_put_nbr(tmp_con->name);
            tmp_con = tmp_con->next;
        }
        write(1, "\n", 1);
        tmp = tmp->next;
    }
    return 0;
}

connexion_t *create_module(int room)
{
    connexion_t *node = malloc(sizeof(connexion_t));

    node->name = room;
    node->next = NULL;
    node->connexion = NULL;
    return node;
}

connexion_t *add_tunnelmodule(connexion_t *module, char **tunnel)
{
    connexion_t *node_a = NULL;
    connexion_t *node_b = NULL;

    for (int i = 0; tunnel[i] != NULL; i += 1) {
        node_a = add_param_module(tunnel, i);
        node_b = node_a->next;
        node_a->next = NULL;
        module = dry_module(module, node_a, node_b);
    }
    return module;
}

int get_module(lem_in_t *src)
{
    room_t *tmp = src->room;
    connexion_t *node = NULL;
    int nb_name = 0;

    src->module = NULL;
    while (tmp) {
        if (tmp->name)
            nb_name += 1;
        node = create_module(tmp->room_idx);
        src->module = add_module_to_list(src->module, node);
        tmp = tmp->next;
    }
    if (nb_name != 2) {
        return 84;
    }
    src->module = add_tunnelmodule(src->module, src->tunnel);
    return init_path(src);
}
