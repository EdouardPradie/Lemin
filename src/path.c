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

int does_exist(paths_t *node, int val)
{
    connexion_t *tmp = node->waze;

    while (tmp) {
        if (tmp->name == val)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

paths_t *add_path_to_list(paths_t *head, paths_t *node)
{
    paths_t *tmp = head;

    if (head == NULL) {
        head = node;
    } else {
        while (tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = node;
        node->prev = tmp;
        node->next = NULL;
    }
    return head;
}

paths_t *cp_path(paths_t *head, int name)
{
    paths_t *node = malloc(sizeof(paths_t));
    connexion_t *tmp = NULL;
    connexion_t *con = head->waze;

    node->waze = NULL;
    while (con) {
        tmp = create_module(con->name);
        node->waze = add_module_to_list(node->waze, tmp);
        con = con->next;
    }
    tmp = create_module(name);
    node->waze = add_module_to_list(node->waze, tmp);
    return node;
}

paths_t *add_good_path(paths_t *head)
{
    paths_t *tmp = NULL;
    paths_t *result = NULL;

    while (head) {
        if (result == NULL || ligaments_croiser(result, head) == 0) {
            tmp = head;
            head = head->next;
            tmp->next = NULL;
            tmp->prev = NULL;
            result = add_path_to_list(result, tmp);
        } else {
            head = free_a_path(head);
        }
    }
    head = result;
    return head;
}

paths_t *add_path(paths_t *tmp, connexion_t *module)
{
    paths_t *node = NULL;
    connexion_t *connexion = module->connexion;

    while (connexion) {
        if (does_exist(tmp, connexion->name) == 0) {
            node = cp_path(tmp, connexion->name);
            tmp = add_path_to_list(tmp, node);
        }
        connexion = connexion->next;
    }
    return tmp;
}
