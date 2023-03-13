#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#include "./SelectMainMenu.c"
#include "../Admin/AdminMenu.c"
#include "../Pleb/PlebMenu.c"
#include "../Admin/AdminVerification.c"
#include "../../Color.c"
#include "../AfisInterfata.c"

void runMain()
{
    int flagMain = 1;

    do{
        int userNumberMain = selectMainInterface(); // #include "MainMenu"
                                                // selectam interfata pe care o dorim
        switch(userNumberMain) // Vedem interfata selectata
        {
            case 0: // ADMIN
                boolean corect = adminVerification(); // Daca este selectat ADMIN, trebuie 
                                                        //introdusa o parola
                if(corect)  // Daca parola e corecta intram in interfata de ADMIN
                {
                    adminInterface();
                }
                else //Altfel afisam faptul ca este gresita parola
                {
                    system("CLS");
                    setColorTo(1); // ROSU
                    printf("\n\n   INCORRECT PASSWORD\n\n");
                    setColorTo(0); // DEFAULT
                    system("pause");
                }
                break;

            case 1: // PLEB
                plebInterface(); //intram in interfata de PLEB
                break;

            case 2: // EXIT
                flagMain = 0; // Iesim din aplicatie
                break;
        }
    }while(flagMain);

}