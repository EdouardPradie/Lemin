/*
** EPITECH PROJECT, 2021
** creat_path
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

connexion_t *find_module(connexion_t *head, int idx)
{
    connexion_t *result = head;

    while (result && result->name != idx) {
        result = result->next;
    }
    return result;
}

int last_module(connexion_t *module)
{
    connexion_t *tmp = module;

    while (tmp->next) {;
        tmp = tmp->next;
    }
    return tmp->name;
}

paths_t *parce_path(paths_t *head, connexion_t *module, connexion_t *ending)
{
    paths_t *tmp = head;

    while (tmp) {
        tmp->waze->connexion = NULL;
        if (last_module(tmp->waze) != ending->name) {
            tmp = check_path_module(tmp, module);
        } else
            tmp = tmp->next;
    }
    return clean(head);
}

int make_path(lem_in_t *src, int start, int end)
{
    paths_t *node = NULL;
    connexion_t *begin = find_module(src->module, start);
    connexion_t *ending = find_module(src->module, end);

    if (begin == NULL || ending == NULL)
        return 84;
    node = malloc(sizeof(paths_t));
    node->waze = malloc(sizeof(connexion_t));
    node->waze->name = begin->name;
    node->waze->next = NULL;
    node->next = NULL;
    node->prev = NULL;
    src->path = parce_path(node, src->module, ending);
    if (!src->path) {
        free_all(src, NULL);
        return 84;
    }
    src->path = add_good_path(src->path);
    print_part(src);
    return 0;
}

int init_path(lem_in_t *src)
{
    room_t *tmp = src->room;
    int start = -1;
    int end = -1;

    while (tmp) {
        if (tmp->name && my_strcmp(tmp->name, "##start") == 0)
            start = tmp->room_idx;
        if (tmp->name && my_strcmp(tmp->name, "##end") == 0)
            end = tmp->room_idx;
        tmp = tmp->next;
    }
    return make_path(src, start, end);
}
