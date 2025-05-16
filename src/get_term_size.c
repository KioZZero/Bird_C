/*
** EPITECH PROJECT, 2024
** flappy_bird
** File description:
** get_term_size.c
*/

#include "my.h"

int get_size(int cas)
{
    struct winsize win;

    ioctl(0, TIOCGWINSZ, &win);
    switch (cas){
        case 1:
            return win.ws_col;
        case 2:
            return win.ws_row;
    }
    return 0;
}
