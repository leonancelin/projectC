#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

////////Ent�te d�finissant le chiffrage des textes

char chiffrage(char texte[], char cle[], char texte_chiffre[])
{
    int size_texte = strlen(texte) + 1;
    int size_cle = strlen(cle) ;
    int n, j = 0;

    int ascii_texte[size_texte];
    int ascii_cle[size_cle];
    int ascii_chiffrage[size_texte];

    //Conversion des chaines de caract�res du texte en ASCII
    for(int i= 0; i<size_texte; i++)
    {
        ascii_texte[i] = (int) texte[i];

    }

    //Conversion des chaines de caract�res de la cl� en ASCII
    for(int i= 0; i<size_cle; i++)
    {
        ascii_cle[i] = (int) cle[i];

    }

    //Chiffrage de la chaine de caract�res donn�e par l'utilisateur
    while(j < size_texte)
    {
        if(j == size_cle)
            n += 1;

        //On commence � partir de 32 pour �viter d'afficher de la mise en page (retour � la ligne, etc...)
        ascii_chiffrage[j] = 32 + abs(ascii_texte[j] - ascii_cle[j-n*size_cle]);
        j++;
    }

    //Conversion des valeurs ASCII en caract�res
    for(int i= 0; i<size_texte; i++)
        texte_chiffre[i] = (char) ascii_chiffrage[i];

    return texte;
    return cle;
    return texte_chiffre;
}

#endif // HEADER_H_INCLUDED
