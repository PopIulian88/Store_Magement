#define NR_ELEMENTE_EDIT 4 //Setarile initiale pentru EDIT

char EditTitle[] = "EDIT";
int optionSelectedEdit = 0;
char menuEdit[NR_ELEMENTE_EDIT][100] = {
    "Ajustare stoc",
    "Schimba pret",
    "Sterge",
    "BACK",
};

void printEditInterface()
{
    system("CLS");

    afisiazaInterfata(menuEdit, NR_ELEMENTE_EDIT, optionSelectedEdit, EditTitle);
}

int selectEditInterface()
{
    int fleg = 1;
    while(fleg) //Cat timp e activa putem naviga in meniu
    {
        printEditInterface(); // afisam interfata curenta
        
        int key_code = _getch(); // primim input de la tastatura

        switch(key_code)
        {   
            case 'w': case 'W': case 72: // UP
                optionSelectedEdit--;
                if(optionSelectedEdit < 0)
                    optionSelectedEdit = NR_ELEMENTE_EDIT - 1;
                else
                    optionSelectedEdit = optionSelectedEdit % NR_ELEMENTE_EDIT;
                break;

            case 's': case 'S': case 80: // DOWN
                optionSelectedEdit++;
                optionSelectedEdit = optionSelectedEdit % NR_ELEMENTE_EDIT;
                break;
                
            case 13: // ENTER
                fleg = 0; //Cand apasam enter iesim din aceasta bucla
                break;
        } 
    }
    
    return optionSelectedEdit; // returnam valoarea selectata
}