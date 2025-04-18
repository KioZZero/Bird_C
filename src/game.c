/*
** EPITECH PROJECT, 2024
** ###
** File description:
** main.c
*/

#include "my.h"
#define WIDTH 100
#define HEIGHT 20


void display_board(char **board)
{
    int x = HEIGHT;
    int y = WIDTH;

    for (int i = 0; i != x; i++){
        for (int j = 0; j != y; j++){
            printf("%c", board[i][j]);
        }
    printf("|\n");
    }
}

char **init_board(int h)
{
    int x = HEIGHT;
    int y = WIDTH;
    char **board = malloc(sizeof(char *) * x);

    for (int i = 0; i < x; i++) {
        board[i] = malloc(sizeof(char) * y);
        for (int j = 0; j != y; j++){
            if (i == h && j == y / 2 - 1)
                board[i][j] = 'O';
            else
                board[i][j] = ' ';
        }
    }
    return board;
}

char **update_board(char **board, int h)
{
    int x = HEIGHT;
    int y = WIDTH;

    for (int i = 0; i != x; i++){
        for (int j = 0; j != y; j++){
            if (i == h && j == y / 2 - 1)
                board[i][j] = 'O';
            else
            board[i][j] = ' ';
        }
    }
    return board;
}

brid_t *init_bird()
{
    brid_t *bird = malloc(sizeof(bird));

    bird->alive = true;
    bird->y = HEIGHT / 2;

    return bird;
}

static void sleep_ms(int milliseconds)
{
    usleep(milliseconds * 1000);
}

void game_start(void)
{
    brid_t *bird = init_bird();
    char **board = init_board(bird->y);
    bool running = true;

    while (bird->alive){
        if ( _kbhit()){
            bird->y--;
            ch = '0';
        } else { 
            bird->y++;
        }
        if (bird->y == HEIGHT)
            bird->alive = false;
        printf("%d\n",bird->y);
        board = update_board(board, bird->y);
        system("clear");
        display_board(board);
        sleep_ms(500);
    }

    for (int i = 0; i < 10; i++)
        free(board[i]);
    free(board);
}

