#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int tailleMot(char mot[]);
void initTableau(int *tableau, int taille);
void afficherLettresDevoiles(int *tableau, int taille, char mot[]);
int rechercheLettre(char lettre, char mot[], int *tableau);
int gagne(int *tableau, int taille);

int main()
{
    char lettre = 0; // Stocke la lettre proposée par l'utilisateur (retour du scanf)
    char motSecret[] = "ROUGE"; // C'est le mot à trouver
    int coupsRestants = 10, taille = tailleMot(motSecret), *LettreTrouvee = NULL; // Compteur de coups restants (0 = mort)
    int search;
    printf("Bienvenue dans le Pendu !\n");
    //printf("%s contient %d lettres\n",motSecret, tailleMot(motSecret));

    LettreTrouvee = (int *) malloc(taille*sizeof(int));

    if (LettreTrouvee == NULL)
    {
        printf("Erreur lors de l'allocation de la mémoire");
        exit(0);
    }
    else    
    {
        initTableau(LettreTrouvee, taille);

        while (coupsRestants > 0 && !gagne(LettreTrouvee, taille))
        {
            printf("\n Il vous reste %d coups a jouer\n", coupsRestants);
            printf("Quel est le mot secret ? ");
            afficherLettresDevoiles(LettreTrouvee, taille, motSecret);
            printf("\nProposez une lettre (en majuscules s.v.p): ");
            scanf("%c", &lettre);
            search = rechercheLettre(lettre, motSecret, LettreTrouvee);
            coupsRestants--;
            /*if (search == 0)
            {
                coupsRestants--;
            }*/
        }

        if (gagne(LettreTrouvee, taille))
        {
            printf("\n\nGagne ! Le mot secret etait bien : %s", motSecret);
        }
        else
        {
            printf("\n\nPerdu ! Le mot secret etait : %s", motSecret);
        }

        free(LettreTrouvee);
    }
    return 0;

}

int tailleMot(char mot[])
{
    int compteur = 0;

    while (*(mot+compteur) != '\0')
    {  
        compteur++;
    }
    return compteur;
}

void initTableau(int *tableau, int taille)
{  
    for (int i=0; i<taille; i++)
    {  
        *(tableau+i) = 0;
    }    
}

void afficherLettresDevoiles(int *tableau, int taille, char mot[])
{
    for (int i=0; i<taille; i++)
    {
        if (*(tableau+i) == 0)
        {
            printf("*");
        }
        else
        {
            printf("%c",mot[i]);
        }
    }   
}

int rechercheLettre(char lettre, char mot[], int *tableau)
{
    int resultatRecherche = 0;

    for (int i=0; mot[i] != '\0'; +i++)
    {
        if (mot[i] == lettre)
        {
            *(tableau+i) = 1;
            resultatRecherche = 1;
        }
    }
    return resultatRecherche;
}

int gagne(int *tableau, int taille)
{
    int resultatFinal = 1;

    for (int i=0; i<taille; i++)
    {  
        if (*(tableau+i) == 0)
        {
            resultatFinal = 0;
        } 
    }
    return resultatFinal;    
}  
