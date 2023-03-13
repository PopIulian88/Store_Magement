#define NR_ELEMENTE_MAIN 3 //Setarile initiale pentru PLEB

char mainTitle[] = "WELCOME";
int optionSelectedMain = 0; // Indicele elementului curent
char utilizator[NR_ELEMENTE_MAIN][100] ={ //Meniul de user initial
    "Admin",
    "Pleb",
    "EXIT",
};

void printMainInterface()
{
    system("CLS");

    afisiazaInterfata(utilizator, NR_ELEMENTE_MAIN, optionSelectedMain, mainTitle); // #AfisText.c
}

int selectMainInterface()
{

    int fleg = 1;
    while(fleg) //Cat timp e activa putem naviga in meniu
    {
        printMainInterface(); // afisam interfata curenta
        
        int key_code = _getch(); // primim input de la tastatura

        switch(key_code)
        {   
            case 'w': case 'W': case 72: // UP
                optionSelectedMain--;
                if(optionSelectedMain < 0)
                    optionSelectedMain = NR_ELEMENTE_MAIN - 1;
                else
                    optionSelectedMain = optionSelectedMain % NR_ELEMENTE_MAIN;
                break;

            case 's': case 'S': case 80: // DOWN
                optionSelectedMain++;
                optionSelectedMain = optionSelectedMain % NR_ELEMENTE_MAIN;
                break;
                
            case 13: // ENTER
                fleg = 0; //Cand apasam enter iesim din aceasta bucla
                break;
        } 
    }
    
    return optionSelectedMain; // returnam valoarea selectata
}