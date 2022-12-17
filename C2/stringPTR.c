#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compter1(char * chaine) {
   int i = 0;
   
   while (*(chaine+i) != '\0')
    ++i;

   return i; 
}

int compter2(char * chaine) 
{
   char * s = chaine; // Pointeur sur le premier élément 

   while (*chaine != '\0')  // On se déplace jusqu'à la fin de la chaine  
      ++chaine;

   return chaine - s; // longueur = dernier - premier 
}

int compter3(char * chaine) 
{
   char * s = chaine;
   
   while (*chaine++); // On se déplace jusqu'au premier élément après la chaine  
   
   return chaine - s - 1;  
}

void saisir(char * s) 
{
   scanf("%s", s);
}


int main()
{
   int len1, len2, len3; 
   char * s = NULL;

   len1 = compter1("Physique");
   len2 = compter2("abcdefghijklmnopqrstuvwxyz");
   len3 = compter3("ISIMA");

   printf("len1 = %d\n len2 = %d\n len3 = %d\n", len1,len2,len3); // Les trois fonctions marchent niquel

   printf("Entrer votre prénom :\n");

   s = (char *) malloc(sizeof(char)); // It took me forever to understand that I should use malloc

   if (s != NULL)
   {
      saisir(s);
      printf("Bonjour %s !\n", s);

      if (strcmp(s,"ddd") == 0) printf("Bizarre \n");
   }
   
   return 0;

   /* ERREUR DE SEGMENTATION : -> Quand on est en train de manipuler des pointeurs non initialisés
                               -> Quand on est censé faire une allocation et on l'a pas fait 
   En tt cas, valgrind peut etre très bénéfique dans ces cas 
   NB : On ne peut pas écrire directement dans un pointeur, il faut faire une allocation. */
}

