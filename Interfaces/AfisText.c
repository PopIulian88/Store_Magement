#include <stdio.h>

int afisFile(char fileName[], int curentPosition)
{
    int count = 0;
    FILE *pointer;
    char data[100];
    pointer = fopen(fileName, "r");

    if(pointer == NULL)
    {
        printf("Fail to open file");
    }else{
        setColorTo(4); // GALBEN
        printf("\n     PRODUSE\n\n");
        setColorTo(0); // DEFAULT

        while(fgets(data, 100, pointer))
        {
            if(curentPosition == count)
            {
                setColorTo(5); // ROZ
                printf(" >> ");
                setColorTo(0); // DEFAULT
            }
            if(count == 0) // Cazul BACK
                setColorTo(1); // ROSU
            else
                setColorTo(6); // CYAN
            printf("  %s", data);
            setColorTo(3); // ALBASTRU
            printf("_______________________\n");
            setColorTo(0); // DEFAULT
            count++;
        }
        fclose(pointer);
    }
    return count;
}