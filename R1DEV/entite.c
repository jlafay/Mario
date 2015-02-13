#include "entite.h"

void entite(int x, int y, int type)
{
        if (type == 1)
        {
            monstreEtBonus[parametre.nbEntite].sprite = loadImage("images/goombaG.png");
            monstreEtBonus[parametre.nbEntite].entiteID = 1;
            monstreEtBonus[parametre.nbEntite].direction = GAUCHE;
            monstreEtBonus[parametre.nbEntite].x = x;
            monstreEtBonus[parametre.nbEntite].y = y;
        }
        else if (type == 2)
        {
            monstreEtBonus[parametre.nbEntite].sprite = loadImage("images/koopaG.png");
            monstreEtBonus[parametre.nbEntite].entiteID = 2;
            monstreEtBonus[parametre.nbEntite].direction = GAUCHE;
            monstreEtBonus[parametre.nbEntite].x = x;
            monstreEtBonus[parametre.nbEntite].y = y;
        }
        else if (type == 3)
        {
            monstreEtBonus[parametre.nbEntite].sprite = loadImage("images/plante.png");
            monstreEtBonus[parametre.nbEntite].entiteID = 3;
            monstreEtBonus[parametre.nbEntite].direction = GAUCHE;
            monstreEtBonus[parametre.nbEntite].x = x;
            monstreEtBonus[parametre.nbEntite].y = y;
        }
        else if (type == 4)
        {
            monstreEtBonus[parametre.nbEntite].sprite = loadImage("images/shell.png");
            monstreEtBonus[parametre.nbEntite].entiteID = 4;
            monstreEtBonus[parametre.nbEntite].direction = GAUCHE;
            monstreEtBonus[parametre.nbEntite].x = x;
            monstreEtBonus[parametre.nbEntite].y = y;
        }
        else if (type == 5)
        {
            monstreEtBonus[parametre.nbEntite].sprite = loadImage("images/shell.png");
            monstreEtBonus[parametre.nbEntite].entiteID = 5;
            monstreEtBonus[parametre.nbEntite].direction = DROITE;
            monstreEtBonus[parametre.nbEntite].x = x;
            monstreEtBonus[parametre.nbEntite].y = y;
        }
        else if (type == 6)
        {
            monstreEtBonus[parametre.nbEntite].sprite = loadImage("images/shell.png");
            monstreEtBonus[parametre.nbEntite].entiteID = 6;
            monstreEtBonus[parametre.nbEntite].direction = GAUCHE;
            monstreEtBonus[parametre.nbEntite].x = x;
            monstreEtBonus[parametre.nbEntite].y = y;
        }
        else if (type == 7)
        {
            monstreEtBonus[parametre.nbEntite].sprite = loadImage("images/champi.png");
            monstreEtBonus[parametre.nbEntite].entiteID = 7;
            monstreEtBonus[parametre.nbEntite].direction = DROITE;
            monstreEtBonus[parametre.nbEntite].x = x;
            monstreEtBonus[parametre.nbEntite].y = y -=32;
        }
        else if (type == 8)
        {
            monstreEtBonus[parametre.nbEntite].sprite = loadImage("images/fleur.png");
            monstreEtBonus[parametre.nbEntite].entiteID = 8;
            monstreEtBonus[parametre.nbEntite].direction = GAUCHE;
            monstreEtBonus[parametre.nbEntite].x = x;
            monstreEtBonus[parametre.nbEntite].y = y -=32;
        }
        monstreEtBonus[parametre.nbEntite].frameNumber = 0;
        monstreEtBonus[parametre.nbEntite].frameTimer = TEMPS_FRAMES;
        monstreEtBonus[parametre.nbEntite].x = x;
        monstreEtBonus[parametre.nbEntite].y = y;
        monstreEtBonus[parametre.nbEntite].l = TILE;
        monstreEtBonus[parametre.nbEntite].h = TILE;
        monstreEtBonus[parametre.nbEntite].mort = 0;
        monstreEtBonus[parametre.nbEntite].auSol = 0;

        parametre.nbEntite++;
}

void reactualiserEntite(void)
{
    int i;
    for ( i = 0; i < parametre.nbEntite; i++ )
    {
        if (monstreEtBonus[i].mort == 0)
        {
            if (monstreEtBonus[i].entiteID == 1)
            {
                monstreEtBonus[i].vectx = 0;
                monstreEtBonus[i].vecty += 0.6;

                if (monstreEtBonus[i].vecty >= 10)
                {
                    monstreEtBonus[i].vecty = 10;
                }

                if (monstreEtBonus[i].x == monstreEtBonus[i].saveX)
                {
                    if (monstreEtBonus[i].direction == GAUCHE)
                    {
                        monstreEtBonus[i].direction = DROITE;
                        changerAnimation(&monstreEtBonus[i], "images/goombaD.png");
                    }
                    else
                    {
                        monstreEtBonus[i].direction = GAUCHE;
                        changerAnimation(&monstreEtBonus[i], "images/goombaG.png");
                    }
                }

                if(monstreEtBonus[i].direction == GAUCHE)
                {
                    monstreEtBonus[i].vectx -= 2;
                }
                else
                {
                    monstreEtBonus[i].vectx += 2;
                }
                monstreEtBonus[i].saveX = monstreEtBonus[i].x;

                collisionDecor(&monstreEtBonus[i]);
                if (collisionEntite(&mario, &monstreEtBonus[i]) == 1)
                {
                    if (mario.marioID == 1)
                    {
                        mario.mort = 1;
                    }
                    else if (mario.marioID == 2)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                    else if (mario.marioID == 3)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                }
                else if (collisionEntite(&mario, &monstreEtBonus[i]) == 2)
                {
                    monstreEtBonus[i].mort = 1;
                }
                else if (collisionEntite(&mario, &monstreEtBonus[i]) == 3)
                {
                    if (mario.marioID == 1)
                    {
                        mario.mort = 1;
                    }
                    else if (mario.marioID == 2)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                    else if (mario.marioID == 3)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                }
            }
            if (monstreEtBonus[i].entiteID == 2)
            {
                monstreEtBonus[i].vectx = 0;
                monstreEtBonus[i].vecty += 0.6;

                if (monstreEtBonus[i].vecty >= 10)
                {
                    monstreEtBonus[i].vecty = 10;
                }
                if (monstreEtBonus[i].x == monstreEtBonus[i].saveX)
                {
                    if (monstreEtBonus[i].direction == GAUCHE)
                    {
                        monstreEtBonus[i].direction = DROITE;
                        changerAnimation(&monstreEtBonus[i], "images/koopaD.png");
                    }
                    else
                    {
                        monstreEtBonus[i].direction = GAUCHE;
                        changerAnimation(&monstreEtBonus[i], "images/koopaG.png");
                    }
                }

                if(monstreEtBonus[i].direction == GAUCHE)
                {
                    monstreEtBonus[i].vectx -= 2;
                }
                else
                {
                    monstreEtBonus[i].vectx += 2;
                }
                monstreEtBonus[i].saveX = monstreEtBonus[i].x;

                collisionDecor(&monstreEtBonus[i]);
                if (collisionEntite(&mario, &monstreEtBonus[i]) == 1)
                {
                    if (mario.marioID == 1)
                    {
                        mario.mort = 1;
                    }
                    else if (mario.marioID == 2)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                    else if (mario.marioID == 3)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                }
                else if (collisionEntite(&mario, &monstreEtBonus[i]) == 2)
                {
                    monstreEtBonus[i].mort = 1;
                    entite(monstreEtBonus[i].x, monstreEtBonus[i].y, 4);
                }
                else if (collisionEntite(&mario, &monstreEtBonus[i]) == 3)
                {
                    if (mario.marioID == 1)
                    {
                        mario.mort = 1;
                    }
                    else if (mario.marioID == 2)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                    else if (mario.marioID == 3)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                }
            }
            if (monstreEtBonus[i].entiteID == 3)
            {
                if (collisionEntite(&mario, &monstreEtBonus[i]) == 1)
                {
                    if (mario.marioID == 1)
                    {
                        mario.mort = 1;
                    }
                    else if (mario.marioID == 2)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                    else if (mario.marioID == 3)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                }
                else if (collisionEntite(&mario, &monstreEtBonus[i]) == 2)
                {
                    if (mario.marioID == 1)
                    {
                        mario.mort = 1;
                    }
                    else if (mario.marioID == 2)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                    else if (mario.marioID == 3)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                }
                else if (collisionEntite(&mario, &monstreEtBonus[i]) == 3)
                {
                    if (mario.marioID == 1)
                    {
                        mario.mort = 1;
                    }
                    else if (mario.marioID == 2)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                    else if (mario.marioID == 3)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                }
            }
            if (monstreEtBonus[i].entiteID == 4)
            {
                if (collisionEntite2(&mario, &monstreEtBonus[i]) == 1)
                {
                    if(mario.marioID == 1)
                    {
                        monstreEtBonus[i].mort = 1;
                        entite(monstreEtBonus[i].x += 16, monstreEtBonus[i].y, 5);
                    }
                    else if(mario.marioID == 2)
                    {
                        monstreEtBonus[i].mort = 1;
                        entite(monstreEtBonus[i].x += 16, monstreEtBonus[i].y, 5);
                    }
                    else if(mario.marioID == 3)
                    {
                        monstreEtBonus[i].mort = 1;
                        entite(monstreEtBonus[i].x += 16, monstreEtBonus[i].y, 5);
                    }
                }
                if (collisionEntite2(&mario, &monstreEtBonus[i]) == 3)
                {
                    if(mario.marioID == 1)
                    {
                        monstreEtBonus[i].mort = 1;
                        entite(monstreEtBonus[i].x -= 16, monstreEtBonus[i].y, 6);
                    }
                    else if(mario.marioID == 2)
                    {
                        monstreEtBonus[i].mort = 1;
                        entite(monstreEtBonus[i].x -= 16, monstreEtBonus[i].y, 6);
                    }
                    else if(mario.marioID == 3)
                    {
                        monstreEtBonus[i].mort = 1;
                        entite(monstreEtBonus[i].x -=16, monstreEtBonus[i].y, 6);
                    }
                }
            }
            if (monstreEtBonus[i].entiteID == 5)
            {
                monstreEtBonus[i].vectx = 0;
                monstreEtBonus[i].vecty += 0.6;

                if (monstreEtBonus[i].vecty >= 20)
                {
                    monstreEtBonus[i].vecty = 20;
                }

                if (monstreEtBonus[i].x == monstreEtBonus[i].saveX)
                {
                    if (monstreEtBonus[i].direction == GAUCHE)
                    {
                        monstreEtBonus[i].direction = DROITE;
                    }
                    else
                    {
                        monstreEtBonus[i].direction = GAUCHE;
                    }

                }
                if(monstreEtBonus[i].direction == GAUCHE)
                {
                    monstreEtBonus[i].vectx -= 4;
                }
                else
                {
                    monstreEtBonus[i].vectx += 4;
                }
                monstreEtBonus[i].saveX = monstreEtBonus[i].x;

                collisionDecor(&monstreEtBonus[i]);
                if (collisionEntite(&mario, &monstreEtBonus[i]) == 1)
                {
                    if (mario.marioID == 1)
                    {
                        mario.mort = 1;
                    }
                    else if (mario.marioID == 2)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                    else if (mario.marioID == 3)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                }
                else if (collisionEntite(&mario, &monstreEtBonus[i]) == 2)
                {
                    if (mario.marioID == 1)
                    {
                        mario.mort = 1;
                    }
                    else if (mario.marioID == 2)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                    else if (mario.marioID == 3)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                }
                else if (collisionEntite(&mario, &monstreEtBonus[i]) == 3)
                {
                    if (mario.marioID == 1)
                    {
                        mario.mort = 1;
                    }
                    else if (mario.marioID == 2)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                    else if (mario.marioID == 3)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                }
            }
            if (monstreEtBonus[i].entiteID == 6)
            {
                monstreEtBonus[i].vectx = 0;
                monstreEtBonus[i].vecty += 0.6;
                if (monstreEtBonus[i].vecty >= 20)
                {
                    monstreEtBonus[i].vecty = 20;
                }
                if (monstreEtBonus[i].x == monstreEtBonus[i].saveX)
                {
                    if (monstreEtBonus[i].direction == GAUCHE)
                    {
                        monstreEtBonus[i].direction = DROITE;
                    }
                    else
                    {
                        monstreEtBonus[i].direction = GAUCHE;
                    }
                }
                if(monstreEtBonus[i].direction == GAUCHE)
                {
                    monstreEtBonus[i].vectx -= 4;
                }
                else
                {
                    monstreEtBonus[i].vectx += 4;
                }
                monstreEtBonus[i].saveX = monstreEtBonus[i].x;

                collisionDecor(&monstreEtBonus[i]);
                if (collisionEntite(&mario, &monstreEtBonus[i]) == 1)
                {
                    if (mario.marioID == 1)
                    {
                        mario.mort = 1;
                    }
                    else if (mario.marioID == 2)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                    else if (mario.marioID == 3)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                }
                else if (collisionEntite(&mario, &monstreEtBonus[i]) == 2)
                {
                    if (mario.marioID == 1)
                    {
                        mario.mort = 1;
                    }
                    else if (mario.marioID == 2)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                    else if (mario.marioID == 3)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                }
                else if (collisionEntite(&mario, &monstreEtBonus[i]) == 3)
                {
                    if (mario.marioID == 1)
                    {
                        mario.mort = 1;
                    }
                    else if (mario.marioID == 2)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                    else if (mario.marioID == 3)
                    {
                        monstreEtBonus[i].mort = 1;
                        mario.marioID = 1;
                        changerAnimation(&mario, "images/M_D.png");
                    }
                }
            }
            if (monstreEtBonus[i].entiteID == 7)
            {
                monstreEtBonus[i].vectx = 0;
                monstreEtBonus[i].vecty += 0.6;

                if (monstreEtBonus[i].vecty >= 20)
                {
                    monstreEtBonus[i].vecty = 20;
                }
                if (monstreEtBonus[i].x == monstreEtBonus[i].saveX)
                {
                    if (monstreEtBonus[i].direction == GAUCHE)
                    {
                        monstreEtBonus[i].direction = DROITE;
                    }
                    else
                    {
                        monstreEtBonus[i].direction = GAUCHE;
                    }

                }
                if(monstreEtBonus[i].direction == GAUCHE)
                {
                    monstreEtBonus[i].vectx -= 2;
                }
                else
                {
                    monstreEtBonus[i].vectx += 2;
                }
                monstreEtBonus[i].saveX = monstreEtBonus[i].x;

                collisionDecor(&monstreEtBonus[i]);
                if (collisionEntite2(&mario, &monstreEtBonus[i]) == 1)
                {
                    monstreEtBonus[i].mort = 1;
                    mario.marioID = 2;
                    mario.y = mario.y -32;
                    changerAnimation(&mario, "images/SM_D.png");
                }
                else if (collisionEntite2(&mario, &monstreEtBonus[i]) == 2)
                {
                    monstreEtBonus[i].mort = 1;
                    mario.marioID = 2;
                    mario.y = mario.y -32;
                    changerAnimation(&mario, "images/SM_D.png");
                }
                else if (collisionEntite2(&mario, &monstreEtBonus[i]) == 3)
                {
                    monstreEtBonus[i].mort = 1;
                    mario.marioID = 2;
                    mario.y = mario.y -32;
                    changerAnimation(&mario, "images/SM_D.png");
                }
            }
            if (monstreEtBonus[i].entiteID == 8)
            {
                if (collisionEntite2(&mario, &monstreEtBonus[i]) == 1)
                {
                    monstreEtBonus[i].mort = 1;
                    mario.marioID = 3;
                    changerAnimation(&mario, "images/FM_D.png");
                }
                else if (collisionEntite2(&mario, &monstreEtBonus[i]) == 2)
                {
                    monstreEtBonus[i].mort = 1;
                    mario.marioID = 3;
                    changerAnimation(&mario, "images/FM_D.png");
                }
                else if (collisionEntite2(&mario, &monstreEtBonus[i]) == 3)
                {
                    monstreEtBonus[i].mort = 1;
                    mario.marioID = 3;
                    changerAnimation(&mario, "images/FM_D.png");
                }
            }
        }
        if (monstreEtBonus[i].mort > 0)
        {
            monstreEtBonus[i].mort--;
            if (monstreEtBonus[i].mort == 0)
            {
                if (monstreEtBonus[i].sprite != NULL)
                {
                    SDL_FreeSurface(monstreEtBonus[i].sprite);
                }
                monstreEtBonus[i] = monstreEtBonus[parametre.nbEntite-1];
                parametre.nbEntite--;
            }
        }
    }
}

int collisionEntite(Objet *mario, Objet *monstreEtBonus)
{
    if ((mario->x >= monstreEtBonus->x + monstreEtBonus->l)
    || (mario->x + mario->l <= monstreEtBonus->x)
    || (mario->y >= monstreEtBonus->y + monstreEtBonus->h)
    || (mario->y + mario->h <= monstreEtBonus->y))
    {
        return 0;
    }
    else if (mario->y + mario->h <= monstreEtBonus->y + 10)
    {
        mario->vecty = -12;
        return 2;
    }
    else if ((mario->x + mario->h >= monstreEtBonus->x + 2))
    {
        return 1;
    }

    else if (mario->x + mario->h >= monstreEtBonus->x + 30)
    {
        return 3;
    }
    else
    {
        return 4;
    }
}

int collisionEntite2(Objet *mario, Objet *monstreEtBonus)
{
    if ((mario->x >= monstreEtBonus->x + monstreEtBonus->l)
    || (mario->x + mario->l <= monstreEtBonus->x)
    || (mario->y >= monstreEtBonus->y + monstreEtBonus->h)
    || (mario->y + mario->h <= monstreEtBonus->y))
    {
        return 0;
    }
    else if (mario->y + mario->h <= monstreEtBonus->y + 10)
    {
        return 2;
    }
    else if ((mario->x + mario->h >= monstreEtBonus->x + 2 && mario->x + mario->h <= monstreEtBonus->x + 14))
    {
        return 1;
    }

    else if ((mario->x + mario->h >= monstreEtBonus->x + 30 && mario->x + mario->h >= monstreEtBonus->x + 18))
    {
        return 3;
    }
    else
    {
        return 4;
    }
}

void initMario(void)
{
    changerAnimation(&mario, "images/M_D_Marche.png");
    mario.direction = DROITE;
    mario.etat = STOP;
    mario.x = 0;
    mario.y = 0;
    mario.l = MARIO_X;
    mario.h = MARIO_Y;
    mario.mort = 0;
    mario.auSol = 0;
    mario.entiteID = 0;
    mario.marioID = 1;

    parametre.nbEntite = 0;
}

void reactualiserMario(void)
{
    if (mario.marioID == 1)
    {
        if (mario.mort == 0)
        {
        mario.vectx = 0;
        mario.h = MARIO_Y;
        mario.vecty += 0.6;
        if (mario.vecty >= 10)
        {
            mario.vecty = 10;
        }
        if (input.gauche == 1)
        {
            mario.vectx -= 4;
            mario.direction = GAUCHE;
            if(mario.etat != G_MARCHE && mario.auSol == 1)
            {
                mario.etat = G_MARCHE;
                changerAnimation(&mario, "images/M_G_Marche.png");
            }
        }
        else if (input.droite == 1)
        {
            mario.vectx += 4;
            mario.direction = DROITE;

            if(mario.etat != D_MARCHE && mario.auSol == 1)
            {
                mario.etat = D_MARCHE;
                changerAnimation(&mario, "images/M_D_Marche.png");
            }
        }
        else if(input.droite == 0 && input.gauche == 0 && mario.auSol == 1)
        {
            if(mario.etat != STOP)
            {
                mario.etat = STOP;
                if(mario.direction == GAUCHE)
                {
                    changerAnimation(&mario, "images/M_G.png");
                }
                else
                {
                    changerAnimation(&mario, "images/M_D.png");
                }
            }
        }
        if (input.saut == 1 && mario.auSol == 1)
        {
            mario.auSol = 0;
            input.saut = 0;
            mario.vecty = -12;
        }
        if(mario.auSol == 0)
        {
            if(mario.direction == DROITE && mario.etat != D_SAUT)
            {
                mario.etat = D_SAUT;
                changerAnimation(&mario, "images/M_D_Saut.png");
            }
            else if(mario.direction == GAUCHE && mario.etat != G_SAUT)
            {
                mario.etat = G_SAUT;
                changerAnimation(&mario, "images/M_G_Saut.png");
            }

        }
        collisionDecor(&mario);
        camera();
        }
        if (mario.mort > 0)
        {
            mario.mort--;
            if (mario.mort == 0)
            {
                parametre.vies--;
                if(parametre.vies < 0)
                {
                    parametre.vies = 0;
                };
                initMario();
                changerCarte();
            }
        }
    }
}

void reactualiserSuperMario(void)
{
    if (mario.marioID == 2)
    {
        if (mario.mort == 0)
        {
        mario.vectx = 0;
        mario.h = 64;
        mario.vecty += 0.6;
        if (mario.vecty >= 10)
        {
            mario.vecty = 10;
        }
        if (input.gauche == 1)
        {
            mario.vectx -= 4;
            mario.direction = GAUCHE;
            if(mario.etat != G_MARCHE && mario.auSol == 1)
            {
                mario.etat = G_MARCHE;
                changerAnimation(&mario, "images/SM_G_Marche.png");
            }
        }
        else if (input.droite == 1)
        {
            mario.vectx += 4;
            mario.direction = DROITE;

            if(mario.etat != D_MARCHE && mario.auSol == 1)
            {
                mario.etat = D_MARCHE;
                changerAnimation(&mario, "images/SM_D_Marche.png");
            }
        }
        else if(input.droite == 0 && input.gauche == 0 && mario.auSol == 1)
        {
            if(mario.etat != STOP)
            {
                mario.etat = STOP;
                if(mario.direction == GAUCHE)
                {
                    changerAnimation(&mario, "images/SM_G.png");
                }
                else
                {
                    changerAnimation(&mario, "images/SM_D.png");
                }
            }
        }
        if (input.saut == 1 && mario.auSol == 1)
        {
            mario.auSol = 0;
            input.saut = 0;
            mario.vecty = -12;
        }
        if(mario.auSol == 0)
        {
            if(mario.direction == DROITE && mario.etat != D_SAUT)
            {
                mario.etat = D_SAUT;
                changerAnimation(&mario, "images/SM_D_Saut.png");
            }
            else if(mario.direction == GAUCHE && mario.etat != G_SAUT)
            {
                mario.etat = G_SAUT;
                changerAnimation(&mario, "images/SM_G_Saut.png");
            }
        }
        collisionDecor(&mario);
        camera();
        }
        if (mario.mort > 0)
        {
            mario.mort--;
            if (mario.mort == 0)
            {
                parametre.vies--;
                if(parametre.vies < 0)
                {
                    parametre.vies = 0;
                }
                initMario();
                changerCarte();
            }
        }
    }
}

void reactualiserFireMario(void)
{
    if (mario.marioID == 3)
    {
        if (mario.mort == 0)
        {
        mario.vectx = 0;
        mario.h = 64;
        mario.vecty += 0.6;
        if (mario.vecty >= 10)
        {
            mario.vecty = 10;
        }
        if (input.gauche == 1)
        {
            mario.vectx -= 4;
            mario.direction = GAUCHE;
            if(mario.etat != G_MARCHE && mario.auSol == 1)
            {
                mario.etat = G_MARCHE;
                changerAnimation(&mario, "images/FM_G_Marche.png");
            }
        }
        else if (input.droite == 1)
        {
            mario.vectx += 4;
            mario.direction = DROITE;
            if(mario.etat != D_MARCHE && mario.auSol == 1)
            {
                mario.etat = D_MARCHE;
                changerAnimation(&mario, "images/FM_D_Marche.png");
            }
        }
        else if(input.droite == 0 && input.gauche == 0 && mario.auSol == 1)
        {
            if(mario.etat != STOP)
            {
                mario.etat = STOP;
                if(mario.direction == GAUCHE)
                {
                    changerAnimation(&mario, "images/FM_G.png");
                }
                else
                {
                    changerAnimation(&mario, "images/FM_D.png");
                }
            }
        }
        if (input.saut == 1 && mario.auSol == 1)
        {
            mario.auSol = 0;
            input.saut = 0;
            mario.vecty = -12;
        }
        if(mario.auSol == 0)
        {
            if(mario.direction == DROITE && mario.etat != D_SAUT)
            {
                mario.etat = D_SAUT;
                changerAnimation(&mario, "images/FM_D_Saut.png");
            }
            else if(mario.direction == GAUCHE && mario.etat != G_SAUT)
            {
                mario.etat = G_SAUT;
                changerAnimation(&mario, "images/FM_G_Saut.png");
            }
        }
        collisionDecor(&mario);
        camera();
    }
    if (mario.mort > 0)
        {
            mario.mort--;
            if (mario.mort == 0)
            {
                parametre.vies--;
                if(parametre.vies < 0)
                {
                    parametre.vies = 0;
                }
                initMario();
                changerCarte();
            }
        }
    }
}

void camera(void)
{
    coordonee.startX = mario.x - (ECRAN_X / 2);
    if (coordonee.startX < 0)
    {
        coordonee.startX = 0;
    }
    else if (coordonee.startX + ECRAN_X >= coordonee.xmax)
    {
        coordonee.startX = coordonee.xmax - ECRAN_X;
    }

    coordonee.startY = mario.y - (ECRAN_Y / 2);
    if (coordonee.startY < 0)
    {
        coordonee.startY = 0;
    }
    else if (coordonee.startY + ECRAN_Y >= coordonee.ymax)
    {
        coordonee.startY = coordonee.ymax - ECRAN_Y;
    }
 }
