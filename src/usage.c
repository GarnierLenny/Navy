/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-navy-Lenny.garnier
** File description:
** usage
*/
#include "my.h"

int comp(char *str1, char *str2)
{
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != str2[i])
            return 0;
    }
    return 1;
}

int usage(int ac, char *av[])
{
    if (ac == 2 && comp(av[1], "-h") == 1) {
        my_printf("USAGE\n");
        my_printf("     ./navy [first_player_pid] navy_positions\n");
        my_printf("DESCRIPTION\n");
        my_printf("     first_player_pid: only for the 2nd player. pid ");
        my_printf("of the first player.\n");
        my_printf("     navy_positions: file representing the positions ");
        my_printf("of the ships.\n");
        return 1;
    }
    return 0;
}