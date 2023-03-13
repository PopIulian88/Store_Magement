#define NR_ELEMENTE_PLEB 3 //Setarile initiale pentru PLEB

char plebTitle[] = "PLEB";
int optionSelectedPleb = 0;
char menuPreb[NR_ELEMENTE_PLEB][100]={
    "Shop",
    "Cos",
    "BACK",
};

void printPlebInterface()
{
    system("CLS");

    afisiazaInterfata(menuPreb, NR_ELEMENTE_PLEB, optionSelectedPleb, plebTitle);
    
}

int selectPlebInterface()
{
    int fleg = 1;
    while(fleg) //Cat timp e activa putem naviga in meniu
    {
        printPlebInterface(); // afisam interfata curenta
        
        int key_code = _getch(); // primim input de la tastatura

        switch(key_code)
        {   
            case 'w': case 'W': case 72: // UP
                optionSelectedPleb--;
                if(optionSelectedPleb < 0)
                    optionSelectedPleb = NR_ELEMENTE_PLEB - 1;
                else
                    optionSelectedPleb = optionSelectedPleb % NR_ELEMENTE_PLEB;
                break;

            case 's': case 'S': case 80: // DOWN
                optionSelectedPleb++;
                optionSelectedPleb = optionSelectedPleb % NR_ELEMENTE_PLEB;
                break;
                
            case 13: // ENTER
                fleg = 0; //Cand apasam enter iesim din aceasta bucla
                break;
        } 
    }
    
    return optionSelectedPleb; // returnam valoarea selectata
}