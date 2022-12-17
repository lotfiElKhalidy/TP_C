#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ( int argc, char** argv )
{
    int nombreMystere = 0, nombreEntre = 0, nombreCoups = 0, rejouer = 1, mode = 1, MAX = 0, nivDifficulte = 1;
    const int MIN = 1;

    // Génération du nombre aléatoire

    srand(time(NULL));

    /* La boucle du programme. Elle se répète tant que l'utilisateur ne souhaite pas encore quitter le jeu */

    printf("=== Jeu Plus Ou Moins ===\n\n");

    while (rejouer)
    {
        // On choisit le niveau de difficulté 
        printf("Choisissez le niveau de difficulté :\n\n 1 = entre 1 et 100 ;\n 2 = entre 1 et 1000 ;\n 3 = entre 1 et 10000.\n\n");
        scanf("%d", &nivDifficulte);

        if (nivDifficulte == 1)
            MAX = 100;
        else if (nivDifficulte == 2)
            MAX = 1000;
        else if (nivDifficulte == 3)
            MAX = 10000;
        else 
            printf("Niveau non reconnu. Le niveau 1 est choisi par défaut (entre 1 et 100).\n");
        
        // On choisit le mode dans lequel on souhaite jouer 
        printf("Choisissez votre mode :\n");
        printf("Tapez 1 pour mode un joueur\n      2 pour mode deux joueurs\n\n");
        scanf("%d",&mode);

        if (mode == 1)
        {
            nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
        }
        else if (mode == 2)
        {
            printf("Joueur 1, choisissez un nombre entre %d et %d sans le montrer au Joueur 2\n",MIN,MAX);
            scanf("%d",&nombreMystere);
        }
        else
        {
            printf("Mode non reconnu. Le mode 1 est choisi par défaut.\n");
        }
        
        /* La seconde boucle du programme. Elle se répète tant que l'utilisateur n'a pas trouvé le nombre mystère */
        do
        {
            // On demande le nombre et on incrémente le nombre de coups une seule fois
            printf("Quel est le nombre ? ");
            scanf("%d", &nombreEntre);
            nombreCoups++;

            // On compare le nombre entré avec le nombre mystère

            if (nombreMystere > nombreEntre)
                printf("C'est plus !\n\n");
            else if (nombreMystere < nombreEntre)
                printf("C'est moins !\n\n");
            else
            {
                printf ("Bravo, vous avez trouve le nombre mystere en %d coups !!!\n\n",nombreCoups);
            
            // On demande à l'utilisateur s'il veut rejouer ou non

                printf("Est-ce que vous voulez quitter ?\n");
                printf("Si oui, tapez 0.\n");
                scanf("%d",&rejouer);
            }
        } while (nombreEntre != nombreMystere);
    }
    return 0;
}

/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define MIN 0

int main()
{
    srand(time(NULL));
    int nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
    int nombrePropose;

    printf("Deviner c'est quoi le nombre : ");
    scanf("%d",&nombrePropose);

    while (nombreMystere != nombrePropose)
    {
        printf("Deviner c'est quoi le nombre : ");
        scanf("%d",&nombrePropose);

        if (nombrePropose > nombreMystere)
        {
            printf("C'est moins !\n\n");
        }
        else if (nombrePropose < nombreMystere)
        {
            printf("C'est plus !\n\n");
        }
    }

    printf("Bravo, vous avez trouve le nombre mystere !!!\n\n");
       
    return 0;
}
 Après avoir écrit le code; je me suis rendu compte que le fait d'utiliser
do..while serait plus bénéfique pour supprimer les deux premières instructions ; Clean Code

We didn't respect the boundaries tough !!! */