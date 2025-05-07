/*
** EPITECH PROJECT, 2024
** Basic Terminal Game
** File description:
** main.c
*/

#include "my.h"

void display_tower_tower(tower_t*tower)
{
    for (int i = 0; i != HEIGHT; i++){
        if (i < tower->opening_y - OPENING_LENGTH / 2
            || i > tower->opening_y + OPENING_LENGTH / 2 ){
            mvprintw(i , tower->position_x, "#");
            mvprintw(i , tower->position_x + 1, "#");
            mvprintw(i , tower->position_x + 2, "#");
            mvprintw(i , tower->position_x - 1, "#");
            mvprintw(i , tower->position_x - 2, "#");
        }
    }
}

void display_elements(bird_t *bird, tower_t *tower)
{
    int i;
    clear();

    for (int i = 0; i != HEIGHT; i++){
        mvprintw(i , WIDTH, "|");
    }
    for (int i = 0; i != WIDTH; i++){
        mvprintw(HEIGHT , i, "_");
        if (i == tower->position_x)
            display_tower_tower(tower);
    }
    mvprintw(bird->y, bird->x, "O");
}

tower_t *init_tower()
{
    tower_t *tower = malloc(sizeof(tower));

    if (!tower)
        exit(84);
    tower->position_x = WIDTH;
    tower->opening_y = rand() % HEIGHT;
    return tower;
}

bird_t *init_bird()
{
    bird_t *bird = malloc(sizeof(bird_t));

    if (!bird)
        exit(84);

    bird->alive = true;
    bird->y = HEIGHT / 2;
    bird->x = WIDTH / 2;

    return bird;
}


static void sleep_ms(int milliseconds)
{
    usleep(milliseconds * 1000);
}


void game_start(void)
{
    bird_t *bird = init_bird();
    tower_t *tower = init_tower();
    int c;

    initscr();
    timeout(WAIT);
    while (bird->alive) {
        c = getch();

        if (c == 'a' || c == 'A')
            bird->alive = false;
        else if (c == 'q')
            bird->x -= 2;
        else if (c == 'd')
            bird->x += 2;
        else if (c == 's')
            bird->y -= 2;
        else
            bird->y++;

        if (tower->position_x < 0 ){
            tower->position_x = WIDTH;
            tower->opening_y = rand() % HEIGHT;
        } else 
            tower->position_x--;

        if (bird->y < 0 || bird->y >= HEIGHT)
            bird->alive = false;

        display_elements(bird, tower);
    }
    endwin();

    free(bird);
}
