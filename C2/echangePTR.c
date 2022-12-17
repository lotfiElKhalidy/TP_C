#include <stdio.h>

void echangeParAdresse(int * a, int * b)
{
    int c =0;
    c = *a;
    *a = *b;
    *b = c;
}

/* Ça marche pas :( ; D'ailleurs, c'est la raison pour laquelle on a des pointeurs */
void echangeParValeur(int a, int b) 
{                            
    int tmp = 0;                
    tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a = 1,*ptra = &a, b = 2, *ptrb = &b;
    
    /*double d = 22.22, *ptrd = &d;

    printf("L'adresse contenue dans le pointeur est : %p \n", ptrd);
    printf("La valeur pointée est : %f \n", *ptrd);

    *ptrd = *ptrd + 1.11;

    printf("L'adresse contenue dans le pointeur est : %p \n", ptrd);
    printf("La valeur pointée est : %f \n", *ptrd); */   

    // Ce petit morceau de code mache niquel

    printf("a = %d et b = %d \n",*ptra,*ptrb); 

    echangeParAdresse(ptra,ptrb); // C'est un échange de deux variables par adresse

    printf("a = %d et b = %d \n",*ptra,*ptrb);


    return 0;
}