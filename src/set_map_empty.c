/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-navy-Lenny.garnier
** File description:
** set_map_empty
*/

#include "my.h"

char **set_map_empty(player_t *p)
{
    int fd = open("files/pattern", O_RDONLY);
    int i = 0;
    char **buffer = malloc(sizeof(char *) * 10);

    p = p;
    for (; i <= 10; i++) {
        buffer[i] = malloc(sizeof(char) * 18);
        read(fd, buffer[i], 18);
    }
    buffer[i] = NULL;
    close(fd);
    return buffer;
}