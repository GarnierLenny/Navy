/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-navy-Lenny.garnier
** File description:
** error_cases
*/

#include "my.h"


int error_cases(int ac, char **av)
{
    av = av;
    if (ac < 2 || ac > 3) {
        return 84;
    }
    return 0;
}