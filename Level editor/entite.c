#include "player.h"


  void initializePlayer(void)
   {

       /* Charge le sprite de notre h�ros */
       player.sprite = loadImage("graphics/walkright.png");

      /* Coordonn�es de d�marrage de notre h�ros */
       player.x = 20;
       player.y = 304;

   }
