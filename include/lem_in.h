/*
** EPITECH PROJECT, 2022
** lem_in.h
** File description:
** C source file for B-CPE-200-BDX-2-1-lemin-pierre.bouillard
*/

#ifndef B_CPE_200_BDX_2_1_LEMIN_PIERRE_BOUILLARD__H
    #define B_CPE_200_BDX_2_1_LEMIN_PIERRE_BOUILLARD__H
    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include "room.h"

int lem_in(char *file_content);

char *open_file(char const *filepath);

char **my_str_to_word_array_pos(char const *file, char pos);

room_t *add_node_to_list(room_t *head, room_t *node);

room_t *create_node(char **array, int i);

room_t *create_node_named(char **array, int i);

int print_room(room_t *head);

int is_a_conection(char *str);

int is_a_room(char *str);

int print_room(room_t *head);

int nb_tunnel(char **array);

int get_module(lem_in_t *src);

int *char_to_int(char *str);

int *add_nb(int *tab, int nb);

int init_struct(lem_in_t *lem_in);

int add_module(lem_in_t *src);

connexion_t *add_param_module(char **tunnel, int i);

connexion_t *add_module_to_list(connexion_t *head, connexion_t *node);

connexion_t *create_module(int room);

connexion_t *dry_module(connexion_t *module, connexion_t *node_a, \
connexion_t *node_b);

paths_t *add_path(paths_t *tmp, connexion_t *module);

paths_t *cp_path(paths_t *head, int name);

int init_path(lem_in_t *src);

void print_path(paths_t *path);

void print_part(lem_in_t *src);

paths_t *free_a_path(paths_t *node);

connexion_t *free_module(connexion_t *head);

connexion_t *free_a_module(connexion_t *head);

int mouv_ant(lem_in_t *src);

int print_mouv(ant_t *head, int **path);

ant_t *free_a_ant(ant_t *node);

int **path_to_int(lem_in_t *src);

int get_len_of_path(lem_in_t *src);

paths_t *add_good_path(paths_t *head);

paths_t *check_path_module(paths_t *tmp, connexion_t *module);

int last_module(connexion_t *module);

ant_t *add_ant_to_list(ant_t *head, ant_t *node);

int ligaments_croiser(paths_t *result, paths_t *head);

void free_ant(ant_t *ant, paths_t *path);

paths_t *clean(paths_t *head);

void free_all(lem_in_t *src, ant_t *ant);

#endif
