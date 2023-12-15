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

connexion_t *free_a_module(connexion_t *head)
{
    connexion_t *node = head->next;

    head->connexion = free_module(head->connexion);
    free(head);
    return node;
}

connexion_t *free_module(connexion_t *head)
{
    connexion_t *node = NULL;

    while (head) {
        node = head->next;
        head->connexion = free_module(head->connexion);
        free(head);
        head = node;
    }
    return NULL;
}

paths_t *free_a_path(paths_t *node)
{
    paths_t *prev = node->prev;
    paths_t *next = node->next;

    if (prev)
        prev->next = next;
    if (next)
        next->prev = prev;
    node->waze = free_module(node->waze);
    node = next;
    return node;
}

ant_t *free_a_ant(ant_t *node)
{
    ant_t *prev = node->prev;
    ant_t *next = node->next;

    if (prev)
        prev->next = next;
    if (next)
        next->prev = prev;
    node = next;
    return node;
}

void free_all(lem_in_t *src, ant_t *ant)
{
    room_t *tmp_room = NULL;

    while (src->room) {
        tmp_room = src->room->next;
        if (src->room->name) {
            free(src->room->name);
        }
        free(src->room);
        src->room = tmp_room;
    }
    for (int i = 0; src->tunnel[i] != NULL; i += 1) {
        free(src->tunnel[i]);
    }
    free(src->tunnel);
    src->module = free_module(src->module);
    free_ant(ant, src->path);
}
