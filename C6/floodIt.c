#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COULEURS 5
#define TAILLE 12

void initialiser(int tableau[TAILLE][TAILLE])
{
    int i,j;
    srand(time (NULL));

    for (i=0; i<TAILLE; ++i)
    {
        for (j=0; j<TAILLE; ++j)
        {
            tableau[i][j] = rand() % 5;
        }
    }
}

void afficherGrille(int grille[TAILLE][TAILLE])
{
    int i,j;

    for (i=0; i<TAILLE; ++i)
    {
        for (j=0; j<TAILLE; ++j)
        {
    
            printf(" %d |",grille[i][j]);
        }
        printf("\n");
    }
}

int fin(int grille[TAILLE][TAILLE])
{
    int i, j, remplissage = 1, color_test = grille[0][0];

    for (i=0; i<TAILLE; ++i)
    {
        for (j=0; j<TAILLE; ++j)
        {
            if (grille[i][j] != color_test)
            {
                remplissage = 0;
            }       
        }
    }
    return remplissage;
}

void remplir(int grille[TAILLE][TAILLE], int color_init, int new_color, int i, int j)
{
    if(i<0 || i>=TAILLE || j<0 || j>=TAILLE)
    {
       printf("Indices invalides\n"); 
    }
    else
    {
        grille[i][j] = new_color;

        if (i+1 < TAILLE && grille[i+1][j] == color_init)
        {
           remplir(grille,color_init,new_color,i+1,j);
        }
        if (i-1 > 0 && grille[i-1][j] == color_init)
        {
           remplir(grille,color_init,new_color,i-1,j);
        }
        if (j+1 < TAILLE && grille[i][j+1] == color_init)
        {
            remplir(grille,color_init,new_color,i,j+1);
        }
        if (j-1 > 0 && grille[i][j-1] == color_init)
        {
            remplir(grille,color_init,new_color,i,j-1);
        } 
    }     
}

int main()
{
    int couleur, tentative = 0, grille[TAILLE][TAILLE], res ;

    initialiser(grille);
    afficherGrille(grille);
    res = fin(grille);

    while (res != 1 || tentative <= 22)
    {
        printf("Donner une couleur (numéro compris entre 0 et %d)\n",COULEURS);
        printf("Sinon, Taper 999 pour sortir.\n");
        scanf("%d",&couleur);

        if (couleur == 999)
        {
            break;
        }
        else
        {
            if ((couleur >= 0 || couleur <= COULEURS) && couleur != grille[0][0])
            {
                remplir(grille, grille[0][0], couleur, 0, 0);
            }
            else
            {
                printf("COuleur invalide.\n");
            }
        }

        afficherGrille(grille);
        res = fin(grille);
        tentative++;          
    }

    return 0;
}