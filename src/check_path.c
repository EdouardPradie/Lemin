/*
** EPITECH PROJECT, 2021
** check_path
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

paths_t *check_path_module(paths_t *tmp, connexion_t *module)
{
    connexion_t *mod = module;

    while (mod) {
        if (last_module(tmp->waze) == mod->name)
            tmp = add_path(tmp, mod);
        mod = mod->next;
    }
    tmp = free_a_path(tmp);
    return tmp;
}

int is_equal(connexion_t *a, connexion_t *b)
{
    while (a != NULL && b != NULL) {
        if (a->name != b->name)
            return 1;
        a = a->next;
        b = b->next;
    }
    if (a != NULL || b != NULL)
        return 1;
    return 0;
}

int ligaments_croiser(paths_t *result, paths_t *head)
{
    paths_t *tmp = result;
    connexion_t *tmp_connexion = NULL;
    connexion_t *tmp_conn_head = NULL;
    int idx = 0;

    while (tmp) {
        tmp_connexion = tmp->waze;
        idx = 0;
        while (tmp_connexion) {
            tmp_conn_head = head->waze;
            if (is_equal(tmp_conn_head, tmp_connexion) == 0) {
                return 0;
            }
            while (tmp_conn_head) {
                if (tmp_conn_head->name == tmp_connexion->name)
                    idx += 1;
                tmp_conn_head = tmp_conn_head->next;
            }
            tmp_connexion = tmp_connexion->next;
        }
        if (idx != 2)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}
