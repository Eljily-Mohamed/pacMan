#ifndef FANTOMES_H
#define FANTOMES_H
#define INKY_RANDOMNESS 3
#define BLINKY_RANDOMNESS 3
#define GRID_WIDTH 28
#define GRID_HEIGHT 31

#include "../include/SDL2/SDL.h"
#include "framework.h"
#include <stdbool.h>


// Structure pour les coordonnées (position et direction)
typedef struct Coord {
    int x;
    int y;
} Coord;

typedef enum GhostName {
    BLINKY,
    CLYDE,
    INKY,
    PINKY
} GhostName;

// Structure pour les fantômes
typedef struct Ghost {
    Coord pos;
    Coord dir;
    GhostName name;        // Identifiant du fantôme
    SDL_Texture *texture;  // Texture du fantôme
} Ghost;


// Prototypes des fonctions
Coord *getPotentialDirection(const char **level, const Ghost *ghost, int *nbDir);
Coord getPacmanNextIntersec(const char **level, int pacmanX, int pacmanY, int dirX, int dirY);


void specificGhostMovement(const char **level, Ghost *ghost, int pacmanX, int pacmanY, int dirX, int dirY);
void clydeMove(const char **level, Ghost *ghost);
void pinkyMove(const char **level, Ghost *ghost, int pacmanX, int pacmanY);
void inkyMove(const char **level, Ghost *ghost, int pacmanX, int pacmanY);
void blinkyMove(const char **level, Ghost *ghost, int pacmanX, int pacmanY, int dirX, int dirY);

bool checkCollision(const Ghost *ghost, int pacmanX, int pacmanY);



#endif // FANTOMES_H
