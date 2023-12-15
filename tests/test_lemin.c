/*
** EPITECH PROJECT, 2022
** test_lemin.c
** File description:
** C source file for B-CPE-200-BDX-2-1-lemin-pierre.bouillard
*/

#include "lem_in.h"
#include <criterion/criterion.h>

char *open_file(char const *filepath);

Test (lem_in, test_return_wrong_input) {
    char *file = open_file("bonus/tests/file.txt");
    cr_assert_eq(lem_in(file), 84);
}

Test (lem_in, test_return_good) {
    char *file = open_file("bonus/tests/good.txt");
    cr_assert_eq(lem_in(file), 0);
}