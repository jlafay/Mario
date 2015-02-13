#include "constante.h"

extern Objet monstreEtBonus[];
extern Configuration parametre;
extern Objet mario;
extern Input input;
extern Carte coordonee;

extern SDL_Surface *loadImage(char *nom);
extern void collisionDecor(Objet *entite2);
extern void changerAnimation(Objet *entite2, char *nom);
extern void chargerCarte(char *nom);
extern void changerCarte(void);
