/*
** EPITECH PROJECT, 2021
** bs
** File description:
** pos
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "lem_in.h"
#include "room.h"

static int my_isalphanum_pos(char c, char pos)
{
    if (c != pos && c != '\n' && c != '\0'){
        return (1);
    }
    return (0);
}

static int get_nb_words_pos(char const *str, char pos)
{
    int i = 0;
    int nb_words = 0;

    while (str[i] != '\0') {
        if (my_isalphanum_pos(str[i], pos) == 1 &&
            my_isalphanum_pos(str[i + 1], pos) == 0){
            nb_words += 1;
            }
        i += 1;
    }
    return (nb_words);
}

static int my_lenword_pos(char const *str, int total, char pos)
{
    int idx = 0;

    while (my_isalphanum_pos(str[total], pos) != 1 &&
    str[total] != '\0') {
        total += 1;
    }
    while (my_isalphanum_pos(str[total], pos) != 0 &&
    str[total] != '\0'){
        idx += 1;
        total += 1;
    }
    return idx;
}

char **my_str_to_word_array_pos(char const *str, char pos)
{
    char **dest = NULL;
    int total = 0;
    int s = 0;
    int nb_words = get_nb_words_pos(str, pos);

    dest = malloc(sizeof(char *) * (nb_words + 1));
    dest[nb_words] = NULL;
    if (str == NULL){
        return NULL;
    }
    for (int j = 0; j != nb_words; j += 1) {
        s = my_lenword_pos(str, total, pos);
        dest[j] = malloc(sizeof(char) * (s + 1));
        for (int f = 0; f != s; f += 1)
            dest[j][f] = str[total + f];
        dest[j][s] = '\0';
        total += (s + 1);
    }
    return dest;
}

void free_ant(ant_t *ant, paths_t *path)
{
    ant_t *tmp_ant = NULL;
    paths_t *tmp_path = NULL;

    while (ant) {
        tmp_ant = ant->next;
        free(ant);
        ant = tmp_ant;
    }
    while (path) {
        tmp_path = path->next;
        free(path);
        path = tmp_path;
    }
}
