/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** read the terminal
*/

#include "../../include/main.h"

void read_term(char *buff)
{
    int check = 0;

    my_putstr("\nattack: ");
    check = read(0, buff, 100);
    buff[check] = '\0';
}