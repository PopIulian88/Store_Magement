
void getPositionInfo(char listName[], int curentPosition, char changedName[])
{                   // prin parametrul changedName intoarcem linia selectata
    int count = 0;  
    FILE *pointer;
    char data[100];
    pointer = fopen(listName, "r");

    if(pointer == NULL)
    {
        printf("Fail to open file");
    }else{
        while(fgets(data, 100, pointer))
        {
            if(curentPosition == count)
            {
                strcpy(changedName, data);
                fclose(pointer);
                return;
            }
            count++;
        }
        fclose(pointer);
    }
}

//MOD DE FOLOSIRE
//
//     char oldSir[100000];
//     getPositionInfo("Storage/Produse.txt", myPosition, oldSir);

//     char *oldName = strtok(oldSir, " ");
//     char *oldCantitate = strtok(NULL, " ");
//     char *oldPret = strtok(NULL, " ");