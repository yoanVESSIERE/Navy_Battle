/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** win or lose check function
*/

#include "../../include/main.h"
#include "../../include/global.h"

int check_lose_win(char map1[8][9], char map2[8][9])
{
    int boat_total = 0;
    int boat_p1 = 0;
    int boat_p2 = 0;

    for (int i = 0; i < 8; i++)
        for (int w = 0; w < 8; w++)
            if (map1[i][w] != '.' && map1[i][w] != 'o')
                boat_total += 1;
    for (int i = 0; i < 8; i++)
        for (int w = 0; w < 8; w++) {
            if (map1[i][w] == 'x')
                boat_p1 += 1;
            if (map2[i][w] == 'x')
                boat_p2 += 1;
        }
    if (boat_p1 == boat_total)
        return (1);
    if (boat_p2 == boat_total)
        return (2);
    return (0);
}

void enemy_won(int *ret, int *nb)
{
    my_putstr("\nEnemy won");
    *ret = 1;
    *nb = 100;
}

int check_end(char map1[8][9], int ac)
{
    int i = 0;
    int w = 0;
    int ret = 0;
    struct timespec slp;

    slp.tv_nsec = 500000;
    slp.tv_sec = 0;
    for (i = 0; i < 8; i++)
        for (w = 0; w < 8; w++) {
            if (ac == 3)
                nanosleep(&slp, NULL);
            if (nb == 100) {
                my_putstr("\nI won");
                ret = 1;
            }
            if (map1[i][w] == 'x' || map1[i][w] == '.' || map1[i][w] == 'o')
                enemy_won(&ret, &nb);
        }
    return (ret);
}