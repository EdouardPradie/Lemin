/*
** EPITECH PROJECT, 2022
** lem in
** File description:
** print
*/

#include "my.h"
#include "room.h"
#include "lem_in.h"

paths_t *clean(paths_t *head)
{
    paths_t *tmp = NULL;

    while (head && !head->waze) {
        tmp = head->next;
        free(head);
        head = tmp;
    }
    return head;
}

void print_path(paths_t *path)
{
    paths_t *tmp = path;
    connexion_t *tmpcon = NULL;

    while (tmp) {
        tmpcon = tmp->waze;
        my_put_nbr(tmpcon->name);
        tmpcon = tmpcon->next;
        while (tmpcon) {
            write(1, " ", 1);
            my_put_nbr(tmpcon->name);
            tmpcon = tmpcon->next;
        }
        write(1, "\n", 1);
        tmp = tmp->next;
    }
}

void print_part(lem_in_t *src)
{
    mouv_ant(src);
}

ant_t *add_ant_to_list(ant_t *head, ant_t *node)
{
    ant_t *tmp = head;

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
