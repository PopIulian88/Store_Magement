
void afisiazaInterfata(char posibilitati[][100], int nrPosibilitati, int posibilitateSelectata, char title[])
{
    setColorTo(4); //GALBEN

    printf("~~~~~~~~~~~~~~~~~\n");
    printf("  $$ ");
    printf(title);
    printf(" $$  \n");
    printf("~~~~~~~~~~~~~~~~~\n\n");

    setColorTo(3); //CYAN
    printf("Select:\n");
    setColorTo(6); //CYAN

    for(int i = 0; i < nrPosibilitati; i++) //Afisam posibilitatile pe ecran
    {
        printf("______________\n");
        if(i == posibilitateSelectata)   //Daca posibilitatea pe care o afisam e cea selectata
        {                       //punem un caracter special in fata ei
            setColorTo(2); // VERDE
            printf("  >>");
            setColorTo(5); // ROZ
            printf(" %s\n", posibilitati[i]);
            setColorTo(6); // CYAN
        }else{
            setColorTo(3); //ALBASTRU
            printf("   %s\n", posibilitati[i]);
            setColorTo(6); // CYAN
        }
    }
    printf("______________\n");

    setColorTo(3); // ALBASTRU
    printf("\nFoloseste: W, S sau SAGETILE pentru a naviga.\n");
    printf("Apasa ENTER pentru a confirma\n");
    setColorTo(0); // DEFAULT
}