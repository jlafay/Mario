 #include "main.h"

int main( int argc, char *argv[ ] )
{
    unsigned int frameLimit = SDL_GetTicks() + 16;
    int continuer;

    if (SDL_Init(SDL_INIT_VIDEO ) < 0)
    {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    parametre.ecran = SDL_SetVideoMode(ECRAN_X, ECRAN_Y, 0,SDL_HWPALETTE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Editeur", NULL);
    coordonee.background = loadImage("images/bg.jpg");
    coordonee.tileSet = loadImage("images/tileset.png");
    chargerCarte("cartes/1-1.txt");
    atexit(cleanup);

    continuer = 1;
    while (continuer == 1)
    {
        getInput();
        rafraichir();
        draw();
        cfgFrame(frameLimit);
        frameLimit = SDL_GetTicks() + 16;
    }
    exit(0);
}

void cleanup()
{
    if (coordonee.background != NULL)
    {
        SDL_FreeSurface(coordonee.background);
    }
    if (coordonee.tileSet != NULL)
    {
        SDL_FreeSurface(coordonee.tileSet);
    }
    SDL_Quit();
}

void getInput(void)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                exit(0);
            break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        exit(0);
                    break;

                    case SDLK_a:
                        input.gauche = 1;
                    break;

                    case SDLK_d:
                        input.droite = 1;
                    break;

                    case SDLK_s:
                        input.bas = 1;
                    break;

                    case SDLK_w:
                        input.haut = 1;
                    break;

                    case SDLK_SPACE:
                        input.sauvegarder = 1;
                    break;

                    case SDLK_l:
                        input.charger = 1;
                    break;

                    case SDLK_DELETE:
                        input.reinitialiser = 1;
                    break;

                    default:
                    break;
                }
            break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                    case SDLK_a:
                        input.gauche = 0;
                    break;

                    case SDLK_d:
                        input.droite = 0;
                    break;

                    case SDLK_s:
                        input.bas = 0;
                    break;

                    case SDLK_w:
                        input.haut = 0;
                    break;

                    default:
                    break;
                }
            break;

            case SDL_MOUSEBUTTONDOWN:
                switch(event.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        input.ajouter = 1;
                   break;

                    case SDL_BUTTON_MIDDLE:
                        input.supprimer = 1;
                   break;

                    case SDL_BUTTON_RIGHT:
                        input.copier = 1;
                   break;

                    case SDL_BUTTON_WHEELUP:
                        input.suivant = 1;
                   break;

                    case SDL_BUTTON_WHEELDOWN:
                        input.precedent = 1;
                    break;

                    default:
                    break;
                }
           break;

            case SDL_MOUSEBUTTONUP:
                switch(event.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        input.ajouter = 0;
                    break;

                    case SDL_BUTTON_MIDDLE:
                        input.supprimer = 0;
                    break;

                    default:
                    break;
                }
            break;
        }
    }

    SDL_GetMouseState(&input.mouseX, &input.mouseY);

    input.mouseX /= TILE;
    input.mouseY /= TILE;
    input.mouseX *= TILE;
    input.mouseY *= TILE;
}

void rafraichir(void)
{
    cursor.x = input.mouseX;
    cursor.y = input.mouseY;

    if (input.gauche == 1)
    {
        coordonee.startX -= TILE;
        if (coordonee.startX < 0)
        {
            coordonee.startX = 0;
        }
    }
    else if (input.droite == 1)
    {
        coordonee.startX += TILE;
        if (coordonee.startX + ECRAN_X >= coordonee.xmax)
        {
            coordonee.startX = coordonee.xmax - ECRAN_X;
        }
    }
    if (input.haut == 1)
    {
        coordonee.startY -= TILE;
        if (coordonee.startY < 0)
        {
            coordonee.startY = 0;
        }
    }

    else if (input.bas == 1)
    {
        coordonee.startY += TILE;
        if (coordonee.startY + ECRAN_Y >= coordonee.ymax)
        {
            coordonee.startY = coordonee.ymax - ECRAN_Y;
        }
    }
    if (input.ajouter == 1)
    {

        coordonee.tile[(coordonee.startY + cursor.y) / TILE][(coordonee.startX + cursor.x) / TILE] = cursor.tileID;

    }
    else if (input.supprimer == 1)
    {

        coordonee.tile[(coordonee.startY + cursor.y) / TILE][(coordonee.startX + cursor.x) / TILE] = 0;

        cursor.tileID = 0;
    }
    if (input.precedent == 1)
    {
        cursor.tileID--;

        if (cursor.tileID < 0)
        {
            cursor.tileID = TILE_MAX;
        }
        else if (cursor.tileID > TILE_MAX)
        {
            cursor.tileID = 0;
        }
        input.precedent = 0;
    }
    if (input.suivant == 1)
    {
        cursor.tileID++;

        if (cursor.tileID < 0)
        {
            cursor.tileID = TILE_MAX - 1;
        }
        else if (cursor.tileID > TILE_MAX)
        {
            cursor.tileID = 0;
        }
        input.suivant = 0;
    }

    if (input.copier == 1)
    {
        cursor.tileID = coordonee.tile[(coordonee.startY + cursor.y) / TILE] [(coordonee.startX + cursor.x) / TILE];
        input.copier = 0;
    }

    if (input.reinitialiser == 1)
    {
        reinitialiserCarte("cartes/1-1.txt");
        chargerCarte("cartes/1-1.txt");
        input.reinitialiser = 0;
    }

    if (input.sauvegarder == 1)
    {
        sauvegarderCarte("cartes/1-1.txt");
        input.sauvegarder = 0;
    }

    if (input.charger == 1)
    {
        chargerCarte("cartes/1-1.txt");
        input.charger = 0;
    }

    if (input.gauche == 1 || input.droite == 1 || input.haut == 1 || input.bas == 1)
    {
        SDL_Delay(30);
    }

}
