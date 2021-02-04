/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-navy-Lenny.garnier
** File description:
** check_both_map_x
*/

#include "my.h"

int check_both_map_x(player_t *p)
{
    if (check_x_nb(p->map) == 1) {
        my_printf("Enemy won\n");
        return 1;
    }
    if (check_x_nb(p->en_map) == 1) {
        my_printf("I won\n");
        return 0;
    }
    return 2;
}