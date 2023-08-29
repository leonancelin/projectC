#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

////////Entête définissant le chiffrage des textes

void chiffrage(char texte[], char cle[], char texte_chiffre[])
{
    int size_texte = strlen(texte);
    int size_cle = strlen(cle) ;
    int n, j = 0;

    //chiffrage
    while(j < size_texte)
    {
        if(j == size_cle)
            n += 1;


        if(j-n*size_cle == size_cle)
            n +=1;


        texte_chiffre[j] = (texte[j] - cle[j - n*size_cle]);
        printf("\n%c, %c, %c", texte_chiffre[j], texte[j], cle[j - n*size_cle]);
        j++;
    }
    return texte_chiffre;
}


/////////////////////////////////////////////////////////////////////////////////


char decryptage(char texte[], char cle[], char texte_chiffre[])
{
    int size_texte_chiffre = strlen(texte_chiffre);
    int size_cle = strlen(cle) ;
    int n, j = 0;

    //Déchiffrage de la chaine de caractères donnée par l'utilisateur
    while(j < size_texte_chiffre)
    {
        if(j == size_cle)
            n += 1;

        if(j-n*size_cle == size_cle)
            n +=1;

        texte[j] = (texte_chiffre[j] + cle[j - n*size_cle]);
        printf("\n%c, %c, %c", texte_chiffre[j], texte[j], cle[j - n*size_cle]);
        j++;
    }

    return texte;
}



#endif // HEADER_H_INCLUDED
