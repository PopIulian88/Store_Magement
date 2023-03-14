
void stergereEditareAdmin(int myPosition)
{
    system("CLS");
    printf("\n\n SUNTETI SIGUR?\n\n");
    printf("  Apasa 1 pentru DA \n");
    printf("  Apasa 2 pentru NU\n\n");

    int flagConfirm = 1;

    while(flagConfirm == 1)
    {
        int key_code = _getch();
        switch(key_code)
        {
            case '1':
                deleteItemFromList("Storage/Produse.txt", myPosition); //#Main/DeleteItemFromList
                flagConfirm = 0;
                break;
            case '2':
                flagConfirm = 0;
                break;
        }
    }

}