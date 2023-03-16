
void trimiteComanda(char listaDeTrimis[], char listaCarePrimeste[], char pretulTotalComanda[])
{
    int MAX = 100000;
    int ctr = 0; //contor

    FILE *mainFilePointer, *auxFilePointer;

    char str[100000];

    mainFilePointer = fopen(listaDeTrimis, "r");

    if(mainFilePointer == NULL)
    {
        printf("Fail to open file 1 From TRIMITE COMANDA");
    }else{
        auxFilePointer = fopen(listaCarePrimeste, "a");

        if(auxFilePointer == NULL)
        {
            printf("Fail to open file 2 From TRIMITE COMANDA");
            fclose(mainFilePointer);
        }else{
            fprintf(auxFilePointer, "%s", "\n"); // Adaugam un spatiu
            fprintf(auxFilePointer, "%s$", pretulTotalComanda); // Adaugam pretul comenzi
            fprintf(auxFilePointer, "%s", "\n"); // Adaugam un spatiu

            while (!feof(mainFilePointer)) 
            {
                strcpy(str, "\0");
                fgets(str, MAX, mainFilePointer);
                // if (!feof(mainFilePointer)) 
                // {
                    /* skip the line at given line number */
                    if (ctr > 0) 
                    {
                        fprintf(auxFilePointer, "%s", str);
                    }
                    ctr++;
                //}
            }
            fclose(mainFilePointer);
            fclose(auxFilePointer);

        }
    }
}