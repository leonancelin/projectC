#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

//#include "chiffrage.c"

char texte[200];
char cle[200];
char texte_chiffre[200];
int taille_texte = 0;
int taille_cle = 0;

int main()
{
    printf("Quel est votre texte a chiffrer ?\n");
    scanf("%200s", texte);


    printf("Quel perroquet voulez-vous utiliser\n");
    scanf("%200s", cle);

    taille_texte = strlen(texte);
    taille_cle = strlen(cle);

    printf("\n\n longueur texte : %d\n" + taille_texte);
    printf("\n longueur cle : %d\n" + taille_cle);


    chiffrage(texte, cle, texte_chiffre);

    printf("\ntexte_originel : %s", texte);
    printf("\ncle de chiffrement : %s", cle);
    printf("\ntexte chiffre : %s", texte_chiffre);
    //return 0;

}


