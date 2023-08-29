#ifndef LECTURE_ECRITURE_H_INCLUDED
#define LECTURE_ECRITURE_H_INCLUDED
//Entête définissant la lecture et l'exriture des fichiers


//Fonciton pour écrire le texte encrypté
void writeFileEncrypted(char texte_chiffre[])
{
    FILE *fp = NULL;

    fp = fopen("dest.crt.txt", "w+t");
    if (fp == NULL)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

    for(int i = 0; i != '\0'; i++)
    {
       fputc(texte_chiffre[i], fp);
    }


    int retClose = fclose(fp);
    if (retClose!= 0)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

}

//Fonciton pour inscrire la clé dans un fichier
void writeFileKey(char cle[])
{
    FILE *fp = NULL;

    fp = fopen("perroquet.txt", "w+t");
    if (fp == NULL)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

    for(int i = 0; i != '\0'; i++)
    {
       fputc(cle[i], fp);
    }


    int retClose = fclose(fp);
    if (retClose!= 0)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

}



/*
void lectureFichier(void)
{
FILE *fp = NULL;
    char lettreLu = '\0';

    fp = fopen("fichier.txt", "rt");
    if (fp == NULL)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }


    fread(&lettreLu, sizeof(lettreLu), sizeof(char), fp);
    if (feof(fp))
    {
        printf("\nFichier Vide !!!");
    }

    //Tant que la fin de fichier n'a pas �t� d�tect�e
    while(!feof(fp))
    {
        printf("\nLettre Lu : %c", lettreLu);
        fread(&lettreLu, sizeof(lettreLu), sizeof(char), fp);
        if (feof(fp))
        {
           printf("\n\tFichier Fini !!!");
        }
    }

    int retClose = fclose(fp);
    if (retClose!= 0)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

} */

char readFile(char texte[], int choix)
{
    FILE* ptr;

    // Ouverture de différents fichiers en focntion du choix fait
    switch (choix)
    {
    case 1:
       ptr = fopen("source.txt", "r");
       break;

    case 2 :
       ptr = fopen("perroquet.txt", "r");
       break;

    case 3 :
       ptr = fopen("dest.crt.txt", "r");
       break;

    }


    if (NULL == ptr) {
        printf("file can't be opened \n");
    }

    printf("content of this file are \n");

    // Printing what is written in file
    // character by character using loop.
    do {
        //texte = fgetc(ptr); //texte, sizeof(texte), stdin
        fgets(texte, 1000, ptr);
        printf("%s", texte);

        // Checking if character is not EOF.
        // If it is EOF stop reading.
    } while (texte != EOF);

    // Closing the file
    fclose(ptr);

    /*
    int taille = strlen(texte);
    for(int i= 0; i<taille+1; i++)
        texte[i] = (char) texte[i];*/

    return texte;


}





#endif // LECTURE_ECRITURE_H_INCLUDED
