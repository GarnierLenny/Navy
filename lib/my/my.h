/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday07-lenny.garnier
** File description:
** my
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdarg.h>
#include <signal.h>

#define scp my_strcpy
#define gnb my_getnbr
#define its int_to_str
#define bf buffer
#define _GNU_SOURCE

#ifndef MY_H_
#define MY_H_

typedef enum {
    false,
    true,
} Bool;

typedef struct player_s {
    int pid;
    char **map;
    char **en_map;
    char *buffer;
} player_t;

typedef struct global_s {
    player_t *p1;
    player_t *p2;
} global_t;

static volatile int signalPid = - 1;

int usage(int ac, char *av[]);
void my_putchar(char c);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char *src);
char **my_str_to_word_array(char const *str);
char *my_strdup(char const *src);
void disp_ss(char **buffer);
char **str_to_word_array_sep(char *str, char separator);
int my_printf(char const *str, ...);
int convert_coord_bin(char *coord);
char *my_revstr(char *str);
char *base_convert_str(int nb, int base);
char *int_to_str(int nb);
int bin_to_decimal(char *str);
void get_sig(int signal);
void get_pid(int sig, siginfo_t *info, void *context);
int bef_game_p1(global_t *g);
int bef_game_p2(global_t *g, int pid);
char *send_char_sig(char c, int pid);
int get_sig_str(struct sigaction *sa, int *y);
char *fill_bin_str(char *str, int *y, int value);
int get_sig_str_signal(int *y);
void disp_ss(char **buffer);
void disp_maps(player_t *p);
char **str_to_word_array_sep(char *str, char separator);
char **set_map_empty(player_t *p);
int game_loop_p1(global_t *g, player_t *p);
int game_loop_p2(player_t *p);
char **check_hit(player_t *p, char *buffer, int pid, char **tab);
int is_char_boat(char c);
player_t *check_sigpid_hit(player_t *p, char *buffer);
int check_x_nb(char **buffer);
int check_both_map_x(player_t *p);
int error_cases(int ac, char **av);

#endif /* !MY_H_ */
