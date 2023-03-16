
void stergeProdusCos(int myProduct)
{
    system("CLS");
    printf("\n\n DORITI SA STERGETI PRODUSUL?\n\n");
    printf("  Apasa 1 pentru DA \n");
    printf("  Apasa 2 pentru NU\n\n");

    int flagConfirm = 1;

    while(flagConfirm == 1)
    {
        int key_code = _getch();
        switch(key_code)
        {
            case '1':
                
                char oldSir[100000]; // Retinem proprietetile produsului pe care dorim sa il stergem
                getPositionInfo("Storage/Cos.txt", myProduct, oldSir);

                char *oldName = strtok(oldSir, " ");
                char *oldCantitate = strtok(NULL, " ");
                char *oldPret = strtok(NULL, "\n");
                

                deleteItemFromList("Storage/Cos.txt", myProduct); //#Main/DeleteItemFromList
                
                putBacktoList("Storage/Produse.txt", oldName, oldCantitate, oldPret);
                flagConfirm = 0;

                system("CLS"); // Confirmare modificari
                setColorTo(2);
                printf("\n\n  STERGERE EFECTUATA CU SUCCES\n\n");
                setColorTo(0);
                system("pause");
                break;
            case '2':
                flagConfirm = 0;
                break;
        }
    }
}