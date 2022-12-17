#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "SDL.h"
#include "commun.h"

void displayString(gdata_t g, char * chaine, int x, int y) 
{
    int iW, iH;
    SDL_Color     couleur  = {0, 0, 255, 255};
    SDL_Surface * surf     = TTF_RenderText_Blended(g.font, chaine, couleur);
    SDL_Texture * text     = SDL_CreateTextureFromSurface(g.renderer, surf);
    SDL_Rect rect;
   

    SDL_QueryTexture(text, NULL, NULL, &iW, &iH);

    rect.x = x;
    rect.y = y;
    rect.w = iW;
    rect.h = iH;

    SDL_RenderCopy(g.renderer, text, NULL, &rect);


}

void displayGraphicalHisto(gdata_t g, histogram_t h) {                          
    char chaine[255];
    int  maxx = 600;
    int  maxy = 400;
    int  i;   
    int  j = maxHisto(h);
  
    SDL_Rect r;
    SDL_SetRenderDrawColor(g.renderer, 255, 255, 255, 255);
    SDL_RenderClear(g.renderer);
    SDL_SetRenderDrawColor(g.renderer, 0, 0, 0, 255);

    for(i=0; i<HISTOSIZE; ++i) {
        r.x = (int)(maxx/22.0*(i+1));
        r.y = maxy-(int)(h[i]/(float)j*300.);
        r.w = 2;
        r.h = (int)(h[i]/(float)j*300.)+3;
        SDL_RenderFillRect(g.renderer, &r);
        
        sprintf(chaine, "%2d", i);
        displayString(g, chaine, (int)(maxx/22.0*(i+1)-4), 420);
        
        if (h[i]>0) {
            sprintf(chaine, "%d", h[i]);
            displayString(g, chaine, (int)(maxx/22.0*(i+1)-4), 75);
        }
        
    }
    
    strcpy(chaine, "Occurences");
    displayString(g, chaine, maxx-100, 50);
    sprintf(chaine, "Notes [%d]", countHisto(h));
    displayString(g, chaine, 10, 445);
    sprintf(chaine, "Moyenne : %f", meanHisto(h));
    displayString(g, chaine, 10, 470);

    SDL_RenderPresent(g.renderer);
}

void displayGraph(histogram_t h) {
    gdata_t        g;
    int graphics = 1;
    int sortie   = 0;
    SDL_Event      event;

    g.window     = 0;
    g.renderer   = 0;
    g.font       = 0;
    g.width      = 600;
    g.height     = 500;


    if (SDL_Init(SDL_INIT_VIDEO) == -1) {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); 
        graphics = 0;
    } else {

        g.window = SDL_CreateWindow("RÃ©partition des notes", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                    g.width, g.height, SDL_WINDOW_SHOWN |  SDL_WINDOW_RESIZABLE); 
    
        if (g.window == 0) {
            fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); 
            graphics = 0; 
        } else {
            g.renderer = SDL_CreateRenderer(g.window, -1, SDL_RENDERER_ACCELERATED ); /* | SDL_RENDERER_PRESENTVSYNC */
            if (g.renderer == 0) {
                fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); 
                graphics = 0;
            } else {
                if (TTF_Init() != 0){
                    fprintf(stderr, "Erreur d'initialisation TTF : %s\n", TTF_GetError()); 
                    graphics = 0;
                } else {
                    g.font = TTF_OpenFont("Arial.ttf", 12 );  

                    if (!g.font) { 
                    	graphics = 0;
                    	fprintf(stderr, "La police ARIAL n'est pas chargee\n"); 
                    } 
                }
            }
        }
    }

    if (graphics==0) {
        if (g.font     != 0) TTF_CloseFont(g.font);
        if (g.renderer != 0) SDL_DestroyRenderer(g.renderer);
        if (g.window   != 0) SDL_DestroyWindow(g.window);
        TTF_Quit();
        SDL_Quit();
        return;
    }    

    while (!sortie) {

        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_WINDOWEVENT:
                    printf("window event\n");
                    switch (event.window.event)  {
                        case SDL_WINDOWEVENT_CLOSE:  
                            printf("appui sur la croix\n");
                            break;
                        case SDL_WINDOWEVENT_SIZE_CHANGED:
                            g.width  = event.window.data1;
                            g.height = event.window.data2;
                            printf("Size : %d %d\n", g.width, g.height);
                        default:
                            displayGraphicalHisto(g, h);
                            printf("evenenent window non pris en compte\n");
                    }   
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    break;
                case SDL_QUIT : 
                    printf("on quitte\n");    
                    sortie = 1;
            }    
        }
        SDL_Delay(1);
    }

    TTF_CloseFont(g.font);
    SDL_DestroyRenderer(g.renderer);
    SDL_DestroyWindow(g.window);
    TTF_Quit();
    SDL_Quit();

}