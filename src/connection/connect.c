/*
** EPITECH PROJECT, 2019
** connect.c
** File description:
** navy
*/

#include "../../include/main.h"
#include "../../include/global.h"

void sucess(int sig)
{
    (void)sig;
    my_putstr("enemy connected\n");
}

void connect(int ac, char *av[])
{
    struct sigaction sig;
    int e = 0;

    sig.sa_handler = &sucess;
    sig.sa_flags = SA_SIGINFO;
    sigemptyset(&sig.sa_mask);
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    my_putstr("my_pid:  ");
    my_put_nbr(getpid());
    if (ac == 3) {
        e = kill(my_getnbr(av[1]), SIGUSR1);
        if (e == 0)
            my_putstr("\nsuccessfully connected\n");
    } else if (ac == 2) {
        my_putstr("\nwaiting for enemy connection...\n\n");
        pause();
    }
}

void ping(int sig, siginfo_t *siginf, void *ucontext)
{
    (void)sig;
    (void)ucontext;

    nb = siginf->si_pid;
}

int other_pid(void)
{
    int pid = 0;
    struct sigaction sig;

    sig.sa_sigaction = &ping;
    sig.sa_flags = SA_SIGINFO;
    sigemptyset(&sig.sa_mask);
    sigaction(SIGUSR1, &sig, NULL);
    pause();
    pid = nb;
    return (pid);
}