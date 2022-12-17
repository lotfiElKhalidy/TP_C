#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "ddd.h"

int main(int argc, char* argv[])
{
    char lettre = 0; // Stocke la lettre proposée par l'utilisateur (retour du scanf)
    char motSecret[] = "ROUGE"; // C'est le mot à trouver
    int coupsRestants = 10; // Compteur de coups restants (0 = mort)
    int nombreLettres = tailleMot(motSecret);
    int *lettreTrouvee = NULL;// Tableau de booléens. Chaque case correspond à une lettre du mot secret. 0 = lettre non trouvée, 1 = lettre trouvée //Q1
    lettreTrouvee = malloc(nombreLettres * sizeof(int)); //Q2
    initTableau(lettreTrouvee, nombreLettres); //Q3

    printf("Bienvenue dans le Pendu !\n\n");
    
    while (coupsRestants > 0 && !gagne(lettreTrouvee, nombreLettres))
    {
        printf("\n\nIl vous reste %d coups a jouer", coupsRestants);
        printf("\nQuel est le mot secret ? ");

        /* On affiche le mot secret en masquant les lettres non trouvées
                Exemple : *A**ON */
        for (int i = 0 ; i < nombreLettres ; i++)
        {
            if (lettreTrouvee[i])
                printf("%c", motSecret[i]);
            else
                printf("*");
        }
        
        printf("\nProposez une lettre : ");
        lettre = lireCaractere();
        
        // Si ce n'était PAS la bonne lettre
        if (!rechercheLettre(lettre, motSecret, lettreTrouvee))
        {
            coupsRestants--; // On enlève un coup au joueur
        }
    }

    if (gagne(lettreTrouvee, nombreLettres))
        printf("\n\nGagne ! Le mot secret etait bien : %s\n", motSecret);
    else
        printf("\n\nPerdu ! Le mot secret etait : %s \n", motSecret);

    return 0;
}

int tailleMot(char motSecret[])
{
    int nombreLettre = 0;
    for(int i = 0; motSecret[i] != '\0'; i++)
    {
        nombreLettre++;
    }
    return nombreLettre;
}