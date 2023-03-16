void modificaPretEditare(int myPosition)
{
    system("CLS");

    int flag = 1;
    char pretNou[100000];
    do{ // Verificari pentru pret
        setColorTo(4);
        printf("\n\n Introduceti noul pret: ");
        setColorTo(5);
        scanf("%s", &pretNou);
        setColorTo(0); // DEFAULT
        double corect = atof(pretNou);
        if(corect <= 0 || corect >= 100000)
        {
            setColorTo(1); // ROSU
            printf("\nACEST PRET NU ESTE VALID\n");
            printf("INCEARCA IAR");
            setColorTo(0); // DEFAULT
        }else{
            flag = 0;
            sprintf(pretNou, "%.2f", corect); // float to string
        }
    }while(flag);

    char oldSir[100000];
    getPositionInfo("Storage/Produse.txt", myPosition, oldSir);

    char *oldName = strtok(oldSir, " ");
    char *oldCantitate = strtok(NULL, " ");
    char *oldPret = strtok(NULL, "\n");

    addItemToList("Storage/Produse.txt", oldName, oldCantitate, pretNou);
    deleteItemFromList("Storage/Produse.txt", myPosition);

    system("CLS"); // Confirmare modificari
    setColorTo(2);
    printf("\n\n  MODIFICARE EFECTUATA CU SUCCES\n\n");
    setColorTo(0);
    system("pause");

}