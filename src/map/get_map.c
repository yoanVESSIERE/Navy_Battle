/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** Map file src
*/

#include "../../include/main.h"

void init_map(char map[8][9])
{
    for (int i = 0; i < 8; i++) {
        map[i][8] = '\0';
        for (int w = 0; w < 8; w++)
            map[i][w] = '.';
    }
}

void put_in_map(char map[8][9], int index, char *buff, char boat)
{
    int begin[2] = {buff[index + 1] - '1', buff[index] - 'A'};
    int end[2] = {buff[index + 4] - '1', buff[index + 3] - 'A'};

    if (begin[0] == end[0]) {
        for (int i = begin[1]; i <= end[1]; i++)
            map[begin[0]][i] = boat;
    } else {
        for (int i = begin[0]; i <= end[0]; i++)
            map[i][begin[1]] = boat;
    }
}

int read_translate_map(char *path, char map[8][9])
{
    int fd = open(path, O_RDONLY);
    char buff[100];
    int bytes_read;
    char to_put = 0;

    if (fd == -1 || (bytes_read = read(fd, buff, 100)) == -1)
        return (84);
    buff[bytes_read] = '\0';
    for (int i = 0; buff[i] != '\0'; i++)
        if (buff[i - 1] == '\n' || i == 0) {
            to_put = buff[i];
            put_in_map(map, i + 2, buff, to_put);
        }
    return (0);
}

void print_grid(char map[8][9])
{
    write(1, "-+---------------\n", 18);
    for (int i = 0, j = i + 49; i < 8; i++, j++) {
        write(1, &j, 1);
        write(1, "|", 1);
        write(1, &map[i][0], 1);
        for (int w = 1; w < 8; w++) {
            write(1, " ", 1);
            write(1, &map[i][w], 1);
        }
        write(1, "\n", 1);
    }
}

void print_maps(char map1[8][9], char map2[8][9])
{
    write(1, "\nmy positions:\n |A B C D E F G H\n", 33);
    print_grid(map1);
    write(1, "\nenemy's positions:\n |A B C D E F G H\n", 38);
    print_grid(map2);
}