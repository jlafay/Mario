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
        printf("Failed to load img %s\n", nom);
        return NULL;
    }
    SDL_SetColorKey(temp, (SDL_SRCCOLORKEY | SDL_RLEACCEL), SDL_MapRGB(temp->format, 255, 0, 220));
    img = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);

    if (img == NULL)
    {
        printf("Failed to convert img %s to native format\n", nom);
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

void drawEntite(Objet *entite2)
{
    if (entite2->frameTimer <= 0)
    {
        entite2->frameTimer = TEMPS_FRAMES;
        entite2->frameNumber++;
        if(entite2->frameNumber >= entite2->sprite->w / entite2->l)
        {
            entite2->frameNumber = 0;
        }
    }
    else
    {
        entite2->frameTimer--;
    }
    SDL_Rect finale;
    finale.x = entite2->x - coordonee.startX;
    finale.y = entite2->y - coordonee.startY;
    finale.w = entite2->l;
    finale.h = entite2->h;

    SDL_Rect initiale;
    initiale.x = entite2->frameNumber * entite2->l;
    initiale.y = 0;
    initiale.w = entite2->l;
    initiale.h = entite2->h;

    SDL_BlitSurface(entite2->sprite, &initiale, parametre.ecran, &finale);
}

void changerAnimation(Objet *entite2, char *nom)
{
    if (entite2->sprite != NULL)
    {
        SDL_FreeSurface(entite2->sprite);
    }
    entite2->sprite = loadImage(nom);
    entite2->frameNumber = 0;
    entite2->frameTimer = TEMPS_FRAMES;
}

void draw(void)
{
    int i;
    drawImg(coordonee.background, 0, 0);
    drawCarte();
    drawEntite(&mario);
    for(i = 0 ; i < parametre.nbEntite ; i++)
    {
        drawEntite(&monstreEtBonus[i]);
    }
    SDL_Flip(parametre.ecran);
    SDL_Delay(1);
}
