#include "./FunctiEditareMarfa/StergeEditareAdmin.c"
#include "./FunctiEditareMarfa/ModificaPretEditare.c"
#include "./FunctiEditareMarfa/ModificaCantitateEditare.c"

void editInterface(int myProduct)
{
    int flagEdit = 1;

    do{
        int userNumberEdit = selectEditInterface(); // selectam interfata pe care o dorim

        switch(userNumberEdit) // Vedem interfata selectata
        {
            case 0: // Modifica cantitatea
                modificaCantitateEditare(myProduct);
                flagEdit = 0;
                break;

            case 1: // Schimba pret
                modificaPretEditare(myProduct);
                flagEdit = 0;
                break;
            
            case 2: // Stergere
                stergereEditareAdmin(myProduct);
                flagEdit = 0;
                break;
                
            case 3: // BACK
                flagEdit = 0; // Iesim din aplicatie
                break;
        }
    }while(flagEdit);

}