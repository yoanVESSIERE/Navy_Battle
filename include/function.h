/*
** EPITECH PROJECT, 2019
** function.h
** File description:
** navy
*/

#ifndef __INCLUSION__
#define __INCLUSION__

#include "main.h"

void connect(int, char **);
int my_put_nbr(int);
int my_putstr(char const *);
int my_getnbr(char const *);
char **str_word_array(char *);

void attack(char, char, int);
void reponse_bis(int *, int *);
void reponse(int *);
void ustwo(int);
int other_pid(void);

void init_map(char [8][9]);
int read_translate_map(char *, char [8][9]);
void print_maps(char [8][9], char [8][9]);
void hit_or_not(int *, char [8][9], int);
int check_lose_win(char [8][9], char [8][9]);
int check_end(char [8][9], int);

int check_send(char *);
void get_hit(int, int, char [8][9]);
void touch(int);

void read_attack(char *);
void read_term(char *);

void init_p1(char **, char [8][9], int *, char [8][9]);
void init_p2(char **, char [8][9], char [8][9], struct timespec *);

int turn_p1(char [2][8][9], struct timespec *, char **);
int turn_p2(char **, char [8][9], char [8][9], struct timespec *);

int error_happens(int, char **);
int error_handling(char *);
int boat_on_boat(char *);
int size_number(char **, int);
int size_letter(char **, int);
int same_letter(int, int, char **);
int same_digit(int, int, char **);
int all_on(int, int, char **);

#endif