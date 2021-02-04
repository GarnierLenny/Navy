/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-navy-Lenny.garnier
** File description:
** send_char_sig
*/

#include "my.h"

char *send_char_sig(char c, int pid)
{
    char *buffer = base_convert_str(c, 2);

    for (int i = 0; buffer[i] != '\0'; i++) {
        usleep(1);
        if (buffer[i] == '0')
            kill(pid, SIGUSR2);
        else if (buffer[i] == '1')
            kill(pid, SIGUSR1);
    }
    return buffer;
}