#include "./FunctiCos/PretFinal.c"

void confirmaComanda()
{
    double myPrice = pretFinal("Storage/Cos.txt");
    
    system("CLS");
    printf("\n\n  PRET FINAL: %.2lf\n\n", myPrice);

    printf("  DORITI SA PLASATI COMANDA?\n\n");
    printf("  Apasa 1 pentru DA \n");
    printf("  Apasa 2 pentru NU\n\n");

    int flagConfirm = 1;

    while(flagConfirm == 1)
    {
        int key_code = _getch();
        switch(key_code)
        {
            case '1':
                

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