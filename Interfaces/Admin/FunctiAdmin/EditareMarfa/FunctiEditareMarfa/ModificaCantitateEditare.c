
void modificaCantitateEditare(int myPosition)
{
    system("CLS");

    printf("\n\n ADAUGI sau SCOTi?\n\n");
    printf("  Apasa 1 pentru ADAUGARE \n");
    printf("  Apasa 2 pentru SCOATERE\n\n");

    int adauga;

    int flagConfirm = 1;

    while(flagConfirm == 1)
    {
        int key_code = _getch();
        switch(key_code)
        {
            case '1':
                adauga = 1; // ADUNA
                flagConfirm = 0;
                break;
            case '2':
                adauga = 0; // SCADE
                flagConfirm = 0;
                break;
        }
    }

    char oldSir[100000]; // functia va returna un oldSir linia actuala
    getPositionInfo("Storage/Produse.txt", myPosition, oldSir);

    char *oldName = strtok(oldSir, " ");
    char *oldCantitate = strtok(NULL, " ");
    char *oldPret = strtok(NULL, "\n");

    int flagCantitate = 1;
    char cantitateNoua[100000];
    do{ // Verificari pentru Cantitate
        printf("Introdu cantitate: ");
        scanf("%s", &cantitateNoua);
        int corect = atoi(cantitateNoua);

        if(corect < 0 || corect >= 100000)
        {
            printf("\nACEASTA CANTITATE NU POATE FI PLASATA\n");
            printf("INCEARCA DIN NOU\n\n");
        }else{
            if(adauga == 1)
                corect = atoi(oldCantitate) + corect; // se aduna cantitatea adaugata peste cea recenta
            else
                corect = atoi(oldCantitate) - corect; // se scade cantitatea adaugata din cea recenta
            if(corect < 0) //conditie de siguranta
                corect = 0;
            if(corect > 100000)
                corect = 100000;
            
            flagCantitate = 0;
            sprintf(cantitateNoua, "%d", corect); // int to string
        }
    }while(flagCantitate);

    //adaugam in lista sirul cu noua cantitate si stergem linia veche
    addItemToList("Storage/Produse.txt", oldName, cantitateNoua, oldPret);
    deleteItemFromList("Storage/Produse.txt", myPosition);

    system("CLS"); // Confirmare modificari
    setColorTo(2);
    printf("\n\n  MODIFICARE EFECTUATA CU SUCCES\n\n");
    setColorTo(0);
    system("pause");
}