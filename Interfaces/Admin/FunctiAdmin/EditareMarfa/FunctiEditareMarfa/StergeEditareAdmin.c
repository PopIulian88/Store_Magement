
void stergereEditareAdmin(int myPosition)
{
    system("CLS");
    setColorTo(4); // GALBEN
    printf("\n  DORITI SA STERGETI PRODUSUL?\n\n");
    setColorTo(6); // CYAN
    printf("  Apasa 1 pentru DA \n");
    printf("  Apasa 2 pentru NU\n\n");
    setColorTo(0); // DEFAULT

    int flagConfirm = 1;

    while(flagConfirm == 1)
    {
        int key_code = _getch();
        switch(key_code)
        {
            case '1':
                deleteItemFromList("Storage/Produse.txt", myPosition); //#Main/DeleteItemFromList
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