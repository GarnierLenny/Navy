/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-navy-Lenny.garnier
** File description:
** get_sig_str
*/

#include "my.h"

int get_sig_str(struct sigaction *sa, int *y)
{
    char *buffer = malloc(sizeof(char) * 8);

    for (int i = 0; i <= 5000; i++) {
        sigaction(SIGUSR1, sa, NULL);
        sigaction(SIGUSR2, sa, NULL);
        buffer = fill_bin_str(buffer, y, 1);
        buffer = fill_bin_str(buffer, y, 0);
    }
    *y = 0;
    return bin_to_decimal(buffer);
}

int get_sig_str_signal(int *y)
{
    char *buffer = malloc(sizeof(char) * 8);

    for (int i = 0; i <= 5000; i++) {
        signal(SIGUSR1, get_sig);
        signal(SIGUSR2, get_sig);
        buffer = fill_bin_str(buffer, y, 1);
        buffer = fill_bin_str(buffer, y, 0);
    }
    *y = 0;
    return bin_to_decimal(buffer);
}