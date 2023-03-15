#include "./SelectCosInterface.c"
#include "./EditareMenuCos/CosInterfaceMenuPleb.c"
#include "./EditareMenuCos/ConfirmaComandaPleb.c"

void cosInterfacePleb()
{
    int flagPleb = 1;

    do{
        int userNumberPleb = selectCosInterface(); // selectam interfata pe care o dorim
        
        switch(userNumberPleb) // Vedem interfata selectata
        {
            case 0: // AFISIAZA COS
                cosInterfaceMenuPleb();
                break;

            case 1: // CONFIRMA COMANDA
                confirmaComanda();
                break;

            case 2: // EXIT
                flagPleb = 0; // Iesim din Interfata
                break;
        }
    }while(flagPleb);
}