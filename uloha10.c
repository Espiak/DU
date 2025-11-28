#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char *argv[])
{

    int x = 0;

    // Inicializace SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Vytvoření okna
    SDL_Window *window = SDL_CreateWindow("Vločky", 700, 300, 500, 500, SDL_WINDOW_SHOWN);

    // Vytvoření kreslítka
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Event event;
    int running = 1;
    int line_x = 100;

    SDL_Surface *image = SDL_LoadBMP("snowflake.bmp");
    // SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    // SDL_FreeSurface(image);


    while (running == 1)
    {
        // Dokud jsou k dispozici nějaké události, ukládej je do proměnné `event`
        while (SDL_PollEvent(&event))
        {
            // Pokud došlo k uzavření okna, nastav proměnnou `running` na `0`
            if (event.type == SDL_QUIT)
            {
                running = 0;
            }
        }
if (event.type == SDL_MOUSEBUTTONUP || event.button.button == SDL_BUTTON_LEFT)
{   printf("Event type: %d\n", event.type);

    printf("pressed\n");
    x += 100;
}


        //printf(" %d ",SDL_MOUSEBUTTONUP);
        // Posuň pozici čáry doprava
        line_x++;

        // backgrund collour
        SDL_SetRenderDrawColor(renderer, 0, x, x, 255);

        // every frame gets new background
        SDL_RenderClear(renderer);

        // colour of item
        SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);

        // Vykresli čáru
        SDL_RenderDrawLine(renderer, line_x, 100, line_x, 500);

        // Zobraz vykreslené prvky na obrazovku
        SDL_RenderPresent(renderer);
    }
    // Uvolnění prostředků
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}