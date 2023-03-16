
void deleteItemFromList(char listName[], int nrItem) // ACEASTA FUNCTIE E POSIBIL SA MODIFICE UN ELEMENT DIN SIRUL DAT
{                                                   // DE PREFERAT DE FOLOSIT LA FINAL DE FUNCTIE
    if(nrItem == 0)
        return;

    nrItem++;
    int MAX = 100000;
    int ctr = 0; //contor

    FILE *mainFilePointer, *auxFilePointer;

    char str[100000], temp[] = "Storage/TempFile.txt";

    mainFilePointer = fopen(listName, "r");

    if(mainFilePointer == NULL)
    {
        printf("Fail to open file 1 From STERGE");
    }else{
        auxFilePointer = fopen(temp, "w");

        if(auxFilePointer == NULL)
        {
            printf("Fail to open file 2 From STERGE");
            fclose(mainFilePointer);
        }else{

            while (!feof(mainFilePointer)) 
            {
                strcpy(str, "\0");
                fgets(str, MAX, mainFilePointer);
                // if (!feof(mainFilePointer)) 
                // {
                    ctr++;
                    /* skip the line at given line number */
                    if (ctr != nrItem) 
                    {
                        fprintf(auxFilePointer, "%s", str);
                    }
                //}
            }
            fclose(mainFilePointer);
            fclose(auxFilePointer);
            remove(listName);  		// remove the original file 
            rename(temp, listName); 	// rename the temporary file to original name

        }
    }
}