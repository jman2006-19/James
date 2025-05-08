#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "asteroid.h"
#include "grid.h"
#include "junk.h"
#include "player movement.h"
#include "fuel.h"
#include "oxegen.h"
#include "scavanger ships.h"
#define GRID_HEIGHT 18
#define GRID_WIDTH  18
#define Win_score_1 10

int main() {
    printf("You are not a Human anymore only a tool to be used by the empire yo fought against.\n");
    printf("You are prisoner of war, not a hero exploring space but a slave sent to mine junk in a nearby asteroid field.\n");
    printf("collect enough junk and you will go free, you will collect resources for your self.\n");
    printf("Now get out there and collect junk, good luck:\n");

    srand(time(NULL));
    player.x = GRID_WIDTH / 2;
    player.y = GRID_HEIGHT / 2;

    clearGrid();
    placeJunk();
    generate_Asteroids();
    grid[asteroid.y][asteroid.x] = ASTEROID_CHAR;
    fuel_spawn();
    oxegen_spawn();
    scavenger_SPAWN();

    char input;
    while (1) {
        printGrid();

        printf("Move with W A S D: ");
        scanf(" %c", &input);

        movePlayer(input);
        moveAsteroid();
        random_Junk_spawning1();
        Fuel_bar();
        oxegen_bar();
        Score_bar_level1();
        move_Scavanger();
        // You can add game over checks or resource updates her
        if (check_Collision()) {
            printGrid();
            printf("You collided with the asteroid GAME OVER.\n");
            printf("Well done you collected %d pieces of space junk, now get back to work.\n", score);
            break;
        }if (fuel <= 0) {
            printGrid();
            printf("\n you ran out of fuel, still useless in the end! Game over");
        }if (fuel <= MAX_FUEL/2) {
            printGrid();
            printf("fuel down to half\n");
            Fuel_bar();Score_bar_level1();oxegen_bar();
            if (fuel <= MAX_FUEL/4) {
                printf("Warning fuel is low if you die the empires will not aid you \n");
                Fuel_bar();Score_bar_level1();oxegen_bar();
            }
        }if (oxegen <= (MAX_OXEGEN/2)) {
            printGrid();
            printf("oxegen down to half\n");
            oxegen_bar();Score_bar_level1();Fuel_bar();
            if (fuel <= (MAX_OXEGEN/2)) {
                printf("Warning oxygen is low if you die the empires will not aid you \n");
                oxegen_bar();Score_bar_level1();Fuel_bar();
            }
        }if (oxegen <= 0) {
            printf("\n you ran out of oxygen, still useless in the end! Game over");
            break;
        }if (score >= Win_score_1) {
            printf("You collected %d pieces of space junk You move to to level 2\n", score);
            break;
        }
    }
    return 0;
}