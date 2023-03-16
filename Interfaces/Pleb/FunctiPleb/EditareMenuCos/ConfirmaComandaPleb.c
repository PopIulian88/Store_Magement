#include "./FunctiCos/PretFinal.c"
#include "./FunctiCos/TrimiteComanda.c"
#include "./FunctiCos/RecreazaFisier.c"

void confirmaComanda()
{
    double myPrice = pretFinal("Storage/Cos.txt"); // calculam pretul produselo din cos
    if(myPrice <= 0.0) // varificam daca este vre-un produs in cos
    {
        system("CLS");
        setColorTo(1); // ROSU
        printf("\n\n NU AI NICI UN PRODUS IN COS \n\n");
        setColorTo(0); // DEFAULT
        system("pause");
        return; // Daca nu avem produse in cos nu trimite nici o comanda
    }

    char myPriceChar[100000];
    sprintf(myPriceChar, "%.2f", myPrice);
    
    system("CLS");
    setColorTo(4); // GALBEN
    printf("\n\n  PRET FINAL: ");
    setColorTo(2); // VERDE
    printf("%.2lf\n\n", myPrice);

    setColorTo(4); // GALBEN
    printf("  DORITI SA PLASATI COMANDA?\n\n"); // Vedem daca utilizatorul chiar vrea sa trimita comanda
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
                
                trimiteComanda("Storage/Cos.txt", "Storage/Comenzi.txt", myPriceChar); //trimite comanda
                recreazaFisier("Storage/Cos.txt"); // recreen fisierul in care se afla produsele din cos

                system("CLS"); // Confirmare modificari
                setColorTo(2);
                printf("\n\n  COMANDA EFECTUATA CU SUCCES\n\n");
                setColorTo(0);
                system("pause");
                flagConfirm = 0;
                break;
            case '2':
                flagConfirm = 0;
                break;
        }
    }

}