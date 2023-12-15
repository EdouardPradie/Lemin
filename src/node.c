/*
** EPITECH PROJECT, 2021
** node
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

room_t *init_node(void)
{
    room_t *node = malloc(sizeof(room_t));

    node->room_idx = 0;
    node->x = 0;
    node->y = 0;
    node->name = NULL;
    return node;
}

room_t *create_node(char **array, int i)
{
    room_t *node = init_node();
    int space = 0;

    for (int j = 0; space <= 2; j += 1) {
        if (array[i][j] == ' ' || array[i][j] == '\0') {
            space += 1;
        } else if (space == 1) {
            node->x = node->x * 10;
            node->x += array[i][j] - 48;
        } else if (space == 2) {
            node->y = node->y * 10;
            node->y += (array[i][j] - 48);
        } else if (space == 0) {
            node->room_idx = node->room_idx * 10;
            node->room_idx += (array[i][j] - 48);
        }
    }
    node->next = NULL;
    return node;
}

room_t *create_node_named(char **array, int i)
{
    room_t *node = NULL;

    if (is_a_room(array[i + 1]) == 0) {
        node = create_node(array, i + 1);
    } else {
        return NULL;
    }
    node->name = malloc(sizeof(char) * (my_strlen(array[i]) + 1));
    node->name = my_strcpy(node->name, array[i]);
    return node;
}

room_t *add_node_to_list(room_t *head, room_t *node)
{
    room_t *tmp = head;

    if (head == NULL) {
        head = node;
    } else {
        while (tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = node;
    }
    return head;
}

int print_room(room_t *head)
{
    room_t *tmp = head;

    while (tmp) {
        if (tmp->name != NULL) {
            my_putstr(tmp->name);
            write(1, "\n", 1);
        }
        my_put_nbr(tmp->room_idx);
        write(1, " ", 1);
        my_put_nbr(tmp->x);
        write(1, " ", 1);
        my_put_nbr(tmp->y);
        write(1, "\n", 1);
        tmp = tmp->next;
    }
    return 0;
}
