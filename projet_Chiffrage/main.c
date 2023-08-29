#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"


char texte[200];
char cle[200];
char texte_chiffre[200];
int taille_texte = 0;
int taille_cle = 0;

int main()
{
    //Saisie du texte à chiffrer
    printf("Quel est votre texte a chiffrer ?\n");
    scanf("%200s", texte);

    // Saisie de la clé
    printf("Quel perroquet voulez-vous utiliser\n");
    scanf("%200s", cle);

    taille_texte = strlen(texte);
    taille_cle = strlen(cle);

    //Debugging
    printf("\n\n longueur texte : %d\n" + taille_texte);
    printf("\n longueur cle : %d\n" + taille_cle);

    /*rallongement_perroquet(texte, cle);*/
    chiffrage(texte, cle, texte_chiffre);

    // présentation des résultats
    printf("\ntexte_originel : %s", texte);
    printf("\ncle de chiffrement : %s", cle);
    printf("\ntexte chiffre : %s", texte_chiffre);

}


