#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void alocate(int clicks){
    int p = relloc(sizeof(SDL_Rect) * clicks);
}

int main(int argc, char *argv[])
{
    int running = 1;
    int rotacia = 100;
    int x = 0;

    // Inicializace SDL
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Vločky", 700, 300, 500, 500, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
    SDL_Event event;
    SDL_Texture *paint = IMG_LoadTexture(renderer, "snowflake.png");

    
    
    SDL_Rect* Position[5];
    
    SDL_Rect* Position[2] = { 50, 50, 50, 50 };
    Position[2]->w = 20;
    
    int clicks = 0;

    if (paint == NULL)
    {
        printf("bez obrazku");
        return 1;
    }

    while (running == 1)
    {
        
        while (SDL_PollEvent(&event))// Dokud jsou k dispozici nějaké události, ukládej je do proměnné `event`
        {
            
            if (event.type == SDL_QUIT)// Pokud došlo k uzavření okna, nastav proměnnou `running` na `0`
            {
                running = 0;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                SDL_GetMouseState(&position[clicks].x, &position[clicks].y);
                clicks += 1;
                printf("Event type: %d\n", event.type);
                //alocate(clicks);
            }
        }

        rotacia++;
        for(int k = 0;k<5 ;k++ )
        {
            position[k].y++;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);        // backgrund collour
        SDL_RenderClear(renderer);                             // every frame gets new background
        SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);  // colour of item


        SDL_RenderCopyEx(renderer, paint, NULL, &position, rotacia, NULL, x);

        // Zobraz vykreslené prvky na obrazovku
        SDL_RenderPresent(renderer);
    }
    // Uvolnění prostředků
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    for (int i = 0; i < 3; i++) {
    free(Position[i]);
}


    return 0;
}