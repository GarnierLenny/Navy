/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-navy-Lenny.garnier
** File description:
** game_loop
*/

#include "my.h"

void get_sig_hit(int signal)
{
    if (signal == SIGUSR1) {
        my_printf("hit\n\n");
        signalPid = 1;
    }
    if (signal == SIGUSR2) {
        my_printf("missed\n\n");
        signalPid = 0;
    }
}

player_t *check_sigpid_hit(player_t *p, char *buffer)
{
    int i = 0;
    int y = 0;

    p = p;
    for (; i <= (buffer[0] - 65); i++);
    for (; y <= (buffer[1] - 48); y++);
    if (signalPid == 1)
        p->en_map[y][i * 2] = 'x';
    else if (signalPid == 0)
        p->en_map[y][i * 2] = 'o';
    return p;
}

player_t *attack_loop(player_t *p, int *fd, int pid)
{
    *fd = open("files/hit", O_TRUNC | O_RDWR);
    my_printf("attack: ");
    read(0, p->buffer, 3);
    p->buffer[2] = '\0';
    my_printf("%s: ", p->buffer);
    write(*fd, p->buffer, 2);
    kill(pid, SIGUSR1);
    signal(SIGUSR1, get_sig_hit);
    signal(SIGUSR2, get_sig_hit);
    pause();
    p = check_sigpid_hit(p, p->buffer);
    disp_maps(p);
    signalPid = -1;
    return p;
}

int game_loop_p1(global_t *g, player_t *p)
{
    int fd = open("files/hit", O_TRUNC | O_RDWR);
    int x = 0;

    p->buffer = malloc(sizeof(char) * 4);
    signal(SIGUSR1, get_sig_hit);
    signal(SIGUSR2, get_sig_hit);
    while (1) {
        p = attack_loop(p, &fd, g->p2->pid);
        if ((x = check_both_map_x(p)) != 2)
            return x;
        my_printf("waiting for enemy's attack...\n");
        signal(SIGUSR1, get_sig);
        pause();
        read(fd, p->buffer, 3);
        my_printf("%s: ", p->buffer);
        p->map = check_hit(p, p->buffer, g->p2->pid, p->map);
        disp_maps(p);
    }
    close(fd);
    return 0;
}

int game_loop_p2(player_t *p)
{
    int fd2 = open("files/hit", O_TRUNC | O_RDWR);
    int x = 0;

    p->buffer = malloc(sizeof(char) * 3);
    while (1) {
        fd2 = open("files/hit", O_TRUNC | O_RDWR);
        my_printf("waiting for enemy's attack...\n");
        signal(SIGUSR1, get_sig);
        pause();
        read(fd2, p->buffer, 3);
        my_printf("%s: ", p->buffer);
        p->map = check_hit(p, p->buffer, p->pid, p->map);
        disp_maps(p);
        if ((x = check_both_map_x(p)) != 2)
            return x;
        signalPid = -1;
        attack_loop(p, &fd2, p->pid);
    }
    close(fd2);
    return 0;
}