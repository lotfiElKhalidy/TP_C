#ifndef Histo_h
#define Histo_h
#include "commun.h"

/* Déclaration des fonctions relatives à la seconde struct de données */
void computeHisto(histogram_t , list_t);
void displayHisto(histogram_t);
int maxHisto(histogram_t);
float meanHisto(histogram_t);
int countHisto(histogram_t);
void displayText(histogram_t);

#endif