#include "fantomes.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h> // Pour le type bool


// Obtenir les directions disponibles pour Clyde
Coord *getPotentialDirection(const char **level, const Ghost *ghost, int *nbDir) {
    Coord directions[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    Coord *availableDirections = malloc(sizeof(Coord) * 4);
    *nbDir = 0;

    for (int i = 0; i < 4; i++) {
        int newX = ghost->pos.x + directions[i].x;
        int newY = ghost->pos.y + directions[i].y;

        // Vérifie si la case est hors des limites
        if (newX < 0 || newX >= 28 || newY < 0 || newY >= 31) {
            continue;
        }

        // Vérifie si la case est un mur
        if (level[newY][newX] == 'H') {
            continue;
        }

        // Empêche le demi-tour
        if (newX == ghost->pos.x - ghost->dir.x && newY == ghost->pos.y - ghost->dir.y) {
            continue;
        }

        // Ajoute la direction valide au tableau
        availableDirections[*nbDir] = directions[i];
        (*nbDir)++;
    }

    return availableDirections;
}

Coord getPacmanNextIntersec(const char **level, int pacmanX, int pacmanY, int dirX, int dirY) {
    Coord nextIntersec = {pacmanX, pacmanY};

    // Check if Pac-Man is stationary
    if (dirX == 0 && dirY == 0) {
        printf("[ERROR] Pac-Man is stationary. No intersection can be calculated.\n");
        return nextIntersec;
    }

    while (1) {
        // Advance in the given direction
        nextIntersec.x += dirX;
        nextIntersec.y += dirY;

        // Check grid boundaries
        if (nextIntersec.x < 0 || nextIntersec.x >= 28 || nextIntersec.y < 0 || nextIntersec.y >= 31) {
            printf("[DEBUG] Out of bounds: (%d, %d)\n", nextIntersec.x, nextIntersec.y);
            break;
        }

        // Check for an intersection
        int paths = 0;
        if (nextIntersec.y > 0 && level[nextIntersec.y - 1][nextIntersec.x] != 'H') paths++; // Up
        if (nextIntersec.y < 30 && level[nextIntersec.y + 1][nextIntersec.x] != 'H') paths++; // Down
        if (nextIntersec.x > 0 && level[nextIntersec.y][nextIntersec.x - 1] != 'H') paths++; // Left
        if (nextIntersec.x < 27 && level[nextIntersec.y][nextIntersec.x + 1] != 'H') paths++; // Right

        printf("[DEBUG] Checking position (%d, %d): Paths = %d\n", nextIntersec.x, nextIntersec.y, paths);

        if (paths > 2) {
            // Found an intersection
            printf("[DEBUG] Intersection found at (%d, %d)\n", nextIntersec.x, nextIntersec.y);
            return nextIntersec;
        }

        // Check if we hit a wall
        if (level[nextIntersec.y][nextIntersec.x] == 'H') {
            printf("[DEBUG] Hit a wall at (%d, %d)\n", nextIntersec.x, nextIntersec.y);
            break;
        }
    }

    // Return the original position if no intersection is found
    printf("[DEBUG] No intersection found. Returning original position (%d, %d)\n", pacmanX, pacmanY);
    return (Coord){pacmanX, pacmanY};
}


void clydeMove(const char **level, Ghost *ghost) {
    int nbDir = 0;
    Coord availableDirections[4];
    Coord *validDirs = getPotentialDirection(level, ghost, &nbDir);

    if (nbDir == 0) {
        ghost->dir.x = -ghost->dir.x;
        ghost->dir.y = -ghost->dir.y;
    } else {
        // Choose random direction
        ghost->dir = validDirs[rand() % nbDir];
    }

    // Update position
    ghost->pos.x = (ghost->pos.x + ghost->dir.x + 28) % 28;
    ghost->pos.y = (ghost->pos.y + ghost->dir.y + 31) % 31;
}


void pinkyMove(const char **level, Ghost *ghost, int pacmanX, int pacmanY) {
    // Vérifiez si Pinky a une ligne de vue directe avec Pac-Man
    if (ghost->pos.x == pacmanX) {
        // Même colonne : vérifier s'il y a un mur entre eux
        int start = (ghost->pos.y < pacmanY) ? ghost->pos.y : pacmanY;
        int end = (ghost->pos.y > pacmanY) ? ghost->pos.y : pacmanY;

        bool hasLineOfSight = true;
        for (int y = start + 1; y < end; y++) {
            if (level[y][ghost->pos.x] == 'H') {
                hasLineOfSight = false;
                break;
            }
        }

        if (hasLineOfSight) {
            // Poursuit Pac-Man verticalement
            ghost->dir.x = 0;
            ghost->dir.y = (pacmanY > ghost->pos.y) ? 1 : -1;
            ghost->pos.y = (ghost->pos.y + ghost->dir.y + 31) % 31;
            return;
        }
    } else if (ghost->pos.y == pacmanY) {
        // Même ligne : vérifier s'il y a un mur entre eux
        int start = (ghost->pos.x < pacmanX) ? ghost->pos.x : pacmanX;
        int end = (ghost->pos.x > pacmanX) ? ghost->pos.x : pacmanX;

        bool hasLineOfSight = true;
        for (int x = start + 1; x < end; x++) {
            if (level[ghost->pos.y][x] == 'H') {
                hasLineOfSight = false;
                break;
            }
        }

        if (hasLineOfSight) {
            // Poursuit Pac-Man horizontalement
            ghost->dir.x = (pacmanX > ghost->pos.x) ? 1 : -1;
            ghost->dir.y = 0;
            ghost->pos.x = (ghost->pos.x + ghost->dir.x + 28) % 28;
            return;
        }
    }

    // Si pas de ligne de vue, agit comme Clyde
    clydeMove(level, ghost);
}

void inkyMove(const char **level, Ghost *ghost, int pacmanX, int pacmanY) {
    // Chance aléatoire qu'Inky prenne une direction aléatoire
    if (rand() % INKY_RANDOMNESS == 0) {
        clydeMove(level, ghost);
        return;
    }

    int nbDir = 0;
    Coord *availableDirections = getPotentialDirection(level, ghost, &nbDir);

    if (nbDir == 0) {
        // Cul-de-sac : demi-tour
        ghost->dir.x = -ghost->dir.x;
        ghost->dir.y = -ghost->dir.y;
    } else {
        int dx = abs(ghost->pos.x - pacmanX);
        int dy = abs(ghost->pos.y - pacmanY);

        Coord bestDirection = {0, 0};
        int bestDistance = 10000; // Grande valeur par défaut

        // Choisissez la direction qui réduit la plus grande différence
        for (int i = 0; i < nbDir; i++) {
            int newX = ghost->pos.x + availableDirections[i].x;
            int newY = ghost->pos.y + availableDirections[i].y;

            int newDx = abs(newX - pacmanX);
            int newDy = abs(newY - pacmanY);

            int distance = (dx > dy) ? newDx : newDy; // Privilégier l'axe le plus éloigné
            if (distance < bestDistance) {
                bestDistance = distance;
                bestDirection = availableDirections[i];
            }
        }

        if (bestDistance == 10000) {
            // Si aucune direction intéressante, choisissez une aléatoire
            bestDirection = availableDirections[rand() % nbDir];
        }

        ghost->dir = bestDirection;
    }

    free(availableDirections);

    // Mise à jour de la position
    ghost->pos.x = (ghost->pos.x + ghost->dir.x + 28) % 28;
    ghost->pos.y = (ghost->pos.y + ghost->dir.y + 31) % 31;
}


void blinkyMove(const char **level, Ghost *ghost, int pacmanX, int pacmanY, int dirX, int dirY) {
    printf("[DEBUG] BlinkyMove called\n");
    printf("Pac-Man position: (%d, %d)\n", pacmanX, pacmanY);
    printf("Pac-Man direction: (%d, %d)\n", dirX, dirY);
    printf("Blinky position: (%d, %d)\n", ghost->pos.x, ghost->pos.y);
    printf("Blinky direction: (%d, %d)\n", ghost->dir.x, ghost->dir.y);

    if (!level || !ghost) {
        fprintf(stderr, "[ERROR] Null pointer passed to blinkyMove\n");
        return;
    }

    if (rand() % BLINKY_RANDOMNESS == 0) {
        printf("[DEBUG] Blinky taking random direction (Clyde logic)\n");
        clydeMove(level, ghost);
        return;
    }

    // Debug: Validate `getPacmanNextIntersec`
    Coord target = getPacmanNextIntersec(level, pacmanX, pacmanY, dirX, dirY);
    if (target.x < 0 || target.y < 0) {
        fprintf(stderr, "[ERROR] Invalid target returned by getPacmanNextIntersec: (%d, %d)\n", target.x, target.y);
        return;
    }
    printf("[DEBUG] Target intersection: (%d, %d)\n", target.x, target.y);

    // Debug: Validate `getPotentialDirection`
    int nbDir = 0;
    Coord *availableDirections = getPotentialDirection(level, ghost, &nbDir);
    if (!availableDirections) {
        fprintf(stderr, "[ERROR] getPotentialDirection returned NULL\n");
        return;
    }
    printf("[DEBUG] Available directions: %d\n", nbDir);

    if (nbDir == 0) {
        printf("[DEBUG] Dead end: reversing direction\n");
        ghost->dir.x = -ghost->dir.x;
        ghost->dir.y = -ghost->dir.y;
    } else {
        Coord bestDirection = {0, 0};
        int bestDistance = 10000;

        for (int i = 0; i < nbDir; i++) {
            int newX = ghost->pos.x + availableDirections[i].x;
            int newY = ghost->pos.y + availableDirections[i].y;
            int distance = abs(newX - target.x) + abs(newY - target.y);

            printf("[DEBUG] Checking direction (%d, %d): Distance = %d\n",
                   availableDirections[i].x, availableDirections[i].y, distance);

            if (distance < bestDistance) {
                bestDistance = distance;
                bestDirection = availableDirections[i];
            }
        }

        printf("[DEBUG] Best direction: (%d, %d), Distance: %d\n",
               bestDirection.x, bestDirection.y, bestDistance);
        ghost->dir = bestDirection;
    }

    free(availableDirections);

    // Update position with wraparound
    ghost->pos.x = (ghost->pos.x + ghost->dir.x + GRID_WIDTH) % GRID_WIDTH;
    ghost->pos.y = (ghost->pos.y + ghost->dir.y + GRID_HEIGHT) % GRID_HEIGHT;

    printf("[DEBUG] Updated position: (%d, %d)\n", ghost->pos.x, ghost->pos.y);
}




void specificGhostMovement(const char **level, Ghost *ghost, int pacmanX, int pacmanY, int dirX, int dirY){
    switch (ghost->name) {
        case CLYDE:
            clydeMove(level, ghost);
        break;
        case PINKY:
            pinkyMove(level, ghost, pacmanX, pacmanY);
        break;
        case INKY:
            inkyMove(level, ghost, pacmanX, pacmanY);
        break;
        case BLINKY:
            blinkyMove(level, ghost, pacmanX, pacmanY, dirX, dirY);
        break;
        default:
            break;
    }
}


// vérifier si Clyde rencontre Pac-Man
bool checkCollision(const Ghost *ghost, int pacmanX, int pacmanY) {
    return ghost->pos.x == pacmanX && ghost->pos.y == pacmanY;
}

