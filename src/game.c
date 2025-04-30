/*
** EPITECH PROJECT, 2024
** Basic Terminal Game
** File description:
** main.c
*/

#include "my.h"

bird_t *init_bird()
{
    bird_t *bird = malloc(sizeof(bird_t));
    if (!bird)
        return NULL;

    bird->alive = true;
    bird->y = HEIGHT / 2;

    return bird;
}

void game_start(void)
{
    bird_t *bird = init_bird();
    int c;

    initscr();
    timeout(500);
    while (bird->alive) {
        c = getch();

        if (c == 'q' || c == 'Q') {
            bird->alive = false;
        } else if (c == ' ') {
            bird->y -= 2;
        } else {
            bird->y++;
        }

        if (bird->y < 0 || bird->y >= HEIGHT)
            bird->alive = false;
    }
    endwin();

    free(bird);
}

// static void sleep_ms(int milliseconds)
// {
//     usleep(milliseconds * 1000);
// }
