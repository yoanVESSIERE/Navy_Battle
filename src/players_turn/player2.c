/*
** EPITECH PROJECT, 2019
** player2
** File description:
** navy
*/

#include "../../include/main.h"
//#include "../../include/global.h"

void init_p2(char **av, char my_map[8][9], char his_map[8][9], \
struct timespec *slp)
{
    read_translate_map(av[2], my_map);
    print_maps(my_map, his_map);
    nanosleep(slp, NULL);
    kill(my_getnbr(av[1]), SIGUSR1);
}

void get_attack_p2(int *tab, struct timespec *slp, char **av, char my_map[8][9])
{
    reponse(tab);
    nanosleep(slp, NULL);
    hit_or_not(tab, my_map, my_getnbr(av[1]));
}

void send_attack_p2(char *buff, struct timespec *slp, char **av, \
char his_map[8][9])
{
    read_attack(buff);
    nanosleep(slp, NULL);
    nanosleep(slp, NULL);
    attack(buff[0], buff[1], my_getnbr(av[1]));
    get_hit(buff[0], buff[1], his_map);
}

void print_and_wait(char my_map[8][9], char his_map[8][9], struct timespec *slp)
{
    print_maps(my_map, his_map);
    nanosleep(slp, NULL);
    nanosleep(slp, NULL);
}

int turn_p2(char **av, char my_map[8][9], char his_map[8][9], \
struct timespec *slp)
{
    char buff[99];
    int tab[3] = {0, 0, 0};

    init_p2(av, my_map, his_map, slp);
    while (check_lose_win(my_map, his_map) == 0) {
        if (tab[2] == 0)
            tab[2] = 1;
        get_attack_p2(tab, slp, av, my_map);
        if (check_lose_win(my_map, his_map) != 0)
            return (check_lose_win(my_map, his_map));
        send_attack_p2(buff, slp, av, his_map);
        print_and_wait(my_map, his_map, slp);
        if (tab[2] == 2) {
            nanosleep(slp, NULL);
            tab[2] = 0;
        } else if (tab[2] == 1)
            tab[2]++;
    }
    return (check_lose_win(my_map, his_map));
}