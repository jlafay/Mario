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
    parametre.ecran = SDL_SetVideoMode(ECRAN_X, ECRAN_Y, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);

    SDL_WM_SetCaption("145866_R1DEV_Mario", NULL);

    initMario();

    coordonee.background = loadImage("images/bg.jpg");

    parametre.niveau = 1;
    changerCarte();
    parametre.vies = 1;

    atexit(cleanup);

    continuer = 1;
    while (continuer == 1)
    {
        getInput();

        if (mario.marioID == 1)
        {
            reactualiserMario();
        }
        if (mario.marioID == 2)
        {
            reactualiserSuperMario();
        }
        if (mario.marioID == 3)
        {
            reactualiserFireMario();
        }
        reactualiserEntite();

        draw();
        cfgFrame(frameLimit);
        frameLimit = SDL_GetTicks() + 16;
    }
    exit(0);
}

void cleanup()
{
    int i;

    if (coordonee.background != NULL)
    {
        SDL_FreeSurface(coordonee.background);
    }

    if (coordonee.tileSet != NULL)
    {
        SDL_FreeSurface(coordonee.tileSet);
    }

    if (mario.sprite != NULL)
    {
        SDL_FreeSurface(mario.sprite);
    }

    for(i = 0 ; i < 20 ; i++)
    {
        if (monstreEtBonus[i].sprite != NULL)
        {
            SDL_FreeSurface(monstreEtBonus[i].sprite);
        }
    }
    SDL_Quit();
}

void getInput()
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

                    case SDLK_SPACE:
                        input.saut = 1;
                    break;

                    case SDLK_a:
                        input.gauche = 1;
                    break;

                    case SDLK_d:
                        input.droite = 1;
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

                    default:
                    break;
                }
            break;
        }
    }
 }
