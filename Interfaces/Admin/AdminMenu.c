#include "./SelectAdminMenu.c"

void adminInterface()
{
    int flagAdmin = 1;

    do{
        int userNumberAdmin = selectAdminInterface(); // selectam interfata pe care o dorim

        switch(userNumberAdmin) // Vedem interfata selectata
        {
            case 0: // 
                    system("CLS");
                    printf("CAZUL 0 CU SUCCES");
                break;

            case 1: // 
                system("CLS");
                    printf("CAZUL 1 CU SUCCES");
                break;

            case 2: // EXIT
                flagAdmin = 0; // Iesim din aplicatie
                break;
        }
    }while(flagAdmin);


}