#include <stdio.h>
#include <stdlib.h> // Il faut inclure cette bibliothèque quand on fait appel à malloc

#define N 1000000


int main()
{
    double * tab; // %f ; Careful next time 

    tab = (double *) malloc(N*sizeof(double));

    if (tab != NULL)
    {
        for (int i=0; i<N; ++i)
        {
            *(tab+i) = i*i;
            printf("%f\n",*(tab+i));
        }
        free(tab);
    }

    return 0;
}