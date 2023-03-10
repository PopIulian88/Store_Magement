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

    setColorTo(4); //GALBEN

    printf("~~~~~~~~~~~~~~~~~\n");
    printf("  $$ WELCOME $$  \n");
    printf("~~~~~~~~~~~~~~~~~\n\n");

    setColorTo(3); //CYAN
    printf("Select:\n");
    setColorTo(6); //CYAN

    for(int i = 0; i < NUMAR_TIPURI_UTILIZATORI; i++) //Afisam posibilitatile pe ecran
    {
        printf("______________\n");
        if(i == selectedUser)   //Daca posibilitatea pe care o afisam e cea selectata
        {                       //punem un caracter special in fata ei
            setColorTo(2); // VERDE
            printf("  >>");
            setColorTo(5); // ROZ
            printf(" %s\n", utilizator[i][0]);
            setColorTo(6); // CYAN
        }else{
            setColorTo(3); //ALBASTRU
            printf("   %s\n", utilizator[i][0]);
            setColorTo(6); // CYAN
        }
    }
    printf("______________\n");

    setColorTo(3); // ALBASTRU
    printf("\nFoloseste: W, S sau SAGETILE pentru a naviga.\n");
    printf("Apasa ENTER pentru a confirma\n");
    setColorTo(0); // DEFAULT
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