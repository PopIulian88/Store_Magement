#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#include "./Interfaces/SelectUserInterface.c"
#include "./Interfaces/Admin/AdminInterface.c"
#include "./Interfaces/Pleb/PlebInterface.c"
#include "./Interfaces/Admin/AdminVerification.c"
#include "./Color.c"


int main()
{
    int fleg = 1;

    do{
        int userNumber = selectUserInterface(); //selectam interfata pe care o dorim

        switch(userNumber) // Vedem interfata selectata
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
                    printf("\n\n   INCORET PASSWORD\n\n");
                    setColorTo(0); // DEFAULT
                    system("pause");
                }
                break;

            case 1: // PLEB
                plebInterface(); //intram in interfata de PLEB
                break;

            case 2: // EXIT
                fleg = 0; // Iesim din aplicatie
                break;
        }
    }while(fleg);

    return 0;
}

//Color link: https://learn.microsoft.com/en-us/windows/console/console-screen-buffers#character-attributes
// How to use them: https://dev.to/tenry/terminal-colors-in-c-c-3dgc