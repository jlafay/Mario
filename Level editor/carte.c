#include "carte.h"

void chargerCarte(char *nom)
{
    int x, y;
    FILE *fp;

    fp = fopen(nom, "rb");
    if (fp == NULL)
    {
        printf("Failed to open map %s\n", nom);

        exit(1);
    }

    coordonee.xmax = coordonee.ymax = 0;

    for (y = 0; y < CARTE_Y_MAX; y++)
    {
        for (x = 0; x < CARTE_X_MAX; x++)
        {
            fscanf(fp, "%d", &coordonee.tile[y][x]);

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
    coordonee.xmax = CARTE_X_MAX * TILE;
    coordonee.ymax = CARTE_Y_MAX * TILE;
    coordonee.startX = coordonee.startY = 0;
    fclose(fp);
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

            nbTile = coordonee.tile[coory][coorx];
            yinitiale = nbTile / 10 * TILE;
            xinitiale = nbTile % 10 * TILE;
            drawTile(coordonee.tileSet, x, y, xinitiale, yinitiale);
            coorx++;
        }
        coory++;
    }
    yinitiale = cursor.tileID / 10 * TILE;
    xinitiale = cursor.tileID % 10 * TILE;
    drawTile(coordonee.tileSet, cursor.x, cursor.y, xinitiale, yinitiale);
}

void sauvegarderCarte(char *nom)
{
    int x, y;
    FILE *fp;

    fp = fopen(nom, "wb");
    if (fp == NULL)
    {
        printf("Failed to open map %s\n", nom);
        exit(1);
    }

    for (y=0;y<CARTE_Y_MAX;y++)
    {
        for (x=0;x<CARTE_X_MAX;x++)
        {
            fprintf(fp, "%d ", coordonee.tile[y][x]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}


void reinitialiserCarte(char *nom)
{
    int x, y;
    FILE *fp;

    fp = fopen(nom, "wb+");
    if (fp == NULL)
    {
        printf("Failed to open map %s\n", nom);
        exit(1);
    }

    for (y=0;y<CARTE_Y_MAX;y++)
    {
        for (x=0;x<CARTE_X_MAX;x++)
        {
            fprintf(fp, "0 ");
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}
