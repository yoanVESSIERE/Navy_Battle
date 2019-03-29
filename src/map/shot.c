/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** src Shot check on map
*/

#include "../../include/main.h"

void missed(int letter, int digit)
{
    write(1, &letter, 1);
    write(1, &digit, 1);
    my_putstr(":  missed\n");
}

void touched(int letter, int digit)
{
    write(1, &letter, 1);
    write(1, &digit, 1);
    my_putstr(":  hit\n");
}

void hit_or_not(int *response, char map[8][9], int pid)
{
    struct sigaction sig;
    struct timespec slp = {0, 100000};

    sig.sa_handler = &touch;
    sig.sa_flags = SA_SIGINFO;
    sigemptyset(&sig.sa_mask);
    nanosleep(&slp, NULL);
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    if (map[response[0]][response[1]] == '.') {
        map[response[0]][response[1]] = 'o';
        kill(pid, SIGUSR2);
        missed(response[1] + 65, response[0] + 49);
    } else {
        map[response[0]][response[1]] = 'x';
        kill(pid, SIGUSR1);
        touched(response[1] + 65, response[0] + 49);
    }
}