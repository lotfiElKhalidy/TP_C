#include <stdio.h>

int main()
{
    int i;

    printf("Donner un nombre :");
    scanf("%i",&i);
    while (i!=0)
    {
        i=i/2;
        printf("%i",i);
    }
    return 0;
}