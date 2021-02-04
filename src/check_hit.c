/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-navy-Lenny.garnier
** File description:
** check_hit
*/

#include "my.h"

int is_char_boat(char c)
{
    if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5')
        return 1;
    return 0;
}

char **check_hit(player_t *p, char *buffer, int pid, char **tab)
{
    int i = 0;
    int y = 0;

    p = p;
    for (; i <= (buffer[0] - 65); i++);
    for (; y <= (buffer[1] - 48); y++);
    if (is_char_boat(tab[y][i * 2]) == 1) {
        tab[y][i * 2] = 'x';
        kill(pid, SIGUSR1);
        my_printf("hit\n\n");
        return tab;
    }
    my_printf("missed\n\n");
    tab[y][i * 2] = 'o';
    kill(pid, SIGUSR2);
    return tab;
}