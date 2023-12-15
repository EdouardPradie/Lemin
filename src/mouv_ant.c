/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-lemin-pierre.bouillard
** File description:
** mouv_ant.c
*/

#include "my.h"
#include "lem_in.h"

int get_len_of_path(lem_in_t *src)
{
    int i = 0;
    paths_t *path = src->path;

    while (path) {
        i += 1;
        path = path->next;
    }
    return i;
}

int **malloc_path(lem_in_t *src, int **tab)
{
    paths_t *path = src->path;
    connexion_t *con = NULL;
    int i = 0;
    int len = 0;

    while (path != NULL) {
        len = 0;
        con = path->waze;
        while (con) {
            len += 1;
            con = con->next;
        }
        tab[i] = malloc(sizeof(int) * (len + 1));
        tab[i][len] = -1;
        i += 1;
        path = path->next;
    }
    return tab;
}

int **path_to_int(lem_in_t *src)
{
    int **tab = malloc(sizeof(int *) * (get_len_of_path(src) + 1));
    int i = 0;
    int j = 0;
    paths_t *path = src->path;
    connexion_t *con = NULL;

    tab[get_len_of_path(src)] = NULL;
    tab = malloc_path(src, tab);
    while (path) {
        con = path->waze;
        while (tab[i][j] != -1) {
            tab[i][j] = con->name;
            con = con->next;
            j += 1;
        }
        j = 0;
        path = path->next;
        i += 1;
    }
    return tab;
}

int print_mouv(ant_t *ant, int **path)
{
    ant_t *head = ant;

    while (ant->next) {
        if (path[ant->path][ant->pos] != -1) {
            my_putchar('P');
            my_put_nbr(ant->ant);
            my_putchar('-');
            my_put_nbr(path[ant->path][ant->pos]);
            my_putchar(' ');
            ant->pos += 1;
        }
        ant = ant->next;
    }
    if (path[ant->path][ant->pos] != -1) {
        my_putchar('P');
        my_put_nbr(ant->ant);
        my_putchar('-');
        my_put_nbr(path[ant->path][ant->pos]);
        my_putchar('\n');
        ant->pos += 1;
        ant = ant->next;
    } else {
        return 1;
    }
    ant = head;
    return 0;
}

int mouv_ant(lem_in_t *src)
{
    int **path = path_to_int(src);
    ant_t *head = NULL;
    ant_t * node = NULL;
    int nb_ant = 1;
    int idx = 0;

    my_putstr("\n#moves\n");
    while(idx == 0) {
        if (nb_ant <= src->nb_ant) {
            for (int i = 0; path[i] != NULL && nb_ant <= src->nb_ant; i += 1) {
                node = malloc(sizeof(ant_t));
                node->ant = nb_ant;
                node->path = i;
                node->pos = 1;
                node->next = NULL;
                nb_ant += 1;
                head = add_ant_to_list(head, node);
            }
        }
        if (print_mouv(head, path) != 0) {
            idx += 1;
        }
    }
    free_all(src, head);
    return 0;
}
