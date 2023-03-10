#define NUMAR_TIPURI_UTILIZATORI 3

int selectedUser = 0; // Indicele elementului curent
char utilizator[NUMAR_TIPURI_UTILIZATORI][1][10] ={ //Meniul de user initial
    {"Admin"},
    {"Pleb"},
    {"EXIT"},
};

void printInterface()
{
    system("CLS");
    printf("_=* WELCOME *=_\n\n");

    for(int i = 0; i < NUMAR_TIPURI_UTILIZATORI; i++) //Afisam posibilitatile pe ecran
    {
        if(i == selectedUser)   //Daca posibilitatea pe care o afisam e cea selectata
        {                       //punem un caracter special in fata ei
            printf(" >>");
        }
        printf("  %s\n", utilizator[i][0]);
    }

    printf("\nPentru a naviga puteti folosi SAGETi\n");

}

int selectUserInterface()
{

    int fleg = 1;
    while(fleg) //Cat timp e activa putem naviga in meniu
    {
        printInterface(); // afisam interfata curenta
        
        int key_code = _getch(); // primim input de la tastatura

        switch(key_code)
        {   
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
                fleg = 0; //Cand apasam enter iesim din aceasta bucla
                break;
        } 
    }
    
    return selectedUser; // returnam valoarea selectata
}