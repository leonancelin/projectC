#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


char rallongement_perroquet(char texte[], char cle[])
{
    int size_texte = strlen(texte);
    int size_cle = strlen(cle);
    bool taille = false;

    if(size_cle%size_texte < 1)
        taille = true;

    while(taille)
    {
        char temp_cle[size_cle];
        strcpy(temp_cle, cle);
        strcat(cle, temp_cle);
        if(size_cle%size_texte < 1)
            taille = true;

        else
            taille = false;

    }

    return texte;
    return cle;

}



char chiffrage(char texte[], char cle[], char texte_chiffre[])
{
    int size_texte = strlen(texte);
    int size_cle = strlen(cle);
    int iteration = 0;

    //convert string to ASCII values

    int ascii_texte[size_texte];
    int ascii_cle[size_cle];
    int ascii_chiffrage[size_texte];

    for(int i= 0; i<size_texte; i++)
    {
        ascii_texte[i] = (int) texte[i];

    }


    for(int i= 0; i<size_cle; i++)
    {
        ascii_cle[i] = (int) cle[i];

    }



    for (int i=0; i<size_texte; i++)
    {
        ascii_chiffrage[i] = ascii_texte[i] - ascii_cle[i];
        if(ascii_cle[i] == "\0")
        {
            n += 1;
            ascii_chiffrage[i] = ascii_texte[i] - ascii_cle[i-n*size_cle];

        }

    }

    for(int i= 0; i<size_texte; i++)
        texte_chiffre[i] = (char) ascii_chiffrage[i];


    return texte;
    return cle;
    return texte_chiffre;


}



#endif // HEADER_H_INCLUDED
