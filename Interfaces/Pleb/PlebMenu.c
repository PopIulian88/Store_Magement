#include "./SelectPlebMenu.c"

void plebInterface()
{
    int flagPleb = 1;

    do{
        int userNumberPleb = selectPlebInterface(); // selectam interfata pe care o dorim
        
        switch(userNumberPleb) // Vedem interfata selectata
        {
            case 0: // 
                
                break;

            case 1: // 

                break;

            case 2: // EXIT
                flagPleb = 0; // Iesim din Interfata
                break;
        }
    }while(flagPleb);
}