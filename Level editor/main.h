#include "constante.h"

Input input;
Configuration parametre;
Carte coordonee;
Cursor cursor;

extern SDL_Surface *loadImage(char *nom);
extern void draw(void);
extern void cleanup(void);
extern void cfgFrame(unsigned int frameLimit);
extern void chargerCarte(char *nom);
extern void reinitialiserCarte(char *nom);
extern void sauvegarderCarte(char *nom);
