/*
** EPITECH PROJECT, 2024
** ###
** File description:
** main.c
*/

#include "my.h"

void display_board(char **board)
{
    int x = 10;
    int y = 20;

    for (int i = 0; i != x; i++){
        for (int j = 0; j != y; j++){
            printf("%c", board[i][j]);
        }
    printf("\n");
    }
}

char **init_board(void)
{
    int x = 10;
    int y = 20;
    char **board = malloc(sizeof(char *) * x);

    for (int i = 0; i < x; i++) {
        board[i] = malloc(sizeof(char) * y);
        for (int j = 0; j != y; j++){
            if (i == x / 2 - 1 && j == y / 2 - 1)
                board[i][j] = 'O';
            else
                board[i][j] = '.';
        }
    }
    return board;
}

void update_board(char ***board)
{
    int x = 10;
    int y = 20;
    int i = 0;

    for (int i = 0; i != x; i++){
        for (int j = 0; j != y; j++){
        }
    }
    return;
}

void game_start(void)
{
    char **board = init_board();
    bool running = true;

    while (running){
        display_board(board);
        update_board(&board);
        sleep(1);
        running = false;
    }

    for (int i = 0; i < 10; i++)
        free(board[i]);
    free(board);
}

