#include "./SelectPlebMenu.c"
#include "./FunctiPleb/ShopInterfacePleb.c"
#include "./FunctiPleb/CosInterfacePleb.c"
#include "./FunctiPleb/EditareMenuPleb/AdaugaCosPleb.c"
#include "./FunctiPleb/EditareMenuPleb/AddItemToCos.c"

void plebInterface()
{
    int flagPleb = 1;

    do{
        int userNumberPleb = selectPlebInterface(); // selectam interfata pe care o dorim
        
        switch(userNumberPleb) // Vedem interfata selectata
        {
            case 0: // SHOP
                shopInterfacePleb();
                break;

            case 1: // COS
                cosInterfacePleb();
                break;

            case 2: // EXIT
                flagPleb = 0; // Iesim din Interfata
                break;
        }
    }while(flagPleb);
}