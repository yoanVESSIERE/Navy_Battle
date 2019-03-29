/*
** EPITECH PROJECT, 2019
** my_get_nbr.c
** File description:
** navy
*/

#include "../../include/main.h"

void set_nbr(char const *str, int j, double *res)
{
    int i;
    int x = 1;
    int count_num = 0;

    for (i = j; str[i] >= '0' && str[i] <= '9'; i++)
        count_num += 1;
    i -= 1;
    for (; str[i] >= '0' && str[i] <= '9'; i--) {
        if (*res + (str[i] - 48) * x < 2147483647) {
            *res += (str[i] - 48) * x;
            x *= 10;
        } else {
            *res = 0;
            break;
        }
        if (i == 0)
            break;
    }
}

int is_neg_or_pos(char const *str, double *res)
{
    int mult = 1;
    int count_neg = 0;
    int j;

    for (j = 0; str[j] == '+' || str[j] == '-'; j++)
        if (str[j] == '-')
            count_neg += 1;
    if ((count_neg % 2) != 0) {
        mult = -1;
        set_nbr(str, j, res);
        return (mult);
    }
    set_nbr(str, j, res);
    return (mult);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int result;
    double set_nb = 0;
    double *res = &set_nb;
    int mult = 1;

    if (str[i] == '+' || str[i] == '-')
        mult = is_neg_or_pos(str, res);
    if (str[i] >= '0' && str[i] <= '9')
        set_nbr(str, 0, res);
    *res *= mult;
    result = *res;
    return (result);
}