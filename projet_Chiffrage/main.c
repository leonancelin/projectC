#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "chiffrage.c"

char texte[];
char cle[];
char texte_chiffre[];

int main()
{
    printf("Quel est votre texte à chiffrer ?\n");
    gets(texte);

    printf("Quel perroquet voulez vous utiliser\n");
    gets(cle);


    rallongement_perroquet(texte, cle);
    chiffrage(texte, cle, texte_chiffre);

    printf(texte);
    printf(cle);
    printf(texte_chiffre);

}


