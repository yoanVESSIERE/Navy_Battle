/*
** EPITECH PROJECT, 2019
** navy
** File description:
** error handling file
*/

#include "../../include/main.h"

int error_happens(int ac, char **av)
{
    if (ac == 2)
        if (error_handling(av[1]) == 84)
            return (84);
    if (ac == 3)
        if (error_handling(av[2]) == 84)
            return (184);
    return (0);
}

int all_boat(char *coord)
{
    int boat[4] = {0};

    for (int i = 0; coord[i] != '\0'; i++) {
        if ((i == 0 && coord[i] == '2') || \
        (i != 0 && coord[i - 1] == '\n' && coord[i] == '2'))
            boat[0] += 1;
        if ((i == 0 && coord[i] == '3') || \
        (i != 0 && coord[i - 1] == '\n' && coord[i] == '3'))
            boat[1] += 1;
        if ((i == 0 && coord[i] == '4') || \
        (i != 0 && coord[i - 1] == '\n' && coord[i] == '4'))
            boat[2] += 1;
        if ((i == 0 && coord[i] == '5') || \
        (i != 0 && coord[i - 1] == '\n' && coord[i] == '5'))
            boat[3] += 1;
    }
    for (int i = 0; i < 4; i++)
        if (boat[i] != 1)
            return (84);
    return (0);
}

int good_coord(char *coord)
{
    char **map = str_word_array(coord);

    for (int i = 0; i < 4; i++) {
        if (map[i][1] != ':' || map[i][4] != ':')
            return (84);
        if ((map[i][2] < 'A' || map[i][2] > 'H') || \
        (map[i][5] < 'A' || map[i][5] > 'H'))
            return (84);
        if ((map[i][3] < '1' || map[i][3] > '8') || \
        (map[i][6] < '1' || map[i][6] > '8'))
            return (84);
    }
    return (0);
}

int diagonal_boat(char *coord)
{
    char **map = str_word_array(coord);

    for (int i = 0; i < 4; i++) {
        if ((map[i][2] != map[i][5] && map[i][3] != map[i][6]) || \
        (map[i][2] == map[i][5] && map[i][3] == map[i][6]))
            return (84);
        if (size_number(map, i) == 84)
            return (84);
        if (size_letter(map, i) == 84)
            return (84);
    }
    return (0);
}

int error_handling(char *file)
{
    int fd = open(file, O_RDONLY);
    char coord[99];

    if (fd == -1)
        return (84);
    read(fd, coord, 99);
    coord[31] = '\0';
    if (all_boat(coord) == 84 || good_coord(coord) == 84)
        return (84);
    if (diagonal_boat(coord) == 84 || boat_on_boat(coord) == 84)
        return (84);
    return (0);
}