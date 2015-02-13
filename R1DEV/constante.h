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
#define MARIO_X 32
#define MARIO_Y 32
#define TEMPS_FRAMES 8
#define D_MARCHE 1
#define G_MARCHE 2
#define STOP 3
#define D_SAUT 4
#define G_SAUT 5
#define DROITE 1
#define GAUCHE 2

typedef struct Input
{
    int gauche, droite, saut;
} Input;

typedef struct Configuration
{
    SDL_Surface *ecran;
    int nbEntite;
    int vies;
    int niveau;
} Configuration;

typedef struct Carte
{
    SDL_Surface *background, *tileSet;
    int startX, startY;
    int xmax, ymax;
    int tile[CARTE_Y_MAX][CARTE_X_MAX];
} Carte;

typedef struct Objet
{
    SDL_Surface *sprite;
    int x, y;
    int h, l;
    int frameNumber, frameTimer;
    int etat;
    int direction;
    int auSol;
    int mort;
    float vectx, vecty;
    int saveX, saveY;
    int entiteID;
    int marioID;
} Objet;
