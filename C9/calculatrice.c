#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calculatrice.h"
//#include "tests_calcul.c"

typedef enum ope 
{
    NONE = -1, ID , SIN, COS, LOG, EXP
} OP;

const char * OPER_NAMES[] = { "x\n", "sin(x)\n", "cos(x)\n", "log(x)\n", "exp(x)\n", NULL };

int main() 
{
    int indice;
    double borne_inf, borne_sup, delta;
    FILE * fichier = NULL;
    char chaine[25];

    /*printf("%d\n",identification("exp(x)")); 
    printf("%f\n",evalf(10.0,identification("x"))); 
    printf("%f\n",evalf(0.0,identification("sin(x)")));
    printf("%f\n",evalf(0.0,identification("cos(x)")));
    printf("%f\n",evalf(1.0,identification("log(x)")));
    printf("%f\n",evalf(0.0,identification("exp(x)")));
    calcul(0.0, 10.0, 1.0, 1);
    RUN_TEST_GROUP(calculatrice);*/

    printf("\nDonnez la fonction que vous souhiatez utiliser :\n");
    printf("x, sin(x), cos(x), log(x), exp(x)\n");
    fgets(chaine, 25, stdin);
    
    //scanf("%s", chaine);
    
    indice = identification(chaine);

    if (indice == -1)
    {
        printf("Erreur : indice invalide\n");
        exit(0);
    }
    else
    {
        printf("Donnez la borne inférieure de l'intervalle :\n");
        fgets(chaine, 25, stdin);
        borne_inf = atoi(chaine);

        printf("Donnez la borne supérieure de l'intervalle :\n");
        fgets(chaine, 25, stdin);
        borne_sup = atof(chaine);

        //scanf("%lf", &borne_inf); // double --> %lf !!!
        //scanf("%lf", &borne_sup);

        if (borne_inf > borne_sup)
        {
            printf("Erreur : la borne inf doit etre inférieure à la borne sup\n");
            exit(0);
        }
        else
        {
            printf("Donnez le pas de progression :\n");
            fgets(chaine, 25, stdin);
            delta = atof(chaine);
            
            //scanf("%lf", &delta);

            fichier = calcul(borne_inf, borne_sup, delta, indice);
        } 

    }
    return 0;
}

int identification(char * chaine)
{
    int i=0;

    while (OPER_NAMES[i] != NULL)
    {
        if (!strcmp(OPER_NAMES[i],chaine))
        {
            return i;
        }
        i++;
    }
    return -1;
}

/*int identification(char * chaine)
{
    int i=0, j=0, feedback;

    while (OPER_NAMES[i] != NULL)
    {
        while (OPER_NAMES[i][j] != '\0' || feedback != -1)
        {
            if (*(OPER_NAMES[i]+j) != *(chaine+j)) 
            {
                feedback = -1;
            }
            else
            {
                j++;
            }
        }
        i++;
    }
    return feedback;
}*/

double evalf(double valeur, int indice)
{
    switch(indice)
    {
        case 0:
            return valeur;
            break;
        case 1:
            return sin(valeur);
            break;
        case 2:
            return cos(valeur);
            break;
        case 3:
            return log(valeur);
            break;
        case 4:
            return exp(valeur);
            break;
        default: 
            printf("Erreur : L'indice entré est invalide\n");
            break;
    }
    return 0;
}

FILE * calcul(double borne_min, double borne_max, double delta, int indice)
{
    double compteur = borne_min;
    FILE * fichier = NULL;

    fichier = fopen("fichierTest.txt","r+"); // Mode lecture/écriture
    
    if (fichier)
    {
        while (compteur <= borne_max)
        {
            fprintf(fichier,"%f --> %f\n", compteur, evalf(compteur,indice));
            compteur += delta;
        }
        fclose(fichier);
    }
    return fichier;
}