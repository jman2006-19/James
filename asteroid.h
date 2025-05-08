//
// Created by james on 04/05/2025.
//

#ifndef ASTEROID_H
#define ASTEROID_H
#include "grid.h"
#include "oxegen.h"
#define ASTEROID_CHAR 'A'
#define ASTEROID_NUM 10
typedef struct {
    Position pos;
    int direction;
    char axis;
}Asteroid;
Asteroid asteroids[ASTEROID_NUM];
void generate_Asteroids() {
    for (int i = 0; i < ASTEROID_NUM; i++) {
        int edge = rand() % 4;
        asteroids[i].direction = (rand() % 2) ? 1 : -1;
        asteroids[i].axis = (rand() % 2) ? 'h' : 'v';

        if (edge == 0) {
            asteroids[i].pos.y = 0;
            asteroids[i].pos.x = rand() % GRID_WIDTH;
        } else if (edge == 1) {
            asteroids[i].pos.y = GRID_HEIGHT - 1;
            asteroids[i].pos.x = rand() % GRID_WIDTH;
        } else if (edge == 2) {
            asteroids[i].pos.x = 0;
            asteroids[i].pos.y = rand() % GRID_HEIGHT;
        } else { // right edge
            asteroids[i].pos.x = GRID_WIDTH - 1;
            asteroids[i].pos.y = rand() % GRID_HEIGHT;
        }
        grid[asteroids[i].pos.y][asteroids[i].pos.x] = ASTEROID_CHAR;
    }
}
void moveAsteroid() {//how asteriod moves
    for (int i = 0; i < ASTEROID_NUM; i++) {
        grid[asteroids[i].pos.y][asteroids[i].pos.x] = EMPTY_CHAR;
        if (asteroids[i].axis == 'h') {
            asteroids[i].pos.x += asteroids[i].direction;
            if (asteroids[i].pos.x <= 0 || asteroids[i].pos.x >= GRID_WIDTH - 1) {
                asteroids[i].direction *= -1;
                asteroids[i].pos.x += asteroids[i].direction;
            }
        } else {
            asteroids[i].pos.y += asteroids[i].direction;
            if (asteroids[i].pos.y <= 0 || asteroids[i].pos.y >= GRID_HEIGHT - 1) {
                asteroids[i].direction *= -1;
                asteroids[i].pos.y += asteroids[i].direction;
            }
        }

        grid[asteroids[i].pos.y][asteroids[i].pos.x] = ASTEROID_CHAR;
    }
}
int check_Collision() {
    for (int i = 0; i < ASTEROID_NUM; i++) {
        if (player.x == asteroids[i].pos.x && player.y == asteroids[i].pos.y) {
            return 1;
        }
    }
    return 0;
}
#endif //ASTEROID_H
