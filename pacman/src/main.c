#include "main.h"
#include <stdio.h>
#include <stdbool.h>

#include "firstLevel.h"
#include "fantomes.h"
#include <time.h>

void eat(char **level, int x, int y) {
    if (level[y][x] == '.') {
        level[y][x] = ' ';
    }
}

bool win(const char **level) {
    // Parcourt toutes les lignes puis les colonnes du niveau
    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < 28; j++) {
            // Si on trouve un point
            if (level[i][j] == '.') {
                return false;
            }
        }
    }

    // Si aucun point n'a été trouvé
    return true;
}

int main(int argc, char *argv[]) {
    // Initialise les paramètres
    RendererParameters params;
    Textures textures;

    // Initialise la fenêtre et le rendu
    initWindowed(&params, &textures, 31, 28);

    // Charger le niveau
    char **level;
    loadFirstLevel(&level);

    // Position initiale de Pacman
    int pacmanX = 14; // Colonne
    int pacmanY = 17; // Ligne
    level[pacmanY][pacmanX] = 'O'; // Place Pacman

    // Position initiale et direction de clyde (orange)
    Ghost clyde = {{12, 15}, {0, 1}}; // Position initiale et direction
    level[clyde.pos.y][clyde.pos.x] = 'C'; // Représentation de Clyde sur la grille

    // Position initiale et direction de Pinky (rose)
    Ghost pinky = {{16, 13}, {0, -1}, PINKY, textures.texturePinky};
    level[pinky.pos.y][pinky.pos.x] = 'P'; // Représentation de Pinky sur la grille

    // Position initiale et direction d'Inky (cyan)
    Ghost inky = {{14, 15}, {1, 0}, INKY, textures.textureInky};
    level[inky.pos.y][inky.pos.x] = 'I'; // Représentation d'Inky sur la grille

    // Position initiale et direction d'Inky (cyan)
    Ghost blinky = {{14, 15}, {1, 0}, BLINKY, textures.textureBlinky};
    level[blinky.pos.y][blinky.pos.x] = 'B'; // Représentation d'Inky sur la grille


    // Directions
    int dirX = 0, dirY = 0; // Direction actuelle de Pacman (par défaut à droite)
    int nextDirX = 0, nextDirY = 0; // Direction sauvegardée (par défaut à droite)

    // Boucle du jeu
    int running = 1;
    while (running) {
        // Gère les entrées utilisateur
        int input = getInput();
        if (input == SDLK_ESCAPE) {
            running = 0;
        } else if (input) {
            // Mise à jour de la direction sauvegardée
            switch (input) {
                case SDLK_UP: nextDirX = 0; nextDirY = -1; break;
                case SDLK_DOWN: nextDirX = 0; nextDirY = 1; break;
                case SDLK_LEFT: nextDirX = -1; nextDirY = 0; break;
                case SDLK_RIGHT: nextDirX = 1; nextDirY = 0; break;
            }
        }

        // Calcul de la prochaine position
        int newX = pacmanX + nextDirX;
        int newY = pacmanY + nextDirY;

        // Si la prochaine position est valide, appliquez la nouvelle direction
        if (level[newY][newX] != 'H') {
            dirX = nextDirX;
            dirY = nextDirY;
        }

        // Mise à jour de la position
        newX = (pacmanX + dirX + 28) % 28;
        newY = (pacmanY + dirY + 31) % 31;

        if (level[newY][newX] != 'H') {
            level[pacmanY][pacmanX] = ' '; // Effacer l'ancienne position
            pacmanX = newX;
            pacmanY = newY;
            level[pacmanY][pacmanX] = 'O'; // Pacman se déplace
        }

        eat(level, pacmanX, pacmanY);

        // Si Pacman a tout mangé, fin de la partie
        if (win((const char **)level)) {
            running = 0;
        }

        // Déplace Clyde
        clydeMove((const char **)level, &clyde);

        // Déplace Pinky
        specificGhostMovement((const char **)level, &pinky, pacmanX, pacmanY, 0, 0);

        // Déplace Inky
        specificGhostMovement((const char **)level, &inky, pacmanX, pacmanY, 0, 0);

        // Déplace Blinky
        specificGhostMovement((const char **)level, &blinky, pacmanX, pacmanY, dirX, dirY);


        // Vérifiez si un fantôme rencontre Pac-Man
         if (checkCollision(&clyde, pacmanX, pacmanY) || checkCollision(&pinky, pacmanX, pacmanY) || checkCollision(&inky, pacmanX, pacmanY) || checkCollision(&blinky, pacmanX, pacmanY)) {
            printf("Un fantôme a mangé Pac-Man !\n");
            running = 0; // Fin du jeu
         }

        // Dessine le niveau
        drawLevel(level, 31, 28, &params, &textures);

        // Calcul de l'angle pour Pacman
        float angle = 180; // à droite
        if (dirX == 0 && dirY == -1) {
            angle = 90; // regarde en haut
        } else if (dirX == 0 && dirY == 1) {
            angle = 270; // regarde en bas
        } else if (dirX == -1 && dirY == 0) {
            angle = 0; // regarde à gauche
        }

        // Dessine Pacman
        drawSpriteOnGrid(textures.texturePacman, pacmanX, pacmanY, angle, &params);

        // Dessine Clyde
        drawSpriteOnGrid(textures.textureClyde, clyde.pos.x, clyde.pos.y, 0, &params);

        // Dessine Pinky
        drawSpriteOnGrid(textures.texturePinky, pinky.pos.x, pinky.pos.y, 0, &params);

        // Dessine Inky
        drawSpriteOnGrid(textures.textureInky, inky.pos.x, inky.pos.y, 0, &params);

        // Dessine Blinky
        drawSpriteOnGrid(textures.textureBlinky, blinky.pos.x, blinky.pos.y, 0, &params);

        // Mise à jour de l'affichage
        update(&params);
    }

    // Libérer la mémoire du tableau
    for (int i = 0; i < 31; i++) {
        free(level[i]);
    }
    free(level);

    // Libère les ressources SDL
    SDL_DestroyRenderer(params.renderer);
    SDL_DestroyWindow(params.window);
    SDL_Quit();

    return 0;
}