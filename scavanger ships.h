//
// Created by james on 04/05/2025.
//

#ifndef SCAVANGER_SHIPS_H
#define SCAVANGER_SHIPS_H
#define SCAVENGER_CHAR 'S'
#define scavenger_spawned 2
#include <stdlib.h>
#include <time.h>
#include "grid.h"
#include "fuel.h"
#include "oxegen.h"
#define EMPTY_CHAR  '.'
#define PLAYER_CHAR '@'
#include "player movement.h"
typedef struct {
    Position pos;
    int direction;
    char axis;
}Scavenger;
Scavenger raider[scavenger_spawned];
void scavenger_SPAWN() {
    for (int i = 0; i < scavenger_spawned; i++) {
        int edge = rand() % 4;
        raider[i].direction = (rand() % 2) ? 1 : -1;
        raider[i].axis = (rand() % 2) ? 'h' : 'v';

        if (edge == 0) {
            raider[i].pos.y = 1;
            raider[i].pos.x = rand() % GRID_WIDTH;
        } else if (edge == 1) {
            raider[i].pos.y = GRID_HEIGHT - 2;
            raider[i].pos.x = rand() % GRID_WIDTH;
        } else if (edge == 2) {
            raider[i].pos.x = 1;
            raider[i].pos.y = rand() % GRID_HEIGHT;
        } else { // right edge
            raider[i].pos.x = GRID_WIDTH - 2;
            raider[i].pos.y = rand() % GRID_HEIGHT;
        }
        grid[raider[i].pos.y][raider[i].pos.x] = SCAVENGER_CHAR;
    }
}
void move_Scavanger() {
    for (int i = 0; i < scavenger_spawned; i++) {
        grid[raider[i].pos.y][raider[i].pos.x] = EMPTY_CHAR;
        if (raider[i].axis == 'h') {
            raider[i].pos.x += raider[i].direction;
            if (raider[i].pos.x <= 1 || raider[i].pos.x >= GRID_WIDTH - 2) {
                raider[i].direction *= -1;
                raider[i].pos.x += raider[i].direction;
            }
        } else {
            raider[i].pos.y += raider[i].direction;
            if (raider[i].pos.y <= 1 || raider[i].pos.y >= GRID_HEIGHT - 2) {
                raider[i].direction *= -1;
                raider[i].pos.y += raider[i].direction;
            }
        }
        grid[raider[i].pos.y][raider[i].pos.x] = SCAVENGER_CHAR;
        if (raider[i].pos.x == player.x && raider[i].pos.y == player.y) {
            printf("Scavenger collided with you! Junk and fuel lost!\n");
            fuel -= 10;
            if (fuel < 0) {
                fuel = 0;
            }
            oxegen -= 10;
            if (oxegen < 0) {
                oxegen = 0;
            }
            score -= 10;
            if (score < 0) {
                score = 0;
            }
            return;
        }
    }
}
#endif //SCAVANGER_SHIPS_H
