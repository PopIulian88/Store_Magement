#include "./SelectAdminMenu.c"
#include "./FunctiAdmin/MarfaInterfaceAdmin.c"
#include "./FunctiAdmin/AdaugaInterfaceAdmin.c"


void adminInterface()
{
    int flagAdmin = 1;

    do{
        int userNumberAdmin = selectAdminInterface(); // selectam interfata pe care o dorim

        switch(userNumberAdmin) // Vedem interfata selectata
        {
            case 0: // MARFA
                marfaInterfaceAdmin();
                break;

            case 1: // ADAUGA
                adaugaInterfaceAdmin();
                break;
                
            case 2: // BACK
                flagAdmin = 0; // Iesim din aplicatie
                break;
        }
    }while(flagAdmin);


}