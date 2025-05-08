//
// Created by james on 04/05/2025.
//

#ifndef FUEL_H
#define FUEL_H
#include <time.h>
#include "grid.h"
#include "oxegen.h"
#define JUNK_CHAR '*'
#define OXEGEN_CHAR 'O'
#define FUEL_CHAR 'F'
#define MIN_FUEL_SPAWN 1
#define MAX_FUEL_SPAWN 10
#define MAX_FUEL 20
int fuel = 20;
void fuel_spawn() {
    int x3,y3;
    int attempts = 0;
    srand(time(NULL));
    for (int i = 0; i <= MAX_FUEL_SPAWN; i++) {
        do {
            x3 = rand()%(GRID_WIDTH-2)+1;
            y3 = rand()%(GRID_HEIGHT-2)+1;
            attempts++;
            if (attempts > 1000) {return;}
        }while (
            grid[y3][x3] != EMPTY_CHAR ||
            (x3 == player.x && y3 == player.y) ||
            (grid[y3][x3] == JUNK_CHAR) ||
            (grid[y3][x3] == OXEGEN_CHAR)
            );
        grid[y3][x3] = FUEL_CHAR;
    }
}
void Fuel_bar() {
    int Lenght_B = 20;
    int filled = (fuel*Lenght_B)/MAX_FUEL;
    printf("fuel = [");
    for (int i = 0; i < Lenght_B; i++) {
        if (i < filled) {
            printf("/");
        }else {
            printf(" ");
        }
    }
    printf("]%d/%d\n", fuel, MAX_FUEL);
}
void fuel_spawn_min() {
    int x5,y5;
    int attempts = 0;
    srand(time(NULL));
    for (int i = 0; i <= MIN_FUEL_SPAWN; i++) {
        do {
            x5 = rand()%(GRID_WIDTH-2)+1;
            y5 = rand()%(GRID_HEIGHT-2)+1;
            attempts++;
            if (attempts > 1000) {return;}
        }while (
            grid[y5][x5] != EMPTY_CHAR ||
            (x5 == player.x && y5 == player.y) ||
            (grid[y5][x5] == JUNK_CHAR) ||
            (grid[y5][x5] == OXEGEN_CHAR)
            );
        grid[y5][x5] = FUEL_CHAR;
    }
}
#endif //FUEL_H
