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

connexion_t *dry_module(connexion_t *module, connexion_t *node_a, \
connexion_t *node_b)
{
    connexion_t *node = module;

    while (node) {
        if (node->name == node_a->name) {
            node->connexion = add_module_to_list(node->connexion, node_b);
        }
        if (node->name == node_b->name) {
            node->connexion = add_module_to_list(node->connexion, node_a);
        }
        node = node->next;
    }
    return module;
}

connexion_t *add_param_module(char **tunnel, int i)
{
    int a = 0;
    int b = 0;
    int idx = 0;
    connexion_t *node_a = NULL;
    connexion_t *node_b = NULL;

    for (int j = 0; tunnel[i][j] != '\0'; j += 1) {
        if (tunnel[i][j] == '-') {
            idx += 1;
        } else if (idx == 0) {
            a = a * 10;
            a += (tunnel[i][j] - 48);
        } else {
            b = b * 10;
            b += (tunnel[i][j] - 48);
        }
    }
    node_a = create_module(a);
    node_b = create_module(b);
    node_a = add_module_to_list(node_a, node_b);
    return node_a;
}
