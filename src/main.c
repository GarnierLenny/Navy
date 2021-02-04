/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-navy-Lenny.garnier
** File description:
** main
*/

#include "my.h"

char **place_boats_2(player_t *p, char *from, char *to, char nb)
{
    int i = 1;
    int y = 1;

    to = to;
    for (; i <= (from[0] - 65); i++);
    for (; y <= (from[1] - 48); y++);
    for (int x = 0; 1; x++) {
        p->map[y][i * 2] = nb;
        if (i > (to[0] - 'A') && y > (to[1] - '0'))
            break;
        if (i <= (to[0] - 'A'))
            i++;
        if (y <= (to[1] - '0'))
            y++;
        p->map[y][i * 2] = nb;
    }
    return p->map;
}

char **place_boats(player_t *p, char *path)
{
    int fd = open(path, O_RDONLY);
    char *str = malloc(sizeof(char) * 35);
    char **buffer = NULL;
    int i = 0;

    p = p;
    read(fd, str, 33);
    for (; str[i + 1] != '\0'; i++);
    str[i] = ':';
    buffer = str_to_word_array_sep(str, ':');
    p->map = place_boats_2(p, buffer[1], buffer[2], '2');
    p->map = place_boats_2(p, buffer[3], buffer[4], '3');
    p->map = place_boats_2(p, buffer[5], buffer[6], '4');
    p->map = place_boats_2(p, buffer[7], buffer[8], '5');
    return buffer;
}

int main(int ac, char **av)
{
    global_t *g = malloc(sizeof(global_t));

    if (usage(ac, av) == 1)
        return 0;
    if (error_cases(ac, av) == 84)
        return 84;
    g->p1 = malloc(sizeof(player_t));
    g->p2 = malloc(sizeof(player_t));
    if (ac == 2) {
        g->p1->map = set_map_empty(g->p1);
        g->p1->en_map = set_map_empty(g->p1);
        place_boats(g->p1, av[1]);
        return(bef_game_p1(g));
    } else {
        g->p2->map = set_map_empty(g->p2);
        g->p2->en_map = set_map_empty(g->p2);
        place_boats(g->p2, av[2]);
        return (bef_game_p2(g, gnb(av[1])));
    }
    return 0;
}