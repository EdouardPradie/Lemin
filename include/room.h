/*
** EPITECH PROJECT, 2022
** room.h
** File description:
** C source file for B-CPE-200-BDX-2-1-lemin-pierre.bouillard
*/

#ifndef ROOM_H
    #define ROOM_H
    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <stdlib.h>

typedef struct room_s {
    char *name;
    int room_idx;
    int x;
    int y;
    struct room_s *next;
}room_t;

typedef struct connexion_s {
    int name;
    struct connexion_s *connexion;
    struct connexion_s *next;
}connexion_t;

typedef struct paths_s {
    connexion_t *waze;
    struct paths_s *prev;
    struct paths_s *next;
}paths_t;

typedef struct ant_s {
    int ant;
    int path;
    int pos;
    struct ant_s *next;
    struct ant_s *prev;
}ant_t;

typedef struct lem_in_s {
    int nb_ant;
    room_t *room;
    char **tunnel;
    connexion_t *module;
    paths_t *path;
}lem_in_t;

#endif