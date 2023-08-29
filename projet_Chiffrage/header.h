#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

////////Entête définissant le chiffrage des textes

char chiffrage(char texte[], char cle[], char texte_chiffre[])
{
    int size_texte = strlen(texte) + 1;
    int size_cle = strlen(cle) ;
    int n, j = 0;

    int ascii_texte[size_texte];
    int ascii_cle[size_cle];
    int ascii_chiffrage[size_texte];

    //Conversion des chaines de caractères du texte en ASCII
    for(int i= 0; i<size_texte; i++)
    {
        ascii_texte[i] = (int) texte[i];

    }

    //Conversion des chaines de caractères de la clé en ASCII
    for(int i= 0; i<size_cle; i++)
    {
        ascii_cle[i] = (int) cle[i];

    }

    //Chiffrage de la chaine de caractères donnée par l'utilisateur
    while(j < size_texte)
    {
        if(j == size_cle)
            n += 1;

        //Modulo 256 pour que les valeurs restent dans la table ASCII étendue (de 0 à 255), puis on rajoute 32 afin d'avoir uniquement des signes visibles
        ascii_chiffrage[j] =((ascii_texte[j] - ascii_cle[j-n*size_cle])%256) + 32;
        j++;
    }

    //Conversion des valeurs ASCII en caractères
    for(int i= 0; i<size_texte; i++)
        texte_chiffre[i] = (char) ascii_chiffrage[i];

    return texte;
    return cle;
    return texte_chiffre;
}

char decryptage(char texte[], char cle[], char texte_chiffre[])
{
    int size_texte_chiffre = strlen(texte_chiffre) + 1;
    int size_cle = strlen(cle) ;
    int n, j = 0;

    int ascii_texte[size_texte_chiffre];
    int ascii_cle[size_cle];
    int ascii_chiffrage[size_texte_chiffre];


    //Conversion des chaines de caractères du texte en ASCII
    for(int i= 0; i<size_texte_chiffre; i++)
    {
        ascii_chiffrage[i] = (int) texte_chiffre[i];

    }

    //Conversion des chaines de caractères de la clé en ASCII
    for(int i= 0; i<size_cle; i++)
    {
        ascii_cle[i] = (int) cle[i];

    }

    //Déchiffrage de la chaine de caractères donnée par l'utilisateur
    while(j < size_texte_chiffre)
    {
        if(j == size_cle)
            n += 1;

        //Modulo 256 pour que les valeurs restent dans la table ASCII étendue (de 0 à 255)
        ascii_texte[j] =(ascii_chiffrage[j] + ascii_cle[j-n*size_cle])%256;
        j++;
    }

    //Conversion des valeurs ASCII en caractères
    for(int i= 0; i<size_texte_chiffre; i++)
        texte[i] = (char) ascii_texte[i];

    return texte;
    return cle;
    return texte_chiffre;


}



#endif // HEADER_H_INCLUDED
