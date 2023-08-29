#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "header.h"
#include "lecture_ecriture.h"

char texte[1000];
char cle[200];
char texte_chiffre[1000];
int taille_texte = 0;
int taille_cle = 0;

int choice = 0;

int main()
{
    while (true)
    {
    //MENU PRINCIPAL
    printf("Bienvenue dans le programme de cryptage du perroquet\n");
    printf("1 - Definissez un perroquet pour encrypter le texte présent dans le fichier source.txt\n");
    printf("2 - Ecrivez un texte perosnnalise a encrypter, puis le perroquet utilise pour l'encrypter\n");
    printf("3 - Decryptez le message dans le fichier destination (a choisir si vous avez deja encrypte quelque chose)\n");
    printf("4 - Quittez le programme\n\n");
    printf("Tapez votre choix\n\n");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1 :

        //texte à chiffrer
        memset(texte, 0, sizeof(texte));
        readFile(texte, 1);

        //clé utilisée
        memset(cle, 0, sizeof(cle));
        printf("Quel perroquet voulez-vous utiliser\n");
        scanf("%s", &cle);
        writeFileKey(cle);

        //Chiffrage du texte
        memset(texte_chiffre, 0, sizeof(texte_chiffre));
        chiffrage(texte, cle, texte_chiffre);

        writeFileEncrypted(texte_chiffre);

        //suppression du fichier source
        remove("source.txt");

        //Présentation des résultats
        printf("\ntexte originel : %s", texte);
        printf("\ncle de chiffrement : %s", cle);
        printf("\ntexte chiffre : %s\n\n", texte_chiffre);

        return 0;

        break;


/////////////////////////////////////////////////////////////////////////////////////

    case 2 :
            memset(texte, 0, sizeof(texte));
            memset(cle, 0, sizeof(cle));
            memset(texte_chiffre, 0, sizeof(texte_chiffre));


            //Saisie du texte à chiffrer, comprend les espaces
            printf("Quel est votre texte a chiffrer ?\n");
            //fgets(texte, sizeof(texte), stdin);
            scanf("%s", &texte);



            //Saisie de la clé (perroquet) par l'utilisateur
            printf("Quel perroquet voulez-vous utiliser\n");
            scanf("%s", &cle);
            writeFileKey(cle);


            //Debugging, longueur de la chaine de caractères ne fonctionne pas
            taille_texte = strlen(texte);
            taille_cle = strlen(cle);

            //taille_texte = (int) taille_texte;
            //taille_cle = (int) taille_cle;
            printf("\n\n longueur texte : %d \n", taille_texte);
            printf("\n longueur cle : %d \n", taille_cle);

            //Chiffrage du texte
            chiffrage(texte, cle, texte_chiffre);

            writeFileEncrypted(texte_chiffre);

            //Présentation des résultats
            printf("\ntexte originel : %s", texte);
            printf("\ncle de chiffrement : %s", cle);
            printf("\ntexte chiffre : %s\n\n", texte_chiffre);

            return 0;

            break;

    case 3 :
        memset(texte, 0, sizeof(texte));
        memset(cle, 0, sizeof(cle));
        memset(texte_chiffre, 0, sizeof(texte_chiffre));

        //Décryptage de l'encryption précédente
        readFile(cle, 2);
        readFile(texte_chiffre, 3);
        decryptage(texte, cle, texte_chiffre);

        //Présentation des résultats
        printf("\ntexte originel : %s", texte);

        return 0;
        break;

    case 4 :
        exit(0);

    default:
        exit(0);



    }

}





}


