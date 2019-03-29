/*
** EPITECH PROJECT, 2019
** player1
** File description:
** navy
*/

#include "../../include/main.h"
//#include "../../include/global.h"

void init_p1(char **av, char my_map[8][9], int *pid, char his_map[8][9])
{
    read_translate_map(av[1], my_map);
    *pid = other_pid();
    print_maps(my_map, his_map);
}

void read_attack(char *buff)
{
    int i = 84;

    while (i == 84) {
        read_term(buff);
        i = check_send(buff);
    }
}

void send_attack_p1(char *buff, struct timespec *slp, int pid, \
char his_map[8][9])
{
    read_attack(buff);
    nanosleep(slp, NULL);
    attack(buff[0], buff[1], pid);
    get_hit(buff[0], buff[1], his_map);
}

void get_attack_p1(int *tab, char my_map[8][9], char his_map[8][9], \
struct timespec *slp)
{
    reponse(tab);
    nanosleep(slp, NULL);
    hit_or_not(tab, my_map, tab[2]);
    print_maps(my_map, his_map);
}

int turn_p1(char maps[2][8][9], struct timespec *slp, char **av)
{
    int tab[4] = {0, 0, 0, 0};
    char buff[99];

    init_p1(av, maps[0], &tab[2], maps[1]);
    while (check_lose_win(maps[0], maps[1]) == 0) {
        if (tab[3] == 0)
            tab[3] = 1;
        send_attack_p1(buff, slp, tab[2], maps[1]);
        if (check_lose_win(maps[0], maps[1]) != 0)
            return (check_lose_win(maps[0], maps[1]));
        get_attack_p1(tab, maps[0], maps[1], slp);
        if (tab[3] == 2) {
            nanosleep(slp, NULL);
            tab[3] = 0;
        } else if (tab[3] == 1)
            tab[3]++;
    }
    return (check_lose_win(maps[0], maps[1]));
}