void modificaPretEditare(int myPosition)
{
    system("CLS");

    int flag = 1;
    char pretNou[100000];
    do{ // Verificari pentru pret
        printf("\n\n Introduceti noul pret: ");
        scanf("%s", &pretNou);
        double corect = atof(pretNou);
        if(corect <= 0 || corect >= 100000)
        {
            printf("\nACEST PRET NU ESTE VALID\n");
            printf("INCEARCA IAR\n\n");
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

}