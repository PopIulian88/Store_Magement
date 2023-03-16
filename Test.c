#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#include "./Interfaces/Pleb/FunctiPleb/EditareMenuCos/FunctiCos/TrimiteComanda.c"
#include "./Interfaces/Pleb/FunctiPleb/EditareMenuCos/FunctiCos/RecreazaFisier.c"


int main()
{  
    trimiteComanda("Storage/Cos.txt", "Storage/Comenzi.txt", "15.69");
    recreazaFisier("Storage/Cos.txt");
    return 0;
}