#ifndef list_h
#define list_h
#include "commun.h"

/* Déclaration des fonctions relatives à la première struct de données */
void initList(list_t *);
int insert(list_t *, char *, int);
void displayByKey(list_t );
void displayByValue(list_t );
void freeList(list_t *);


#endif
