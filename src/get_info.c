/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-navy-Lenny.garnier
** File description:
** get_info
*/
#define _GNU_SOURCE
#include "my.h"

void get_pid(int sig, siginfo_t *info, void *context)
{
    (void)sig;
    (void)context;
    signalPid = info->si_pid;
}

void get_sig(int signal)
{
    signal = signal;
    if (signal == SIGUSR1) {
        signalPid = 1;
    }
    else if (signal == SIGUSR2) {
        signalPid = 0;
    }
    return;
}

char *fill_bin_str(char *str, int *y, int value)
{
    char *buffer = my_strdup(str);

    if (signalPid == value) {
        buffer[*y] = value + 48;
        signalPid = -1;
        *y += 1;
    }
    return buffer;
}

int bef_game_p1(global_t *g)
{
    struct sigaction sa;
    int fd = open("files/pos", O_RDWR);
    char *buffer = malloc(sizeof(char) * 3);

    fd = fd;
    buffer = buffer;
    my_printf("my_pid: %d\n", getpid());
    sa.sa_handler = get_sig;
    sa.sa_flags = SA_SIGINFO;
    my_putstr("waiting for enemy connection...\n\n");
    sa.sa_sigaction = get_pid;
    sigaction(SIGUSR1, &sa, NULL);
    pause();
    my_printf("enemy connected\n\n");
    disp_maps(g->p1);
    g->p2->pid = signalPid;
    if (game_loop_p1(g, g->p1) == 1)
        return 1;
    return 0;
}

int bef_game_p2(global_t *g, int pid)
{
    char *buffer = malloc(sizeof(char) * 3);
    int fd = open("files/pos", O_RDWR | O_TRUNC);

    fd = fd;
    buffer = buffer;
    g->p2->pid = pid;
    my_printf("my_pid: %d\n", getpid());
    kill(pid, SIGUSR1);
    my_putstr("successfully connected\n\n");
    disp_maps(g->p2);
    usleep(100);
    if (game_loop_p2(g->p2) == 1)
        return 1;
    return 0;
}