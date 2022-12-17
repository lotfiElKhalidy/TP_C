#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

void SDL_exit(const char *);
void pause(void);

int main()
{
    SDL_Window   * window;

    // Initialisation graphique 
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        SDL_exit("Initialisation graphique");
    }

    window = SDL_CreateWindow("SDL2 Programme 0.1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0); 
    if (window == 0) {
        SDL_exit("Ouverture de la fenetre");
    }

    SDL_Surface *image = NULL;
    image = IMG_Load("loic5.png");
    if (!image) {
        printf("IMG_Load: %s\n", IMG_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    pause();
ù,9bÙ²
    SDL_Quit();

    return EXIT_SUCCESS;
    }

void SDL_exit(const char * texte)
{
    fprintf(stderr, "Erreur : %s -> %s\n", texte, SDL_GetError()); // On écrit les erreurs dans un fichier
    SDL_Quit();
    exit(EXIT_FAILURE);
}

void pause() { 
    int continuer = 1;
    SDL_Event event; 
     
    while (continuer) 
    { 
        SDL_WaitEvent(&event); 
        switch(event.type) 
        { 
            case SDL_QUIT: 
                continuer = 0; 
        } 
    } 
}