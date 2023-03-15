void shopInterfacePleb()
{
    int produsActual = 0;
    int fleg = 1;
    while(fleg) //Cat timp e activa putem naviga
    {
        system("CLS");
        int NrProduse = afisFile("Storage/Produse.txt", produsActual); // afisam interfata curenta
        
        int key_code = _getch(); // primim input de la tastatura

        switch(key_code)
        {   
            case 'w': case 'W': case 72: // UP
                produsActual--;
                if(produsActual < 0)
                    produsActual = NrProduse - 1;
                else
                    produsActual = produsActual % NrProduse;
                break;

            case 's': case 'S': case 80: // DOWN
                produsActual++;
                produsActual = produsActual % NrProduse;
                break;
                
            case 13: // ENTER
                fleg = 0; //Cand apasam enter iesim din aceasta bucla
                break;
        } 
    }

    if(produsActual > 0) // Produsul ales urmeaza sa fie adaugat in cos
    {
        system("CLS");
        printf("\n\n DORITI SA ADAUGATI IN COS?\n\n");
        printf("  Apasa 1 pentru DA \n");
        printf("  Apasa 2 pentru NU\n\n");

        int flagConfirm = 1;

        while(flagConfirm == 1) 
        {
            int key_code = _getch();
            switch(key_code)
            {
                case '1': // Daca pleb-ul alege ca vrea sa adauge in cos

                    adaugaCosPleb(produsActual, 1); // adaugam cu (1) = o sa adaugam noi cantitatea care se adauga
                    flagConfirm = 0;

                    system("CLS"); // Confirmare modificari
                    setColorTo(2);
                    printf("\n\n  PRODUS ADAUGAT CU SUCCES\n\n");
                    setColorTo(0);
                    system("pause");
                    break;
                case '2':
                    flagConfirm = 0;
                    break;
            }
        }

    }
}