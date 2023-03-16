#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#include "./Interfaces/Pleb/FunctiPleb/EditareMenuCos/FunctiCos/PretFinal.c"


int main()
{  
    double pret = pretFinal("Storage/Cos.txt");

    printf("%lf", pret);
    return 0;
}