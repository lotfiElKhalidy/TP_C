#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COULEURS 5
#define TAILLE 12
#define ROUGE   "\033[31m" 
#define VERT   "\033[32m" 
#define JAUNE  "\033[33m" 
#define BLEU  "\033[34m" 
#define VIOLET   "\033[35m" 
#define BLANC   "\033[37m" 
//#define RESET "\033[0m" 

char couleurs[][6] = {ROUGE, VERT, JAUNE, BLEU, VIOLET, BLANC};

void initialiser(int tableau[TAILLE][TAILLE])
{
    srand(time (NULL));

    for (int i=0; i<TAILLE; ++i)
    {
        for (int j=0; j<TAILLE; ++j)
        {
            tableau[i][j] = rand() % 6; // Pour générer des nombres entiers entre 0 et 5
        }
    }
}

void afficherGrille(int grille[TAILLE][TAILLE])
{
    printf("\n\n");

    for (int k=0; k<6; k++)
    { 
        printf("%s\u25A0 %d ||    ",couleurs[k],k);
    }

    printf("\n\n");
    //printf("%s----------------------------\n",couleurs[rand() % 6]);

    for (int i=0; i<TAILLE; ++i)
    {
        //printf("%s|    ", couleurs[rand() % 6]);
        for (int j=0; j<TAILLE; ++j)
        {
            printf("%s\u25A0    ", couleurs[grille[i][j]]);
            //printf(" %d |",grille[i][j]);
        }
        //printf("%s    |\n", couleurs[rand() % 6]);
        printf("\n\n");
    }
    //printf("%s----------------------------\n",couleus[rand() % 6]);
}

int fin(int grille[TAILLE][TAILLE])
{
    int remplissage = 1, color_test = grille[0][0];

    for (int i=0; i<TAILLE; ++i)
    {
        for (int j=0; j<TAILLE; ++j)
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
    int couleur, tentative = 0, grille[TAILLE][TAILLE];

    printf("\n\t\t=== Jeu Flood It ===\n");

    initialiser(grille);
    afficherGrille(grille);

    while (fin(grille) != 1 && tentative < 23)
    {
        //printf("%sVeuillez saisir une couleur\n", couleurs[rand() % 6]);
        printf("\nDonner une couleur (numéro compris entre 0 et %d)\n",COULEURS);
        printf("\tSinon, Taper 999 pour sortir.\n");
        scanf("%d",&couleur);

        if (couleur == 999)
        {
            printf("\n\t À bientot -_- \n");
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
                printf("Couleur invalide.\n");
            }
        }

        afficherGrille(grille);
        tentative++;        
        printf("\n Il vous reste %d coups !!\n",23-tentative);  
    }

    if (fin(grille))
    {
        printf("Félicitations. Vous avez gagné !!!!\n");
    }

    return 0;
}