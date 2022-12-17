#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cellule 
{
  char * ligne;
  struct cellule * suiv;
} cellule_t;

typedef struct liste 
{
  cellule_t * tete;
  cellule_t * fin;
} liste_t;

void inserererEnFin(cellule_t * cell, liste_t * lch)
{
  if (lch->tete == NULL)
    {
      lch->tete = cell;
    }
    else
    {
      lch->fin->suiv = cell;
    }
    lch->fin = cell;
}

liste_t lecture(FILE * ptrfic)
{
  cellule_t * new = NULL;
  char chaine[255];
  liste_t lch = {NULL, NULL}; // Il faut initialiser la lch, Sinon on aura SEG FAULT

  while(fgets(chaine, 255, ptrfic))
  {
    new = (cellule_t *) malloc(sizeof(cellule_t));

    if (new != NULL)
    {
      new->ligne = (char *) malloc(sizeof(char)*(strlen(chaine)+1));

      if (new->ligne != NULL)
      {
        strcpy(new->ligne,chaine);
        new->suiv = NULL;
      }
    }

    inserererEnFin(new, &lch);
  }
  return lch;
}

/*liste_t saisirChaine(void)
{
  char chaine[255];
  cellule_t * new = NULL;
  liste_t lch;

  while (fgets(chaine, 255, stdin))
  {
    printf("Donner une chaine de caractères :\n");
    new = (cellule_t *) malloc(sizeof(cellule_t));
    strcpy(new->ligne,chaine);
    new->suiv = NULL;
      
    if (lch.tete == NULL)
    {
      lch.tete = new;
    }
    else
    {
      lch.fin->suiv = new;
    }
    lch.fin = new;
  }
  return lch;
}*/

void initialiser(liste_t * lch)
{
  lch->tete = NULL;
  lch->fin = NULL;
}

void afficherChaine(liste_t * lch)
{
  int i=1;
  cellule_t * cour;
  cour = lch->tete;

  while (cour != NULL)
  {
    printf("Élément %d:   ",i);
    printf("%s\n",cour->ligne);
    cour = cour->suiv;    
    i++;
  } // car la boucle n'affiche pas le dernier elt
} 

void libererChaine(liste_t * lch)
{
  cellule_t * cour;
  cellule_t * tmp = NULL;

  cour = lch->tete;

  while (cour != NULL)
  {
    tmp = cour;
    cour = cour->suiv;
    free(tmp->ligne);
    free(tmp);
  }
}  

int main(int argc, char ** argv)
{
  liste_t lch;
  FILE * pfic = stdin;

  initialiser(&lch);
  
  if (argc >= 2)
  {
    pfic = fopen(argv[1],"r");

    if (pfic == NULL)
    {
      printf("Erreur lors de la lecture du fichier\n");
    }
    else
    {
      lch = lecture(pfic);
    }
  }
  else
  {
    printf("Donner une chaine de caractères :\n");
    lch = lecture(pfic);
  }

  fclose(pfic);
  afficherChaine(&lch);
  libererChaine(&lch);
  
  return 0;
}