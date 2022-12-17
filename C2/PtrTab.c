#include <stdio.h>

int main()
{
   int tab[] = {1,3,6,9,14,19};
   int  * p1;
   char * p2;
   
   printf("%lu %lu %lu\n", sizeof(char), sizeof(int), sizeof(double));
   // %lu : long unsigned 

   p1 = tab; // p1 est un pointeur qui stocke l'adresse de la première valeur du tableau (1 dans ce cas)
   ++p1; // p1 pointe maintenant sur la deuxième valeur du tableau

   printf("%d\n", *p1);

   p2 = (char *) p1;
   p2 += sizeof(int); // C'est équivalent à dire : p2++ (car sizeof(int) = 1)

   printf("%d\n", *((int*)p2)); // Renvoie la valeur pointée par p2 (Troisième valeur du tableau)
   printf("%p\n ", p2); // Adresse stockée sur le pointeur 
   printf("%d\n", *(p1+4));  // le dernier élément du tableau
   printf("%p\n", p1+4); // Son adresse (élément 19)

   /*p1 = NULL;
   printf("%d", *p1);  Erreur de segmentation (Ce qui est logique) */

   return 0;
}