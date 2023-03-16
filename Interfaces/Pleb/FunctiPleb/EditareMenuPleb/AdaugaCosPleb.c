int adaugaCosPleb(int myPosition, int addCantitate) // Adauga cantitatea, iar daca "addCantitae" != 0 adauga o cantitate data
{ //Returneaza 1 daca produsul a fost adaugat cu succes
    char oldSir[100000];
    getPositionInfo("Storage/Produse.txt", myPosition, oldSir);

    char *oldName = strtok(oldSir, " ");
    char *oldCantitate = strtok(NULL, " ");
    char *oldPret = strtok(NULL, "\n");

    if(atoi(oldCantitate) <= 0)
    {
        return 0; 
    }

    if(addCantitate == 0){
        addItemToList("Storage/Cos.txt", oldName, oldCantitate, oldPret); // adaug cantitatea dorita in cos
    }else{
        int flagCantitate = 1;
        char cantitateNoua[100000];
        char cantitateaRamasa[100000];
        char pretActualizat[100000];
        
        do{ // Verificari pentru Cantitate
            setColorTo(4); // GALBEN
            printf("Cantitarea MAXIMA: ");
            setColorTo(2); // VERDE
            printf("%s\n\n", oldCantitate);
            setColorTo(6); // CYAN
            printf("Introdu cantitatea dorita: ");
            setColorTo(5); // ROZ
            scanf("%s", &cantitateNoua);
            setColorTo(0); // DEFAULT
            int cantitateaDorita = atoi(cantitateNoua); // Cantitatea dorita/posibila
            int cantitateaMaxima = atoi(oldCantitate);

            float pretPerObj = atof(oldPret); // Pretul per obiect

            if(cantitateaDorita <= 0 || cantitateaDorita > cantitateaMaxima)
            {
                setColorTo(1); // ROSU
                printf("\nACEASTA CANTITATE NU POATE FI PLASATA\n");
                printf("INCEARCA DIN NOU\n\n");
                setColorTo(0); // DEFAULT
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
    return 1; //Daca sa ajuns la final produsul a fost adaugat cu succes
}