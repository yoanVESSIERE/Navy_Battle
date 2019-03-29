/*
** EPITECH PROJECT, 2019
** error boat
** File description:
** navy
*/

#include "../../include/main.h"

int all_on(int i, int j, char **map)
{
    if (map[i][3] == map[i][6]) {
        if (map[i][3] >= map[j][3] && map[i][3] <= map[j][6] \
        && map[j][2] >= map[i][2] && map[j][2] <= map[i][5])
            return (84);
    } else if (map[j][3] >= map[i][3] && map[j][3] <= map[i][6] \
    && map[i][2] >= map[j][2] && map[i][2] <= map[j][5]) {
        return (84);
    }
    return (0);
}

int second_letter(char **map, int j, int x)
{
    for (int m = map[j][3]; m <= map[j][6]; m++)
        if (x == m)
            return (84);
    return (0);
}

int second_digit(char **map, int j, int x)
{
    for (int m = map[j][2]; m <= map[j][5]; m++)
        if (x == m)
            return (84);
}

int same_letter(int i, int j, char **map)
{
    int stock1 = 0;
    int stock2 = 0;

    for (int x = map[i][3]; x <= map[i][6]; x++)
        if (second_letter(map, j, x) == 84)
            return (84);
    return (0);
}

int same_digit(int i, int j, char **map)
{
    for (int x = map[i][2]; x <= map[i][5]; x++)
        if (second_digit(map, j, x) == 84)
            return (84);
    return (0);
}