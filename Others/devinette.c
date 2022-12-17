#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define M 5

int main()
{
    char texte[] = "Donner des nombres pour remplir le tableau";
    long unsigned int i;
    int j,k;
    int tab[M] = {0};
    for (i=0; i<strlen(texte); i++)
    {
        if (texte[i]>='a' && texte[i]<='z')
        {
            texte[i] = texte[i] -'a' +'A';
        }
    }
    printf("%s\n",texte);
    for (j=0; j<M; j++)
    {
        scanf("%d", &tab[j]);
    }
    printf("les valeurs que vous avez saisi sont :\n");
    for (k=0; k<M; k++)
    {
        printf("%d\n",tab[k]);
    }
    return 0;
}#include <stdio.h>

#define N 9

void inverser(char texte[])
{
    char resultat[N] = "*********";
    int i; 
    resultat[N-1] = texte[0];
    for (i=N-1; i>0; i--)
    {
        resultat[N-1-i] = texte[i];
    }
    printf("L'inverse du mot que vous avez proposé est : %s\n",resultat);
}

int main()
{
    char texte[] = "inversion";
    inverser(texte);
    return 0;
}
