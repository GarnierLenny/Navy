/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-navy-Lenny.garnier
** File description:
** disp_ss
*/

#include "my.h"

void disp_ss(char **buffer)
{
    for (int i = 0; buffer[i] != NULL; i++)
        my_printf("%s", buffer[i]);
}

void disp_maps(player_t *p)
{
    my_printf("my positions:\n");
    disp_ss(p->map);
    my_printf("\nenemy's positions:\n");
    disp_ss(p->en_map);
    my_printf("\n");
}