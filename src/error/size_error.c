/*
** EPITECH PROJECT, 2019
** size error handling
** File description:
** navy
*/

#include "../../include/main.h"

int on_on(int i, int j, char **map)
{
    int error = 0;

    if (i != j && map[i][2] == map[i][5] && map[j][2] == map[j][5] \
    && map[i][2] == map[j][2])
        error = same_letter(i, j, map);
    if (error == 84)
        return (84);
    if (i != j && map[i][3] == map[i][6] && map[j][3] == map[j][6] \
    && map[i][3] == map[j][3])
        error = same_digit(i, j, map);
    if (error == 84)
        return (84);
    if (i != j && all_on(i, j, map) == 84)
        return (84);
    return (0);
}

int ret_on(int i, char **map)
{
    for (int j = 0; j < 4; j++)
        if (on_on(i , j, map) == 84)
            return (84);
    return (0);
}

int boat_on_boat(char *coord)
{
    char **map = str_word_array(coord);

    for (int i = 0; i < 4; i++)
        ret_on(i, map);
    return (0);
}

int size_number(char **map, int i)
{
    int check = 0;

    if (map[i][2] == map[i][5]) {
        if (map[i][3] > map[i][6])
            check = map[i][3] - map[i][6];
        else
            check = map[i][6] - map[i][3];
        if (check + 1 != map[i][0] - '0')
            return (84);
    }
    return (0);
}

int size_letter(char **map, int i)
{
    int check = 0;

    if (map[i][3] == map[i][6]) {
        if (map[i][2] > map[i][5])
            check = map[i][2] - map[i][5];
        else
            check = map[i][5] - map[i][2];
        if (check + 1 != map[i][0] - '0')
            return (84);
    }
    return (0);
}