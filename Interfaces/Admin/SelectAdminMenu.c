#define NR_ELEMENTE_ADMIN 6 //Setarile initiale pentru PLEB

char adminTitle[] = "ADMIN";
int optionSelectedAdmin = 0;
char menuAdmin[NR_ELEMENTE_ADMIN][100] = {
    "Afis",
    "Adauga",
    "Sterge",
    "Ajustare stoc",
    "Schimba pret",
    "BACK",
};

void printAdminInterface()
{
    system("CLS");

    afisiazaInterfata(menuAdmin, NR_ELEMENTE_ADMIN, optionSelectedAdmin, adminTitle);
}

int selectAdminInterface()
{
    int fleg = 1;
    while(fleg) //Cat timp e activa putem naviga in meniu
    {
        printAdminInterface(); // afisam interfata curenta
        
        int key_code = _getch(); // primim input de la tastatura

        switch(key_code)
        {   
            case 'w': case 'W': case 72: // UP
                optionSelectedAdmin--;
                if(optionSelectedAdmin < 0)
                    optionSelectedAdmin = NR_ELEMENTE_ADMIN - 1;
                else
                    optionSelectedAdmin = optionSelectedAdmin % NR_ELEMENTE_ADMIN;
                break;

            case 's': case 'S': case 80: // DOWN
                optionSelectedAdmin++;
                optionSelectedAdmin = optionSelectedAdmin % NR_ELEMENTE_ADMIN;
                break;
                
            case 13: // ENTER
                fleg = 0; //Cand apasam enter iesim din aceasta bucla
                break;
        } 
    }
    
    return optionSelectedAdmin; // returnam valoarea selectata
}