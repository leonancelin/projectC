#ifndef LECTURE_ECRITURE_H_INCLUDED
#define LECTURE_ECRITURE_H_INCLUDED
//Entête définissant la lecture et l'exriture des fichiers

void ecrireFichier(void)
{
    FILE *fp = NULL;

    fp = fopen("fichier.txt", "w+t");
    if (fp == NULL)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }
/*
    for(char lettre='A'; lettre <= 'Z'; lettre++)
    {
        fwrite(&lettre, sizeof(lettre), sizeof(char), fp);
    } */


    int retClose = fclose(fp);
    if (retClose!= 0)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }

}


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

    //1ere lecture
    //fseek(fp, 5, SEEK_SET);   //D�calage de 5 � partir du d�but du fichier
    //fseek(fp, -5, SEEK_END);    //D�calage de 5 � partir de la fin de fichier

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

}





#endif // LECTURE_ECRITURE_H_INCLUDED
