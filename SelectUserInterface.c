#define NUMAR_TIPURI_UTILIZATORI 3

int selectedUser = 0;
char utilizator[NUMAR_TIPURI_UTILIZATORI][1][10] ={ //Meniul de user initial
    {"Admin"},
    {"Pleb"},
    {"EXIT"},
};

void printInterface()
{
    system("cls");
    printf("_=* WELCOME *=_\n\n");

    for(int i = 0; i < NUMAR_TIPURI_UTILIZATORI; i++)
    {
        if(i == selectedUser)
        {
            printf(" >>");
        }
        printf("  %s\n", utilizator[i][0]);
    }

    printf("\nPress W for up, S for down\n");

}

int selectUserInterface()
{
    printInterface();

    while(TRUE)
    {
        int key_code = _getch();

        switch(key_code){
                
            case 'w': case 'W': case 72: // UP
                selectedUser--;
                if(selectedUser < 0)
                    selectedUser = NUMAR_TIPURI_UTILIZATORI - 1;
                else
                    selectedUser = selectedUser % NUMAR_TIPURI_UTILIZATORI;
                break;

            case 's': case 'S': case 80: // DOWN
                selectedUser++;
                selectedUser = selectedUser % NUMAR_TIPURI_UTILIZATORI;
                break;
                
            case 13: // ENTER
                return selectedUser;
        }
        printInterface();  
    }
    
    return 0;
}