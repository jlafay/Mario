#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#define ECRAN_X 640
#define ECRAN_Y 480
#define CARTE_X_MAX 400
#define CARTE_Y_MAX 300
#define TILE 32
#define TILE_MAX 12

typedef struct Input
{
    int gauche, droite, haut, bas, ajouter, supprimer;
    int precedent, suivant, charger, sauvegarder, copier, reinitialiser;
    int mouseX, mouseY;
} Input;

typedef struct Cursor
{
      int x, y, tileID;
} Cursor;

typedef struct Configuration
{
    SDL_Surface *ecran;
} Configuration;

typedef struct Carte
{
    SDL_Surface *background, *tileSet;
    int startX, startY;
    int xmax, ymax;
    int tile[CARTE_Y_MAX][CARTE_X_MAX];
} Carte;
