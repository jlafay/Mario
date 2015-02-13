#include "draw.h"

void drawImg(SDL_Surface *img, int x, int y)
{
    SDL_Rect finale;

    finale.x = x;
    finale.y = y;
    finale.w = img->w;
    finale.h = img->h;

    SDL_BlitSurface(img, NULL, parametre.ecran, &finale);
}


SDL_Surface *loadImage(char *nom)
{
    SDL_Surface *temp = IMG_Load(nom);
    SDL_Surface *img;

    if (temp == NULL)
    {
        printf("Failed to load image %s\n", nom);
        return NULL;
    }

    SDL_SetColorKey(temp, (SDL_SRCCOLORKEY | SDL_RLEACCEL), SDL_MapRGB(temp->format, 255, 0, 220));

    img = SDL_DisplayFormat(temp);

    SDL_FreeSurface(temp);

    if (img == NULL)
    {
        printf("Failed to convert image %s to native format\n", nom);
        return NULL;
    }
    return img;
}



void cfgFrame(unsigned int frameLimit)
{
    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }
    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }
    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}

void drawTile(SDL_Surface *img, int finalex, int finaley, int initialex, int initialey)
{
    SDL_Rect finale;

    finale.x = finalex;
    finale.y = finaley;
    finale.w = TILE;
    finale.h = TILE;

    SDL_Rect initiale;

    initiale.x = initialex;
    initiale.y = initialey;
    initiale.w = TILE;
    initiale.h = TILE;

    SDL_BlitSurface(img, &initiale, parametre.ecran, &finale);
}

void draw(void)
{
    drawImg(coordonee.background, 0, 0);
    drawCarte();
    SDL_Flip(parametre.ecran);
    SDL_Delay(1);
}
