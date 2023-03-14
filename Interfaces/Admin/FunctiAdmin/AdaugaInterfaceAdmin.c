void adaugaInterfaceAdmin()
{
    int flag = 1;
    char nume[50], cantitate[100000], pret[100000];

    system("CLS");
    printf("Introdu produsul:\n\n");
    
    printf("Nume: ");
    scanf("%s", &nume);

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

    system("pause");
}