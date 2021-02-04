/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-navy-Lenny.garnier
** File description:
** base_convert_str
*/

#include "my.h"

int bin_to_decimal(char *str)
{
    int nb = 0;
    int ref = 1;
    int i = my_strlen(str) - 1;

    for (; i >= 0; i--, ref *= 2)
        nb = str[i] == '1' ? nb + ref : nb;
    return nb;
}

char *base_convert_str(int nb, int base)
{
    char *buffer = malloc(sizeof(char) * 10);
    int res = nb / base;
    int left = 0;
    int i = 0;

    for (; res >= 1; res = res / base, nb /= base, i++) {
        left = nb - (base * res);
        buffer[i] = left + '0';
    }
    left = nb - (base * res);
    buffer[i] = left + '0';
    buffer[i + 1] = '\0';
    buffer = my_revstr(buffer);
    return buffer;
}