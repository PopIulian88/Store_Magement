#include "./EditareMarfa/EditareMenu.c"
#include "./EditareMarfa/SelectEditare.c"

void marfaInterfaceAdmin()
{
    int produsActual = 0;
    int fleg = 1;
    while(fleg) //Cat timp e activa putem naviga
    {
        system("CLS");
        int NrProduse = afisFile("Storage/Produse.txt", produsActual); // afisam interfata curenta
        
        int key_code = _getch(); // primim input de la tastatura

        switch(key_code)
        {   
            case 'w': case 'W': case 72: // UP
                produsActual--;
                if(produsActual < 0)
                    produsActual = NrProduse - 1;
                else
                    produsActual = produsActual % NrProduse;
                break;

            case 's': case 'S': case 80: // DOWN
                produsActual++;
                produsActual = produsActual % NrProduse;
                break;
                
            case 13: // ENTER
                fleg = 0; //Cand apasam enter iesim din aceasta bucla
                break;
        } 
    }

    if(produsActual > 0)
        editInterface(produsActual);

}