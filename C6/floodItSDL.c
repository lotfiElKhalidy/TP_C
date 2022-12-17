#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

int SDL_exit(const char *);
void afficherEcran(void);

SDL_Renderer *renderer;
SDL_Texture  *avatar;
TTF_Font *font1;

int main(int argc, char *argv[])
{
    SDL_Window   * window;

    int flags = IMG_INIT_JPG|IMG_INIT_PNG, initted = 0;

    // Initialisation graphique 
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        return SDL_exit("Initialisation graphique");
    }

    window = SDL_CreateWindow("SDL2 Programme 0.1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0); 
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED ); 
    initted = IMG_Init(flags);

    if (window == NULL) 
    {
        return SDL_exit("Ouverture de la fenetre");
    }

    if (renderer == NULL)
    {
        return SDL_exit("Ouverture du rendu");
    }

    if((initted&flags) != flags) 
    {
        printf("IMG_Init: Impossible d'initialiser le support des formats JPG et PNG requis!\n");
        printf("IMG_Init: %s\n", IMG_GetError());
        SDL_Quit();
    }

    // Affichage de l'image/ecran
    SDL_Surface *image = NULL;

    image = IMG_Load("loic5.png");
    /* image=SDL_LoadBMP("loic.bmp"); fonction standard de la SDL2 */
    if(!image) 
    {
        printf("IMG_Load: %s\n", IMG_GetError());
        SDL_Quit();
    }

    if (TTF_Init() != 0)
    {
        fprintf(stderr, "Erreur d'initialisation TTF : %s\n", TTF_GetError()); 
        SDL_Quit();
    }

    font1 = TTF_OpenFont("chlorinar.regular.ttf", 72 );

    avatar = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    int running = 1, width, height;
    SDL_Event event;

    while (running) 
    {
        while (SDL_PollEvent(&event))
	    {
		    switch(event.type)
		    {
			    case SDL_WINDOWEVENT:
				    printf("window event\n");
				
                    switch (event.window.event)  
				    {
					    case SDL_WINDOWEVENT_CLOSE:  
						    printf("appui sur la croix\n");	
						    break;
					
                        case SDL_WINDOWEVENT_SIZE_CHANGED:
						    width = event.window.data1;
						    height = event.window.data2;
						    printf("Size : %d%d\n", width, height);
					
                        default:
						    afficherEcran();
				    }   
			        break;
			
                case SDL_MOUSEBUTTONDOWN:
				    printf("Appui :%d %d\n", event.button.x, event.button.y);
				    afficherEcran();
				    break;
			
                case SDL_QUIT : 
				    printf("on quitte\n");    
				    running = 0;
            }
	    SDL_Delay(1);
        } 
    }

    SDL_Delay(5000);
    TTF_CloseFont(font1);
    IMG_Quit();
    if (renderer != NULL)
        SDL_DestroyRenderer(renderer);
    if (window != NULL)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}

void afficherEcran()
{
    SDL_Rect rect;

    int iW, iH;
    SDL_Color couleur  = {0, 0, 255, 255}; //bleu 
    SDL_Surface * surf     = TTF_RenderText_Blended(font1, "", couleur);
    SDL_Texture * texttext = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_QueryTexture(texttext, NULL, NULL, &iW, &iH);
    SDL_RenderCopy(renderer, texttext, NULL, &rect);

    /* couleur de fond : Noir dans ce cas*/
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    if (SDL_SetRenderDrawColor != 0) {
        SDL_exit("Set Renderrer Draw Color");
    }

    SDL_RenderClear(renderer);

    /* dessiner en blanc 
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);

    rect.x = rect.y = 0;
    rect.w = rect.h = 600; // Dimensions du truc 

    SDL_RenderFillRect(renderer, &rect ); // Remplir

    rect.x = 600;
    rect.y = 110;
    rect.w = rect.h = 128;

    SDL_RenderCopy(renderer, avatar, NULL, &rect); 
    /* L'image a ete copiee dans le renderer qui sera plus tard affiche a l'ecran */
    /* afficher à l'ecran */
    SDL_RenderPresent(renderer);

}

int SDL_exit(const char * texte)
{
    fprintf(stderr, "Erreur : %s -> %s\n", texte, SDL_GetError()); // On écrit les erreurs dans un fichier
    exit(EXIT_FAILURE);
    return EXIT_FAILURE;
}