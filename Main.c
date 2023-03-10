#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "SelectUserInterface.c"

int main()
{
    printf("%d", selectUserInterface());



    //Conditia sa nu se termine consola
    int n;
    scanf("%d",  &n);
    return 0;
}