#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "header.h"
#include "lecture_ecriture.h"

char texte[200];
char cle[200];
char texte_chiffre[200];
int taille_texte = 0;
int taille_cle = 0;

int main()
{
    //Saisie du texte à chiffrer, comprend les espaces
    printf("Quel est votre texte a chiffrer ?\n");
    //scanf("%s", texte);
    fgets(texte, sizeof(texte), stdin);

    //Saisie de la clé (perroquet) par l'utilisateur
    printf("Quel perroquet voulez-vous utiliser\n");
    scanf("%s", cle);

    //Debugging, longueur de la chaine de caractères ne fonctionne pas
    taille_texte = strlen(texte) +1 ;
    taille_cle = strlen(cle) +1 ;
    printf("\n\n longueur texte : %d \n" + taille_texte);
    printf("\n longueur cle : %d \n" + taille_cle);

    //Chiffrage du texte
    chiffrage(texte, cle, texte_chiffre);
    //lireFichier();
    ecrireFichier();

    //Présentation des résultats
    printf("\ntexte originel : %s", texte);
    printf("cle de chiffrement : %s", cle);
    printf("\ntexte chiffre : %s\n\n", texte_chiffre);

}


