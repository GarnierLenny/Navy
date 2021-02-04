/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-navy-Lenny.garnier
** File description:
** check_x_nb
*/

#include "my.h"

int check_x_nb(char **buffer)
{
    int y = 0;
    int i = 0;
    int count = 0;

    for (; buffer[y] != NULL; y++) {
        for (i = 0; buffer[y][i] != '\0'; i++)
            if (buffer[y][i] == 'x')
                count++;
    }
    if (count == 14)
        return 1;
    return 0;
}