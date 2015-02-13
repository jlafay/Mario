#include "player.h"


  void initializePlayer(void)
   {

       /* Charge le sprite de notre héros */
       player.sprite = loadImage("graphics/walkright.png");

      /* Coordonnées de démarrage de notre héros */
       player.x = 20;
       player.y = 304;

   }
