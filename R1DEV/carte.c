#include "carte.h"

void chargerCarte(char *nom)
{
    int x, y;

    FILE *file;
    file = fopen(nom, "rb");
    if (file == NULL)
    {
        printf("Failed to open map %s\n", nom);
        exit(1);
    }

    coordonee.xmax = 0;
    coordonee.ymax = 0;

    for (y = 0; y < CARTE_Y_MAX; y++)
    {
        for (x = 0; x < CARTE_X_MAX; x++)
        {
            fscanf(file, "%d", &coordonee.tile[y][x]);

            if (coordonee.tile[y][x] > 0)
            {
                if (x > coordonee.xmax)
                {
                    coordonee.xmax = x;
                }
                if (y > coordonee.ymax)
                {
                    coordonee.ymax = y;
                }
            }
        }
    }
    coordonee.xmax = (coordonee.xmax + 1) * TILE;
    coordonee.ymax = (coordonee.ymax + 1) * TILE;

    coordonee.startX = 0;
    coordonee.startY = 0;

    fclose(file);
}

void drawCarte(void)
{
    int x, y, coorx, xa, xb, coory, ya, yb, xinitiale, yinitiale, nbTile;

    coorx = coordonee.startX / TILE;
    xa = (coordonee.startX % TILE) * -1;
    xb = xa + ECRAN_X + (xa == 0 ? 0 : TILE);

    coory = coordonee.startY / TILE;
    ya = (coordonee.startY % TILE) * -1;
    yb = ya + ECRAN_Y + (ya == 0 ? 0 : TILE);

    for (y = ya; y < yb; y += TILE)
    {
        coorx = coordonee.startX / TILE;

        for (x = xa; x < xb; x += TILE)
        {
            if (coordonee.tile[coory][coorx] != 0)
            {
                if (coordonee.tile[coory][coorx] == 10)
                {
                    entite(coorx * TILE, coory * TILE, 1);
                    coordonee.tile[coory][coorx] = 0;
                }
                else if (coordonee.tile[coory][coorx] == 11)
                {
                    entite(coorx * TILE, coory * TILE, 2);
                    coordonee.tile[coory][coorx] = 0;
                }
                else if (coordonee.tile[coory][coorx] == 12)
                {
                    entite(coorx * TILE, coory * TILE, 3);
                    coordonee.tile[coory][coorx] = 0;
                }
                else if (coordonee.tile[coory][coorx] == 13)
                {
                    entite(coorx * TILE, coory * TILE, 4);
                    coordonee.tile[coory][coorx] = 0;
                }
            }
            nbTile = coordonee.tile[coory][coorx];

            yinitiale = nbTile / 10 * TILE;
            xinitiale = nbTile % 10 * TILE;
            drawTile(coordonee.tileSet, x, y, xinitiale, yinitiale);

            coorx++;
        }
        coory++;
    }
}

void collisionDecor(Objet *entite2)
{

    int i, xa, xb, ya, yb;

    entite2->auSol = 0;
    if(entite2->h > TILE)
    {
        i = TILE;
    }
    else
    {
        i = entite2->h;
    }

    for (;;)
    {

        xa = (entite2->x + entite2->vectx) / TILE;
        xb = (entite2->x + entite2->vectx + entite2->l - 1) / TILE;
        ya = (entite2->y) / TILE;
        yb = (entite2->y + i - 1) / TILE;

        if (xa >= 0 && xb < CARTE_X_MAX && ya >= 0 && yb < CARTE_Y_MAX)
        {
            if (entite2->vectx > 0)
            {
                if (coordonee.tile[ya][xb] == 1)
                {
                    coordonee.tile[ya][xb] = 0;
                }
                else if(coordonee.tile[yb][xb] == 1)
                {
                    coordonee.tile[yb][xb] = 0;
                }
                if (coordonee.tile[ya][xb] > 1 || coordonee.tile[yb][xb] > 1)
                {
                    entite2->x = xb * TILE;
                    entite2->x -= entite2->l + 1;
                    entite2->vectx = 0;
                }
            }

            else if (entite2->vectx < 0)
            {
                if (coordonee.tile[ya][xa] == 1)
                {
                    coordonee.tile[ya][xa] = 0;
                }
                else if(coordonee.tile[yb][xa] == 1)
                {
                    coordonee.tile[yb][xa] = 0;
                }

                if (coordonee.tile[ya][xa] > 1 || coordonee.tile[yb][xa] > 1)
                {
                    entite2->x = (xa + 1) * TILE;
                    entite2->vectx = 0;
                }
            }
        }

        if (i == entite2->h)
        {
            break;
        }
        i += TILE;
        if (i > entite2->h)
        {
            i = entite2->h;
        }
    }

    if(entite2->l > TILE)
    {
       i = TILE;
    }
    else
    {
        i = entite2->l;
    }

    for (;;)
    {
        xa = (entite2->x) / TILE;
        xb = (entite2->x + i) / TILE;
        ya = (entite2->y + entite2->vecty) / TILE;
        yb = (entite2->y + entite2->vecty + entite2->h) / TILE;

        if (xa >= 0 && xb < CARTE_X_MAX && ya >= 0 && yb < CARTE_Y_MAX)
        {
            if (entite2->vecty > 0)
            {
                if (coordonee.tile[yb][xa] == 1)
                {
                    coordonee.tile[yb][xa] = 0;
                }
                else if(coordonee.tile[yb][xb] == 1)
                {
                    coordonee.tile[yb][xb] = 0;
                }

                if (coordonee.tile[yb][xa] > 1 || coordonee.tile[yb][xb] > 1)
                {
                    entite2->y = yb * TILE;
                    entite2->y -= entite2->h;
                    entite2->vecty = 0;
                    entite2->auSol = 1;
                }
            }

            else if (entite2->vecty < 0)
            {
                if (coordonee.tile[ya][xa] == 1)
                {
                    coordonee.tile[ya][xa] = 0;
                }
                else if(coordonee.tile[ya][xb] == 1)
                {
                    coordonee.tile[ya][xb] = 0;
                }

                if (coordonee.tile[ya][xa] == 5)
                {
                    coordonee.tile[ya][xa] = 4;
                }
                else if(coordonee.tile[ya][xb] == 5)
                {
                    coordonee.tile[ya][xb] = 4;
                }

                if (coordonee.tile[ya][xa] == 6)
                {
                    coordonee.tile[ya][xa] = 4;
                    entite(xa * TILE, ya * TILE, 7);
                }
                else if(coordonee.tile[ya][xb] == 6)
                {
                    coordonee.tile[ya][xb] = 4;
                    entite(xb * TILE, ya * TILE, 7);
                }

                if (coordonee.tile[ya][xa] == 7)
                {
                    coordonee.tile[ya][xa] = 4;
                    entite(xa * TILE, ya * TILE, 8);
                }
                else if(coordonee.tile[ya][xb] == 7)
                {
                    coordonee.tile[ya][xb] = 4;
                    entite(xb * TILE, ya * TILE, 8);
                }

                if (coordonee.tile[ya][xa] > 1 || coordonee.tile[ya][xb] > 1)
                {
                    entite2->y = (ya + 1) * TILE;
                    entite2->vecty = 0;
                }
            }
        }

        if (i == entite2->l)
        {
            break;
        }
        i += TILE;
        if (i > entite2->l)
        {
            i = entite2->l;
        }
    }
    entite2->x += entite2->vectx;
    entite2->y += entite2->vecty;

    if (entite2->x < 0)
    {
        entite2->x = 0;
    }
    else if (entite2->x + entite2->l >= coordonee.xmax)
    {
        entite2->x = coordonee.xmax - entite2->l - 1;
    }
    if (entite2->y > coordonee.ymax)
    {
        entite2->mort = 60;
    }
}

void changerCarte(void)
{
    char file[200];
    sprintf(file, "cartes/1-%d.txt", parametre.niveau );
    chargerCarte(file);

    if(coordonee.tileSet != NULL)
    {
        SDL_FreeSurface(coordonee.tileSet);
    }
    sprintf(file, "images/tileset.png", parametre.niveau );
    coordonee.tileSet = loadImage(file);
}
