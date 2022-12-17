#include <stdio.h>

void echange(char * a, char * b);

int main()
{
    int i = 9765, *ptri = &i; // ptri est un pointeur qui stocke l'adresse de i
    char c1 = '1', *ptrc1 = &c1; // ptrc1 est un pointeur qui stocke l'adresse de c1
    char c2 = '2', *ptrc2 = &c2; // ptrc2 est un pointeur qui stocke l'adresse de c2
    double d = 9.33, *ptrd = &d; // ptrd est un pointeur qui stocke l'adresse de d
    
    // L'adresse contenue dans le pointeur %p ----> ptr 
    printf("cm(ptrd) = %p \n", ptrd);

    // La valeur pointée (dont l'adresse est contenue dans le pointeur) %i,d,f,c ---> *ptr
    printf("cm(cm(ptrd)) = %f \n", *ptrd);
    
    // Valeur pointée
    printf("*ptri = %d et *ptrc1 = %c \n", *ptri, *ptrc1);

    (*ptri)++; // Pour incrémenter la valeur de i 
    //(*ptrc1)++; // Comment itérer un char ????

    // Il s'avère que dans le cas de l'incrémentation par 1, le truc ne marche pas sans parenthèses

    *ptrd = *ptrd + 2; // Incrémentation de d à partir de ptrd

    printf("\n");
    printf("nouv_ptri = %u \n et nouv_ptrc1 = %d \n   et nouv_ptrd = %f\n", *ptri, *ptrc1, *ptrd);

    printf("\n");

    printf("c1 = %c et c2 = %c \n",c1,c2);

    printf("\n");
    echange (ptrc1,ptrc2);

    printf("c1 = %c et c2 = %c \n",c1,c2);

    return 0;
}

void echange(char * a, char * b)
{
    char c = 0;
    c = *a;
    *a = *b;
    *b = c;
}
