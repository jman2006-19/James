//
// Created by james on 04/05/2025.
//

#ifndef OXEGEN_H
#define OXEGEN_H
#include <time.h>
#define FUEL_CHAR 'F'
#include "fuel.h"
#include "grid.h"
#define OXEGEN_CHAR 'O'
#define MIN_OXEGEN_SPAWNED 3
#define MAX_OXEGEN_SPAWNED 15
#define MAX_OXEGEN 30
int oxegen = 30;
void oxegen_spawn() {
    int x4,y4;
    int attempts1 = 0;
    srand(time(NULL));
    for (int i = 0; i <= MAX_OXEGEN_SPAWNED; i++) {
        do {
            x4 = rand()%(GRID_WIDTH-2)+1;
            y4 = rand()%(GRID_HEIGHT-2)+1;
            attempts1++;
            if (attempts1 > 1000) {return;}
        }while (
            grid[y4][x4] != EMPTY_CHAR ||
            (x4 == player.x && y4 == player.y) ||
            (grid[y4][x4] == JUNK_CHAR) ||
            (grid[y4][x4] == FUEL_CHAR)
            );
        grid[y4][x4] = OXEGEN_CHAR;
    }
}
void oxegen_bar() {
    int Lenght_O = 30;
    int filled_1 = (oxegen*Lenght_O)/MAX_OXEGEN;
    printf("oxegen = [");
    for (int i = 0; i < Lenght_O; i++) {
        if (i < filled_1) {
            printf("/");
        }else {
            printf(" ");
        }
    }
    printf("]%d/%d\n", oxegen, MAX_OXEGEN);
}
void oxegen_spawn_min() {
    int x6,y6;
    int attempts1 = 0;
    srand(time(NULL));
    for (int i = 0; i <= MIN_OXEGEN_SPAWNED; i++) {
        do {
            x6 = rand()%(GRID_WIDTH-2)+1;
            y6 = rand()%(GRID_HEIGHT-2)+1;
            attempts1++;
            if (attempts1 > 1000) {return;}
        }while (
            grid[y6][x6] != EMPTY_CHAR ||
            (x6 == player.x && y6 == player.y) ||
            (grid[y6][x6] == JUNK_CHAR) ||
            (grid[y6][x6] == FUEL_CHAR)
            );
        grid[y6][x6] = OXEGEN_CHAR;
    }
}
#endif //OXEGEN_H
