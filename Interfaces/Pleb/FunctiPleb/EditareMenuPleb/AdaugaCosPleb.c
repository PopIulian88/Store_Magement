void adaugaCosPleb(int myPosition, int addCantitate) // Adauga cantitatea, iar daca "addCantitae" != 0 adauga o cantitate data
{
    char oldSir[100000];
    getPositionInfo("Storage/Produse.txt", myPosition, oldSir);

    char *oldName = strtok(oldSir, " ");
    char *oldCantitate = strtok(NULL, " ");
    char *oldPret = strtok(NULL, "\n");

    if(addCantitate == 0){
        addItemToList("Storage/Cos.txt", oldName, oldCantitate, oldPret); // adaug cantitatea dorita in cos
    }else{
        int flagCantitate = 1;
        char cantitateNoua[100000];
        char cantitateaRamasa[100000];
        char pretActualizat[100000];
        
        do{ // Verificari pentru Cantitate
            printf("Cantitarea MAXIMA: %s\n\n", oldCantitate);
            printf("Introdu cantitatea dorita: ");
            scanf("%s", &cantitateNoua);
            int cantitateaDorita = atoi(cantitateNoua); // Cantitatea dorita/posibila
            int cantitateaMaxima = atoi(oldCantitate);

            float pretPerObj = atof(oldPret); // Pretul per obiect

            if(cantitateaDorita <= 0 || cantitateaDorita > cantitateaMaxima)
            {
                printf("\nACEASTA CANTITATE NU POATE FI PLASATA\n");
                printf("INCEARCA DIN NOU\n\n");
            }else{
                            
                flagCantitate = 0;
                sprintf(cantitateaRamasa, "%d", cantitateaMaxima - cantitateaDorita); //Cantitatea ramasa
                sprintf(pretActualizat, "%.2f", cantitateaDorita * pretPerObj); // Actualizarea pretului in functie de cantitate
                sprintf(cantitateNoua, "%d", cantitateaDorita); // Cantitatea noua
            }
        }while(flagCantitate);
    
        addItemToCos("Storage/Cos.txt", oldName, cantitateNoua, pretActualizat); // adaug cantitatea dorita in cos

        //dam uppdate la lista de stoc
        addItemToList("Storage/Produse.txt", oldName, cantitateaRamasa, oldPret);
        deleteItemFromList("Storage/Produse.txt", myPosition);
    }
}