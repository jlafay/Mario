#include "constante.h"

Input input;
Configuration parametre;
Carte coordonee;
Objet mario;
Objet monstreEtBonus[20];

extern SDL_Surface *loadImage(char *nom);
extern void cleanup(void);
extern void draw(void);
extern void cfgFrame(unsigned int frameLimit);
extern void reactualiserMario(void);
extern void reactualiserSuperMario(void);
extern void reactualiserFireMario(void);
extern void initMario(void);
extern void reactualiserEntite(void);
extern void chargerCarte(char *nom);
extern void changerCarte(void);
