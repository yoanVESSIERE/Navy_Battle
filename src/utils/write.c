/*
** EPITECH PROJECT, 2019
** write.c
** File description:
** navy
*/

#include "../../include/main.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (0);
}

int my_put_nbr(int nbr)
{
    if (nbr > 9) {
        my_put_nbr(nbr / 10);
    }
    if (nbr < 0 && (nbr * -1) > 9) {
        my_putchar(45);
        nbr = nbr * -1;
        my_put_nbr(nbr / 10);
    }
    else if (nbr < 0) {
        my_putchar(45);
        nbr = nbr * -1;
    }
    my_putchar(nbr % 10 + '0');
    return (0);
}