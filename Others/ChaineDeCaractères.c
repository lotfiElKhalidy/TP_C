#include <stdio.h>

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
void convertir(int nb, char r[100])
{
    int 
    while (nb/2 != 0)
    {

    }
}