/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday06-leonard.leroy
** File description:
** my.h
*/


#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <ncurses.h>
    #include <sys/ioctl.h>
    #include <time.h>
int get_size(int cas);
    #define WIDTH get_size(1)
    #define HEIGHT get_size(2)
    #define OPENING_LENGTH 7
    #define WAIT 200
typedef struct tower_s {
    int position_x;
    int opening_y;
} tower_t;
typedef struct bird_s {
    bool alive;
    int x;
    int y;
} bird_t;
void game_start(void);
#endif /* !MY_H_ */
