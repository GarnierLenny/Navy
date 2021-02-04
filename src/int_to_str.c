/*
** EPITECH PROJECT, 2020
** B-MUL-100-RUN-1-1-myhunter-lenny.garnier
** File description:
** int_to_str
*/

#include "my.h"

int find_nb_div(int nb)
{
    int div = 1;

    while (div <= nb)
        div = div * 10;
    div = div / 10;
    return div;
}

char *int_to_str(int nb)
{
    int div = find_nb_div(nb);
    char *buffer = malloc(sizeof(char) * div + 3);
    int i = 0;

    if (nb == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return buffer;
    }
    for (; div > 0; i++) {
        buffer[i] = (nb / div) + '0';
        nb = nb % div;
        div /= 10;
    }
    buffer[i] = '\0';
    return buffer;
}