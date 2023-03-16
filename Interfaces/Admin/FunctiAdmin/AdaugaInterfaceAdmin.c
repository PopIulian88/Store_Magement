void adaugaInterfaceAdmin()
{
    int flag = 1;
    char nume[50], cantitate[100000], pret[100000];

    system("CLS");
    setColorTo(4); //GALBEN
    printf("\n\n  DETALI PRODUS:\n\n");

    flag = 0;
    do{ // Verificare Nume
        setColorTo(6); // CYAN
        printf("Nume: ");
        fflush(stdin);
        setColorTo(5); // ROZ
        gets(nume);
        setColorTo(0); // DEFAULT

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
    //Daca nu am gasit numele inseamna ca numele nu e introdus
    if(corect == 0) // Produsul este deja introdus
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
        setColorTo(6); // CYAN
        printf("Cantitate: ");
        setColorTo(5); // ROZ
        scanf("%s", &cantitate);
        setColorTo(0); // DEFAULT
        int corect = atoi(cantitate);

        if(corect <= 0 || corect >= 100000)
        {
            setColorTo(1); // ROSU
            printf("\nACEASTA CANTITATE NU POATE FI PLASATA\n");
            printf("INCEARCA DIN NOU\n\n");
            setColorTo(0); // DEFAULT
        }else{
            flag = 0;
            sprintf(cantitate, "%d", corect); // int to string
        }
    }while(flag);

    flag = 1;
    do{ // Verificari pentru pret
        setColorTo(6); // CYAN
        printf("Pret: ");
        setColorTo(5); // ROZ
        scanf("%s", &pret);
        setColorTo(0); // DEFAULT
        double corect = atof(pret);
        if(corect <= 0 || corect >= 100000)
        {
            setColorTo(1); //ROSU
            printf("\nACEST PRET NU ESTE VALID\n");
            printf("INCEARCA IAR\n\n");
            setColorTo(0); // DEFAULT
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