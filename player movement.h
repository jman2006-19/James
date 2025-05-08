//
// Created by james on 04/05/2025.
//

#ifndef PLAYER_MOVEMENT_H
#define PLAYER_MOVEMENT_H
#define PLAYER_CHAR '@'
#define SCORE_LEVEL_1 10
#include "grid.h"
#include "fuel.h"
#include "oxegen.h"
int score = 0;
void movePlayer(char input) {
    int newX = player.x;
    int newY = player.y;
    switch (input) {
        case 'w':
            if (player.y > 0) newY--;
        break;
        case 's':
            if (player.y < GRID_HEIGHT - 1) newY++;
        break;
        case 'a':
            if (player.x > 0) newX--;
        break;
        case 'd':
            if (player.x < GRID_WIDTH - 1) newX++;
        break;
        default:
            break;
    }
    if (grid[newY][newX] == JUNK_CHAR) {
        score++;
        grid[newY][newX] = EMPTY_CHAR;
        random_Junk_spawning1();
    }
    if (grid[newY][newX] == FUEL_CHAR) {
        for (int i = 0; i <= MAX_FUEL; i++) {
            fuel = MAX_FUEL;
        }
        grid [newY][newX] = EMPTY_CHAR;
        fuel_spawn_min();
    }
    if (grid[newY][newX] == OXEGEN_CHAR) {
        for (int i = 0; i <= MAX_OXEGEN; i++) {
            oxegen = MAX_OXEGEN;
        }
        grid[newY][newX] = EMPTY_CHAR;
        oxegen_spawn_min();
    }
    player.x = newX;
    player.y = newY;
    fuel--;
    oxegen--;
}
void Score_bar_level1() {
    int Lenght_2 = 10;
    int filled_2 = (score*Lenght_2)/SCORE_LEVEL_1;
    printf("score = [");
    for (int i = 0; i < Lenght_2; i++) {
        if (i < filled_2) {
            printf("/");
        }else {
            printf(" ");
        }
    }
    printf("]%d/%d\n", score, SCORE_LEVEL_1);
}
#endif //PLAYER_MOVEMENT_H
