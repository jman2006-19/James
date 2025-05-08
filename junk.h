//
// Created by james on 04/05/2025.
//

#ifndef JUNK_H
#define JUNK_H
#define JUNK_CHAR   '*'
#include "grid.h"
#define JUNK_Number 10
#define JUNK_Number_SPAWN 3
#include <time.h>

void placeJunk() {
    srand(time(NULL));
    for (int i = 0; i < JUNK_Number; i++) {
        for (int j = 0; j < JUNK_Number; j++)
            do{
                int junkX = rand() % (GRID_WIDTH - 2) + 1;
                int junkY = rand() % (GRID_HEIGHT - 2) + 1;
                grid[junkY][junkX] = JUNK_CHAR;
            }while(JUNK_Number < 6);
    }
}
void random_Junk_spawning1() {// this is for when and asteroid destroys junk, so I decided to spawn more if two low
    srand(time(NULL));
    for (int i = 0; i < JUNK_Number_SPAWN; i++) {
        for (int j = 0; j < JUNK_Number_SPAWN; j++)
            do {
                int junkX1 = rand() % (GRID_WIDTH - 2) + 1;
                int junkY1 = rand() % (GRID_HEIGHT - 2) + 1;
                grid[junkY1][junkX1] = JUNK_CHAR;
            }while (JUNK_Number >= 12);
    }
}
#endif //JUNK_H
