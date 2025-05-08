//
// Created by james on 04/05/2025.
//

#ifndef GRID_H
#define GRID_H
#define GRID_HEIGHT 18
#define GRID_WIDTH  18
#define EMPTY_CHAR  '.'
#define PLAYER_CHAR '@'
typedef struct {
    int x;
    int y;
} Position;

char grid[GRID_HEIGHT][GRID_WIDTH];
Position player;
Position asteroid;
Position raiders;
int asteroid_direction = 1;
int raiders_direction = 1;

void clearGrid() {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            grid[i][j] = EMPTY_CHAR;
        }
    }
}
void printGrid() {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            if (i == player.y && j == player.x)
                printf("%c ", PLAYER_CHAR);
            else
                printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}
#endif //GRID_H
