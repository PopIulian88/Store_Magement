#define NR_ELEMENTE_COS 3 //Setarile initiale pentru COS

char CosTitle[] = "Cos";
int optionSelectedCos = 0;
char menuCos[NR_ELEMENTE_COS][100]={
    "Arata Cos",
    "Confirma comanda",
    "BACK",
};

void printCosInterface()
{
    system("CLS");

    afisiazaInterfata(menuCos, NR_ELEMENTE_COS, optionSelectedCos, CosTitle);
}

int selectCosInterface()
{
    int fleg = 1;
    while(fleg) //Cat timp e activa putem naviga in meniu
    {
        printCosInterface(); // afisam interfata curenta
        
        int key_code = _getch(); // primim input de la tastatura

        switch(key_code)
        {   
            case 'w': case 'W': case 72: // UP
                optionSelectedCos--;
                if(optionSelectedCos < 0)
                    optionSelectedCos = NR_ELEMENTE_COS - 1;
                else
                    optionSelectedCos = optionSelectedCos % NR_ELEMENTE_COS;
                break;

            case 's': case 'S': case 80: // DOWN
                optionSelectedCos++;
                optionSelectedCos = optionSelectedCos % NR_ELEMENTE_COS;
                break;
                
            case 13: // ENTER
                fleg = 0; //Cand apasam enter iesim din aceasta bucla
                break;
        } 
    }
    
    return optionSelectedCos; // returnam valoarea selectata
}