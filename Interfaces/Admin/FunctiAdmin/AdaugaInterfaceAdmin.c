void adaugaInterfaceAdmin()
{
    int flag = 1;
    char nume[50], cantitate[100000], pret[100000];

    system("CLS");
    printf("Introdu produsul:\n\n");

    flag = 0;
    do{ // Verificare Nume
        printf("Nume: ");
        fflush(stdin);
        gets(nume);
        //scanf("%s", &nume);

    for (int i = 0; nume[i]!='\0'; i++){ // Modificari nume
        if(nume[i] >= 'a' && nume[i] <= 'z') // toUpperCase
            nume[i] = nume[i] - 32;
        if(nume[i] == ' ') //Transformam spatiile in '_'
            nume[i] = '_';
    }

    //Cautam in fisier daca mai exista un produs cu acest nume
    int count = 0, corect = 1;  
    FILE *pointer;
    char data[100];
    pointer = fopen("Storage/Produse.txt", "r");

    if(pointer == NULL)
    {
        printf("Fail to open file");
    }else{
        while(fgets(data, 100, pointer))
        {
            char oldSir[100000]; // functia va returna un oldSir linia actuala
            getPositionInfo("Storage/Produse.txt", count, oldSir);

            char *oldName = strtok(oldSir, " ");

            if(strcmp(nume, oldName) == 0) // daca gasim un nume identic nu e ok
            {
                corect = 0;
            }
            count++;
        }
        fclose(pointer);
    }
    //Daca nu am gasit numele inseamna ca numele e corect
    if(corect == 0)
    {
        system("CLS"); // Nume incorect
        setColorTo(1);
        printf("\n\n  ACEST PRODUS ESTE DEJA INTRODUS\n\n");
        setColorTo(0);
        system("pause");
        return;
    }
    }while(flag);

    // TERMINARE VERIFICARE NUME

    flag = 1;
    do{ // Verificari pentru Cantitate
        printf("Cantitate: ");
        scanf("%s", &cantitate);
        int corect = atoi(cantitate);

        if(corect <= 0 || corect >= 100000)
        {
            printf("\nACEASTA CANTITATE NU POATE FI PLASATA\n");
            printf("INCEARCA DIN NOU\n\n");
        }else{
            flag = 0;
            sprintf(cantitate, "%d", corect); // int to string
        }
    }while(flag);

    flag = 1;
    do{ // Verificari pentru pret
        printf("Pret: ");
        scanf("%s", &pret);
        double corect = atof(pret);
        if(corect <= 0 || corect >= 100000)
        {
            printf("\nACEST PRET NU ESTE VALID\n");
            printf("INCEARCA IAR\n\n");
        }else{
            flag = 0;
            sprintf(pret, "%.2f", corect); // float to string
        }
    }while(flag);


    addItemToList("Storage/Produse.txt", nume, cantitate, pret); //#include "./Main/ AddItemToList"

    system("CLS"); // Confirmare modificari
    setColorTo(2);
    printf("\n\n  ADAUGARE EFECTUATA CU SUCCES\n\n");
    setColorTo(0);
    system("pause");
}