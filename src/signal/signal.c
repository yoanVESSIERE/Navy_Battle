/*
** EPITECH PROJECT, 2019
** signal.c
** File description:
** navy
*/

#include "../../include/main.h"
#include "../../include/global.h"

void usone(int sig)
{
    if (sig == SIGUSR1)
        nb += 1;
    else if (sig == SIGUSR2)
        nb = 0;
}

void reponse_bis(int *index, int *tab)
{
    nb = 1;
    while (nb != 0) {
        index[0] = nb;
        pause();
        if (nb == 0 && index[1] == 0) {
            tab[1] = index[0] - 2;
            index[1] = 1;
            nb = 1;
            index[0] = 0;
        }
    }
    tab[0] = index[0] - 2;
}

void reponse(int *tab)
{
    struct sigaction sig;
    int index[2] = {0, 0};

    sig.sa_handler = &usone;
    sig.sa_flags = SA_SIGINFO;
    sigemptyset(&sig.sa_mask);
    my_putstr("\nwaiting for enemy's attack...\n");
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    pause();
    reponse_bis(index, tab);
}

void send(int *tab, int pid, struct timespec slp, struct sigaction sig)
{
    sigaction(SIGUSR1, &sig, NULL);
    kill(pid, SIGUSR2);
    nanosleep(&slp, NULL);
    for (tab[0] = 0; tab[0] != tab[1]; tab[0]++) {
        nanosleep(&slp, NULL);
        kill(pid, SIGUSR1);
    }
    nanosleep(&slp, NULL);
    kill(pid, SIGUSR2);
    nanosleep(&slp, NULL);
    for (tab[0] = 0; tab[0] != tab[2]; tab[0]++) {
        nanosleep(&slp, NULL);
        kill(pid, SIGUSR1);
    }
    nanosleep(&slp, NULL);
    kill(pid, SIGUSR2);
    nanosleep(&slp, NULL);
}

void attack(char letter, char digits, int pid)
{
    int tab[3] = {0, letter - 64, digits - 48};
    struct sigaction us1;
    struct timespec slp;

    slp.tv_nsec = 50000;
    slp.tv_sec = 0;
    us1.sa_handler = &usone;
    us1.sa_flags = SA_SIGINFO;
    sigemptyset(&us1.sa_mask);
    sigaction(SIGUSR1, &us1, NULL);
    sigaction(SIGUSR2, &us1, NULL);
    nanosleep(&slp, NULL);
    send(tab, pid, slp, us1);
}