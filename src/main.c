/*
** EPITECH PROJECT, 2024
** ###
** File description:
** main.c
*/

#include "my.h"

int main(int ac, char **av)
{
    if (ac != 1)
        exit(84);
    game_start();
    exit(0);
}
