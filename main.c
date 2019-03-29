/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** main.c
*/

#include "include/main.h"

void hand(int sig)
{
    (void)sig;
}

void prepare_game(int ac, char **av, char my_map[8][9], char his_map[8][9])
{
    struct sigaction sig;

    sig.sa_handler = &hand;
    sig.sa_flags = SA_SIGINFO;
    sigemptyset(&sig.sa_mask);
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    connect(ac, av);
    init_map(my_map);
    init_map(his_map);
}

int main(int ac, char **av)
{
    int ret = 0;
    struct timespec slp = {0, 500};
    char maps[2][8][9];

    if (error_happens(ac, av) == 84)
        return (84);
    prepare_game(ac, av, maps[0], maps[1]);
    if (ac == 3)
        ret = turn_p2(av, maps[0], maps[1], &slp);
    else if (ac == 2)
        ret = turn_p1(maps, &slp, av);
    print_maps(maps[0], maps[1]);
    if (ret == 1) {
        my_putstr("\nEnemy won\n");
        return (1);
    } else if (ret == 2) {
        my_putstr("\nI won\n");
        return (0);
    }
    return (0);
}