#include <stdio.h>

#define N 5

void afficher_tableau()
{
    int tab[N]={0};
    int i;
    for (i=0 ; i<N ; i++)
    {
        printf("%d\n",tab[i]);
    }
}

void maximum(int tab[])
{
    int i, max = 0;
    for (i=0 ; i<N ; i++)
    {
        if (max<tab[i])
        {
            max=tab[i];
        }
    }
    printf("Le maximum de ce tableau est : %d\n",max);
}
void minimum(int tab[])
{
    int i, min = 0;
    for (i=0 ; i<N ; i++)
    {
        if (min>tab[i])
        {
            min=tab[i];
        }
    }
    printf("Le minimum de ce tableau est : %d\n",min);
}
void moyenne(int tab[])
{
    int moyenne = 0;
    int i;
    for (i=0 ; i<N ; i++)
    {
        moyenne += tab[i];
    }
    moyenne /= N;
    printf("La moyenne est : %d\n",moyenne);
}
int main()
{
    int tab[5] = {78,90876,87,97,4365};
    maximum(tab);
    minimum(tab); //?????   
    moyenne(tab);
    return 0;
}

