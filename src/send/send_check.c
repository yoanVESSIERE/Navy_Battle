/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** src check before send a signal
*/

#include "../../include/main.h"
#include "../../include/global.h"

int check_send(char *buff)
{
    int len = 0;

    for (len = 0; buff[len] != '\n'; len++);
    if (len != 2) {
        write(1, "wrong position\n", 15);
        return (84);
    }
    if ((buff[0] != 'A' && buff[0] != 'B' && buff[0] != 'C' && buff[0] != 'D' \
    && buff[0] != 'E' && buff[0] != 'F' && buff[0] != 'G' && buff[0] != 'H') \
    || (buff[1] != '1' && buff[1] != '2' && buff[1] != '3' && buff[1] != '4' \
    && buff[1] != '5' && buff[1] != '6' && buff[1] != '7' && buff[1] != '8')) {
        write(1, "wrong position\n", 15);
        return (84);
    }
    return (0);
}

void touch(int sig)
{
    if (sig == SIGUSR1)
        nb = 1;
    else if (sig == SIGUSR2)
        nb = 2;
}

void get_hit(int letter, int digit, char map[8][9])
{
    struct sigaction get;

    get.sa_handler = &touch;
    nb = 0;
    get.sa_flags = SA_SIGINFO;
    sigemptyset(&get.sa_mask);
    sigaction(SIGUSR1, &get, NULL);
    sigaction(SIGUSR2, &get, NULL);
    pause();
    if (nb == 1) {
        map[digit - 49][letter - 65] = 'x';
        write(1, &letter, 1);
        write(1, &digit, 1);
        my_putstr(": hit\n");
    } else if (nb == 2) {
        map[digit - 49][letter - 65] = 'o';
        write(1, &letter, 1);
        write(1, &digit, 1);
        my_putstr(": missed\n");
    }
}