#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./Interfaces/Main/GetInformation.c"


int main()
{  
    char oldSir[100000];
    getPositionInfo("Storage/Produse.txt", 4, oldSir);

    char *oldName = strtok(oldSir, " ");
    char *oldCantitate = strtok(NULL, " ");
    char *oldPret = strtok(NULL, "\n");
    printf("Vechiul este: %s, %s, %s", oldName, oldCantitate, oldPret);
    printf("Vechiul este: %s, %s, %s", oldName, oldCantitate, oldPret);
    return 0;
}